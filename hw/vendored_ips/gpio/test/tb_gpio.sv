//-----------------------------------------------------------------------------
// Title         : GPIO Testbench
//-----------------------------------------------------------------------------
// File          : tb_gpio.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 07.05.2021
//-----------------------------------------------------------------------------
// Description :
// Test the functionality of the GPIO Peripheral
//-----------------------------------------------------------------------------
// Copyright (C) 2013-2021 ETH Zurich, University of Bologna
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//-----------------------------------------------------------------------------


`define SV_RAND_CHECK(r) \
do begin \
  if (!(r)) begin \
    $display("%s:%0d: Randomization failed \"%s\"", `__FILE__, `__LINE__, `"r`"); \
    $stop;\
  end\
end while (0)

// Unfortunately, the reggen tool has very inconsistent naming rules for multi
// regs. The generated parameters use a suffixed index for multireg iff there
// are at least two registers. If we generate less then 32 GPIOs the multiregs
// will only contain a single reg instance. In that case, the current version of
// reggen will ommit the suffix which causes issues in this TB we thus use this
// preproc macro workaround to alias to the right regs in this case. The
// 'reconfigure' target in the makefile will take care of enabling/disabling the
// workaround as needed. Thus DO NOT TOUCH THE FOLLOWING TWO LINES MANUALLY.

//`define ENABLE_LESS_THAN_16_GPIOS_REG_PKG_WORKAROUND
`define ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND

module tb_gpio;
  localparam ClkPeriod        = 10ns;
  localparam RstCycles        = 6;
  localparam ApplTime         = 1ns;
  localparam TestTime         = 8ns;
  localparam DataWidth        = 32;
  localparam AddrWidth = 32;
  parameter NumRepetitions = 20;
  localparam SimTimeoutCycles = 5000*NumRepetitions; // Timeout the simulation after 5000 cycles
  localparam NrGPIOs = gpio_reg_pkg::GPIOCount;

  // Testbench control signals
  logic clk;
  logic rst_n;
  logic end_of_sim;

  // Generate clock and reset
  clk_rst_gen #(
    .ClkPeriod    ( ClkPeriod ),
    .RstClkCycles ( RstCycles )
  ) i_clk_rst_gen (
    .clk_o ( clk   ),
    .rst_no( rst_n )
  );

  // Test Timeout Module
  sim_timeout #(
    .Cycles(SimTimeoutCycles)
  ) i_sim_timeout(
    .clk_i  ( clk   ),
    .rst_ni ( rst_n )
  );

  // End of test procedure
  initial begin : proc_end_of_test
    wait (end_of_sim);
    repeat (100) @(posedge clk);
    $info("Simulation ended.");
    $stop();
  end

  // Interface Signals
  REG_BUS #(
    .ADDR_WIDTH (AddrWidth),
    .DATA_WIDTH (DataWidth)) s_reg_bus (.clk_i(clk));

  logic [NrGPIOs-1:0]   gpio_in;
  logic [NrGPIOs-1:0]   gpio_in_sync;
  logic [NrGPIOs-1:0]   gpio_out;
  logic [NrGPIOs-1:0]   gpio_tx_en;
  logic                 global_interrupt;


  // Instantiate DUT
  gpio_intf #(
    .ADDR_WIDTH ( AddrWidth ),
    .DATA_WIDTH ( DataWidth )
  ) i_dut (
    .reg_bus                ( s_reg_bus.in              ),
    // Outputs
    .gpio_out               ( gpio_out[NrGPIOs-1:0]     ),
    .gpio_tx_en_o           ( gpio_tx_en[NrGPIOs-1:0]   ),
    .gpio_in_sync_o         ( gpio_in_sync[NrGPIOs-1:0] ),
    .global_interrupt_o     ( global_interrupt          ),
    .pin_level_interrupts_o (                           ),
    // Inputs
    .clk_i                  ( clk                       ),
    .rst_ni                 ( rst_n                     ),
    .gpio_in                ( gpio_in[NrGPIOs-1:0]      )
  );

  // Connect test programm
  test #(
    .NrGPIOs        (  NrGPIOs       ),
    .DataWidth      (  DataWidth     ),
    .AddrWidth      (  AddrWidth     ),
    .ApplTime       (  ApplTime      ),
    .TestTime       (  TestTime      ),
    .NumRepetitions ( NumRepetitions )
   ) i_test (
    .end_of_sim_o       ( end_of_sim       ),
    .clk_i              ( clk              ),
    .rst_ni             ( rst_n            ),
    .gpio_in_o          ( gpio_in          ),
    .gpio_out_i         ( gpio_out         ),
    .gpio_tx_en_i       ( gpio_tx_en       ),
    .gpio_in_sync_i     ( gpio_in_sync     ),
    .global_interrupt_i ( global_interrupt ),
    .reg_bus            ( s_reg_bus        )
  );
endmodule


program automatic test #(
  parameter int unsigned NrGPIOs   = 64,
  localparam int unsigned NrGPIOs_rounded = ((NrGPIOs+32-1)/32)*32,
  parameter DataWidth = 32,
  parameter AddrWidth = 32,
  parameter ApplTime,
  parameter TestTime,
  parameter int unsigned NumRepetitions
) (
  output logic               end_of_sim_o,
  input logic                clk_i,
  input logic                rst_ni,
  output logic [NrGPIOs-1:0] gpio_in_o,
  input logic [NrGPIOs-1:0]  gpio_out_i,
  input logic [NrGPIOs-1:0]  gpio_tx_en_i, // 0 -> input, 1 -> output
  input logic [NrGPIOs-1:0]  gpio_in_sync_i, // sampled and synchronized GPIO
  // input.
  input logic                global_interrupt_i,
  REG_BUS.out                reg_bus
);
  default clocking cb @(posedge clk_i);
  endclocking

  import reg_test::reg_driver;
  import gpio_reg_pkg::*;

  localparam type gpio_reg_driver_t = reg_driver #(.AW(AddrWidth), .DW(DataWidth), .TA(ApplTime), .TT(TestTime));
  gpio_reg_driver_t gpio_reg_driver;
  // reg_driver #(.AW(AddrWidth), .DW(DataWidth), .TA(ApplTime), .TT(TestTime)) gpio_reg_driver;

  // Debug Signals
  logic [NrGPIOs_rounded-1:0][1:0] gpio_modes;
  logic [NrGPIOs_rounded-1:0]      gpio_values;
  int                              error_count = 0;

  task automatic test_toggle_set_clear(gpio_reg_driver_t gpio_reg_driver, int unsigned NumRepetitions);
    logic [DataWidth-1:0] data = 0;
    logic [AddrWidth-1:0] addr;
    logic [DataWidth/8-1:0] strb  = '1;
    logic                   error = 0;

    $info("Verifying toggle, set and clear functionality of the outputs");
    for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth*2; i++) begin : cfg_gpio_modes
`ifdef ENABLE_LESS_THAN_16_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_MODE_OFFSET + i*4;
`else
      addr = GPIO_GPIO_MODE_0_OFFSET + i*4;
`endif
      data = {16{2'b01}}; // Put all gpios in push-pull mode
      gpio_reg_driver.send_write(addr, data, strb, error);
      assert(error == 0) else begin
        $error("Interface write error while writing GPIO mode.");
        error_count++;
      end
    end

    // Set random gpio out values
    `SV_RAND_CHECK(randomize(gpio_values));
    for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth; i++) begin
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_OUT_OFFSET + i*4;
`else
      addr = GPIO_GPIO_OUT_0_OFFSET + i*4;
`endif
      data = gpio_values[i*DataWidth+:DataWidth];
      gpio_reg_driver.send_write(addr, data, strb, error);
      assert(error == 0) else begin
        $error("Interface write error while writing GPIO out values.");
        error_count++;
      end
    end

    assert (gpio_tx_en_i == '1) else begin
      $error("GPIO TX driver not enabled although all GPIOs should be configured as outputs in push-pull mode.");
      error_count++;
    end
    assert (gpio_out_i == gpio_values[NrGPIOs-1:0]) else begin
      $error("Missmatch in GPIO outputs. Expected output pattern %0b but was %0b.", gpio_values, gpio_out_i);
      error_count++;
    end

    // Sequentially toggle, set and clear all GPIOs and verify only the ones set are modified
    for (int i= 0; i < NrGPIOs; i++) begin
      data = 1<<(i%32);
      // Toggle the GPIO
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_TOGGLE_OFFSET + i/32*4;
`else
      addr = GPIO_GPIO_TOGGLE_0_OFFSET + i/32*4;
`endif
      gpio_reg_driver.send_write(addr, data, strb, error);
      for (int j = 0; j < NrGPIOs; j++) begin
        if (i == j) begin
          assert(gpio_out_i[j] == ~gpio_values[j]) else begin
            $error("GPIO %0d has not toggled.", j);
            error_count++;
          end
        end else begin
          assert(gpio_out_i[j] == gpio_values[j]) else begin
            $error("GPIO %0d was %0b instead of %0b although it should not have beend altered during modification of GPIO %0d.", j, gpio_out_i[j], gpio_values[j], i);
            error_count++;
          end
        end
      end


      //Set the GPIO
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_SET_OFFSET + i/32*4;
`else
      addr = GPIO_GPIO_SET_0_OFFSET + i/32*4;
`endif
      gpio_reg_driver.send_write(addr, data, strb, error);
      for (int j = 0; j < NrGPIOs; j++) begin
        if (i == j) begin
          assert(gpio_out_i[j] == 1'b1) else begin
            $error("GPIO %0d is not set.", j);
            error_count++;
          end
        end else begin
          assert(gpio_out_i[j] == gpio_values[j]) else begin
            $error("GPIO %0d was %0b instead of %0b although it should not have beend altered during modification of GPIO %0d.", j, gpio_out_i[j], gpio_values[j], i);
            error_count++;
          end
        end
      end

      // Now clear the GPIO
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_CLEAR_OFFSET + i/32*4;
`else
      addr = GPIO_GPIO_CLEAR_0_OFFSET + i/32*4;
`endif
      gpio_reg_driver.send_write(addr, data, strb, error);
      for (int j = 0; j < NrGPIOs; j++) begin
        if (i == j) begin
          assert(gpio_out_i[j] == 1'b0) else begin
            $error("GPIO %0d is not cleared.", j);
            error_count++;
          end
        end else begin
          assert(gpio_out_i[j] == gpio_values[j]) else begin
            $error("GPIO %0d was %0b instead of %0b although it should not have beend altered during modification of GPIO %0d.", j, gpio_out_i[j], gpio_values[j], i);
            error_count++;
          end
        end
      end
      gpio_values[i] = 1'b0;
    end

  endtask

  task automatic test_inputs(gpio_reg_driver_t reg_driver, int unsigned NumRepetitions);
    logic [DataWidth-1:0] data = 0;
    logic [AddrWidth-1:0] addr;
    logic [DataWidth/8-1:0] strb                               = '1;
    logic                   error                              = 0;
    logic [NrGPIOs_rounded-1:0] enabled_gpios;
    logic [NrGPIOs-1:0]         gpio_values;
    logic [NrGPIOs-1:0]         data_queue[$];

    gpio_in_o = '0;

    $info("Test GPIOs in input mode with random data.");
    for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth*2; i++) begin : cfg_gpio_modes
`ifdef ENABLE_LESS_THAN_16_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_MODE_OFFSET + i*4;
`else
      addr = GPIO_GPIO_MODE_0_OFFSET + i*4;
`endif
      data = {16{2'b00}}; // Put all gpios in input mode
      gpio_reg_driver.send_write(addr, data, strb, error);
      assert(error == 0) else begin
        $error("Interface write error while writing GPIO mode.");
        error_count++;
      end
    end
    $info("Enabling input sampling on random GPIOs");
    `SV_RAND_CHECK(randomize(enabled_gpios));
    for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth; i++) begin : cfg_gpio_enable
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_EN_OFFSET + i*4;
`else
      addr = GPIO_GPIO_EN_0_OFFSET + i*4;
`endif
      data = enabled_gpios[i*32+:32];
      gpio_reg_driver.send_write(addr, data, strb, error);
      assert(error == 0) else begin
        $error("Interface write error while writing GPIO mode.");
        error_count++;
      end
    end

    $info("Apply and verify random inputs");
    for (int i = 0; i < NumRepetitions; i++) begin
      `SV_RAND_CHECK(randomize(gpio_in_o));
      ##3; //Wait three cycles
      #TestTime;
      for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth; i++) begin
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
        addr = GPIO_GPIO_IN_OFFSET + i*4;
`else
        addr = GPIO_GPIO_IN_0_OFFSET + i*4;
`endif
        gpio_reg_driver.send_read(addr, data, error);
        assert(error == 0) else begin
          $error("Interface write error while writing GPIO mode.");
          error_count++;
        end
        for (int j = i*32; j < (i+1)*32; j++) begin
          if (j < NrGPIOs && enabled_gpios[j]) begin
            assert(gpio_in_o[j] == data[j%32]) else begin
              $error("Got wrong gpio value for GPIO%0d. Was %0b instead of %0b", j, gpio_in_o[j], data[j%32]);
              error_count++;
            end
          end
        end
      end
    end

    $info("Test fast data sampling");
    for (int k = 0; k < NumRepetitions; k++) begin
      `SV_RAND_CHECK(randomize(gpio_values));
      data_queue.push_back(gpio_values);
    end
    fork
      begin
        $info("Aplying inputs...");
        foreach(data_queue[i]) begin
          #ApplTime;
          gpio_in_o = data_queue[i];
          ##1;
        end
      end
      begin
        ##3; // Delay sampling by 3 cycles for
        $info("Start reading sampled values on GPIO0...");
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
        addr = GPIO_GPIO_IN_OFFSET;
`else
        addr = GPIO_GPIO_IN_0_OFFSET;
`endif
        foreach(data_queue[i]) begin
          gpio_reg_driver.send_read(addr, data, error);
          for (int j = 0; j < NrGPIOs && j < 32; j++) begin
            if (enabled_gpios[j])
              assert(data[j] == data_queue[i][j]) else begin
                $error("On GPIO %0d. Was %0b instead of %0b.", j, data[j], data_queue[i][j]);
                error_count++;
              end
          end
        end
      end
    join
  endtask

  typedef enum logic[2:0] {None, Rising, Falling, EitherEdge, Low, High} interrupt_mode_e;
  interrupt_mode_e [NrGPIOs_rounded-1:0] interrupt_modes;

  task automatic test_interrupts(gpio_reg_driver_t gpio_reg_driver, int unsigned NumRepetitions);
    logic [DataWidth-1:0] data = 0;
    logic [AddrWidth-1:0] addr;
    logic [DataWidth/8-1:0] strb  = '1;
    logic                   error = 0;
    logic [NrGPIOs_rounded-1:0] enabled_gpios;
    logic [NrGPIOs-1:0]         gpio_values;
    logic [NrGPIOs-1:0]         toggle_mask;
    logic [NrGPIOs_rounded-1:0] pending_intrpt, pending_rise_intrpt, pending_fall_intrpt, pending_low_intrpt, pending_high_intrpt;
    logic                       clear_interrupt;


    int unsigned                delay;

    $info("Test GPIO interrupts.");
    for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth*2; i++) begin : cfg_gpio_modes
`ifdef ENABLE_LESS_THAN_16_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_MODE_OFFSET + i*4;
`else
      addr = GPIO_GPIO_MODE_0_OFFSET + i*4;
`endif
      data = {16{2'b00}}; // Put all gpios in input mode
      gpio_reg_driver.send_write(addr, data, strb, error);
      assert(error == 0) else begin
        $error("Interface write error while writing GPIO mode.");
        error_count++;
      end
    end
    $info("Enabling input sampling on all GPIOs");
    `SV_RAND_CHECK(randomize(enabled_gpios));
    for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth; i++) begin : cfg_gpio_enable
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_EN_OFFSET + i*4;
`else
      addr = GPIO_GPIO_EN_0_OFFSET + i*4;
`endif
      data = '1;
      gpio_reg_driver.send_write(addr, data, strb, error);
      assert(error == 0) else begin
        $error("Interface write error while writing GPIO mode.");
        error_count++;
      end
    end

    $info("Put GPIOs into random interrupt modes...");
    // We randomize the modes such that there are not to many enabled
    // interrupts. Otherwise the global_interrupt line will probably stay high all the
    // time due to the level sensitive interrupts.
    std::randomize(interrupt_modes) with {
       foreach (interrupt_modes[i]) {
         interrupt_modes[i] dist {
                                  None        := 20,
                                  Rising      := 2,
                                  Falling     := 2,
                                  EitherEdge  := 1,
                                  Low         := 1,
                                  High        := 1
                                  };
       }
    };
    // Before enabling level low  sensitive interrupts, put gpio inputs in a state
    // that doesn't immediately trigger them.
    foreach(gpio_in_o[i]) begin
      gpio_in_o[i] = interrupt_modes[i] == Low;
    end
    ##3;

    for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth; i++) begin : cfg_gpio_enable
      // Enable rising edge interrupts
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_INTRPT_RISE_EN_OFFSET + i*4;
`else
      addr = GPIO_INTRPT_RISE_EN_0_OFFSET + i*4;
`endif
      foreach(data[j]) begin
        data[j] = interrupt_modes[i*32+j] == Rising || interrupt_modes[i*32+j] == EitherEdge;
      end
      gpio_reg_driver.send_write(addr, data, strb, error);
      // Enable falling edge interrupts
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_INTRPT_FALL_EN_OFFSET + i*4;
`else
      addr = GPIO_INTRPT_FALL_EN_0_OFFSET + i*4;
`endif
      foreach(data[j]) begin
        data[j] = interrupt_modes[i*32+j] == Falling || interrupt_modes[i*32+j] == EitherEdge;
      end
      gpio_reg_driver.send_write(addr, data, strb, error);

      // Enable low level-sensitive interrupts
      foreach(data[j]) begin
        data[j] = interrupt_modes[i*32+j] == Low;
      end
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_INTRPT_LVL_LOW_EN_OFFSET + i*4;
`else
      addr = GPIO_INTRPT_LVL_LOW_EN_0_OFFSET + i*4;
`endif
      gpio_reg_driver.send_write(addr, data, strb, error);
      // Enable high level-sensitive interrupts
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_INTRPT_LVL_HIGH_EN_OFFSET + i*4;
`else
      addr = GPIO_INTRPT_LVL_HIGH_EN_0_OFFSET + i*4;
`endif
      foreach(data[j]) begin
        data[j] = interrupt_modes[i*32+j] == High;
      end
      gpio_reg_driver.send_write(addr, data, strb, error);
      assert(error == 0) else begin
        $error("Interface write error while writing GPIO mode.");
        error_count++;
      end
    end
    ##10;

    $info("Inserting random interrupts...");
    pending_rise_intrpt = '0;
    pending_fall_intrpt = '0;
    pending_high_intrpt = '0;
    pending_low_intrpt = '0;
    for (int i = 0; i < NumRepetitions; i++) begin
      ## 1;
      // Toggle some random GPIOs
      `SV_RAND_CHECK(randomize(toggle_mask) with {
        $countones(toggle_mask) < 3;
      });
      $info("Toggling GPIOs...");
      gpio_in_o ^= toggle_mask;
      #ApplTime;
      //Check which interrups this change should trigger...
      foreach(toggle_mask[j]) begin
        case (interrupt_modes[j])
          Falling: begin
            if (gpio_in_o[j] == 1'b0 && toggle_mask[j])
              pending_fall_intrpt[j] = 1'b1;
          end

          Rising: begin
            if (gpio_in_o[j] == 1'b1 && toggle_mask[j])
              pending_rise_intrpt[j] = 1'b1;
          end

          EitherEdge: begin
            if (toggle_mask[j]) begin
              if (gpio_in_o[j] == 1'b1)
                pending_rise_intrpt[j] = 1'b1;
              else
                pending_fall_intrpt[j] = 1'b1;
            end
          end

          Low: begin
            if (gpio_in_o[j] == 1'b0)
              pending_low_intrpt[j] = 1'b1;
          end

          High: begin
            if (gpio_in_o[j] == 1'b1)
              pending_high_intrpt[j] = 1'b1;
          end
        endcase
      end
      $info("Checking global_interrupt status regs...");
      pending_intrpt = pending_high_intrpt | pending_low_intrpt | pending_rise_intrpt | pending_fall_intrpt;
      if (pending_intrpt) begin
        if (pending_rise_intrpt | pending_fall_intrpt) begin
          // Wait 2 cycles (rising and falling edge interrupts arrive 1 cycle
          // earlier than level sensitive interrupts)
          ##2;
        end else begin
          ##3;
        end

        #TestTime;
        assert(global_interrupt_i == 1'b1) else begin
          $error("Interrupt was not asserted.");
          error_count++;
        end
        ##2; // Wait another 2 cycles for the global_interrupt status register to be
             // updated
        //Read global_interrupt status registers
        for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth; i++) begin
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
          addr = GPIO_INTRPT_STATUS_OFFSET + i*4;
`else
          addr = GPIO_INTRPT_STATUS_0_OFFSET + i*4;
`endif
          gpio_reg_driver.send_read(addr, data, error);
          assert(data == pending_intrpt[i*32+:32]) else begin
            $error("Interrupt status missmatch. Was %0x instead of %0x", data, pending_intrpt[i*32+:32]);
            error_count++;
          end
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
          addr = GPIO_INTRPT_RISE_STATUS_OFFSET + i*4;
`else
          addr = GPIO_INTRPT_RISE_STATUS_0_OFFSET + i*4;
`endif
          gpio_reg_driver.send_read(addr, data, error);
          assert(data == pending_rise_intrpt[i*32+:32]) else begin
            $error("Interrupt rise status missmatch. Was %0x instead of %0x", data, pending_rise_intrpt[i*32+:32]);
            error_count++;
          end
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
          addr = GPIO_INTRPT_FALL_STATUS_OFFSET + i*4;
`else
          addr = GPIO_INTRPT_FALL_STATUS_0_OFFSET + i*4;
`endif
          gpio_reg_driver.send_read(addr, data, error);
          assert(data == pending_fall_intrpt[i*32+:32]) else begin
            $error("Interrupt fall status missmatch. Was %0x instead of %0x", data, pending_fall_intrpt[i*32+:32]);
            error_count++;
          end
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
          addr = GPIO_INTRPT_LVL_LOW_STATUS_OFFSET + i*4;
`else
          addr = GPIO_INTRPT_LVL_LOW_STATUS_0_OFFSET + i*4;
`endif
          gpio_reg_driver.send_read(addr, data, error);
          assert(data == pending_low_intrpt[i*32+:32]) else begin
            $error("Interrupt low status missmatch. Was %0x instead of %0x", data, pending_low_intrpt[i*32+:32]);
            error_count++;
          end
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
          addr = GPIO_INTRPT_LVL_HIGH_STATUS_OFFSET + i*4;
`else
          addr = GPIO_INTRPT_LVL_HIGH_STATUS_0_OFFSET + i*4;
`endif
          gpio_reg_driver.send_read(addr, data, error);
          assert(data == pending_high_intrpt[i*32+:32]) else begin
            $error("Interrupt high status missmatch. Was %0x instead of %0x", data, pending_high_intrpt[i*32+:32]);
            error_count++;
          end
        end

        //Now clear some of the pending interrupts
        $info("Start global_interrupt clearing...");
        foreach(pending_intrpt[j]) begin
          if (pending_intrpt[j]) begin
            randcase
              2: begin
                $info("Clearing all interrupts on GPIO %0d.", j);
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
                addr = GPIO_INTRPT_STATUS_OFFSET + j/32*4;
`else
                addr = GPIO_INTRPT_STATUS_0_OFFSET + j/32*4;
`endif
                data = 1<<j%32;
                gpio_reg_driver.send_write(addr, data, strb, error);
                pending_rise_intrpt[j] = 1'b0;
                pending_fall_intrpt[j] = 1'b0;
                pending_low_intrpt[j]  = 1'b0;
                pending_high_intrpt[j] = 1'b0;
              end

              1: begin
                //Don't clear the global_interrupt
              end
            endcase
          end
        end

        foreach(pending_rise_intrpt[j]) begin
          if (pending_rise_intrpt[j]) begin
            randcase
              2: begin
                $info("Clearing rise global_interrupt on GPIO %0d.", j);
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
                addr = GPIO_INTRPT_RISE_STATUS_OFFSET + j/32*4;
`else
                addr = GPIO_INTRPT_RISE_STATUS_0_OFFSET + j/32*4;
`endif
                data = 1<<j%32;
                gpio_reg_driver.send_write(addr, data, strb, error);
                pending_rise_intrpt[j] = 1'b0;
              end

              1: begin
                //Don't clear the global_interrupt
              end
            endcase
          end
        end

        foreach(pending_fall_intrpt[j]) begin
          if (pending_fall_intrpt[j]) begin
            randcase
              2: begin
                $info("Clearing fall global_interrupt on GPIO %0d.", j);
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
                addr = GPIO_INTRPT_FALL_STATUS_OFFSET + j/32*4;
`else
                addr = GPIO_INTRPT_FALL_STATUS_0_OFFSET + j/32*4;
`endif
                data = 1<<j%32;
                gpio_reg_driver.send_write(addr, data, strb, error);
                pending_fall_intrpt[j] = 1'b0;
              end

              1: begin
                //Don't clear the global_interrupt
              end
            endcase
          end
        end

        foreach(pending_low_intrpt[j]) begin
          if (pending_low_intrpt[j]) begin
            randcase
              4: begin
                $info("Clearing low global_interrupt on GPIO %0d and asserting the gpio input.", j);
                gpio_in_o[j] = 1'b1;
                ##3;
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
                addr = GPIO_INTRPT_LVL_LOW_STATUS_OFFSET + j/32*4;
`else
                addr = GPIO_INTRPT_LVL_LOW_STATUS_0_OFFSET + j/32*4;
`endif
                data = 1<<j%32;
                gpio_reg_driver.send_write(addr, data, strb, error);
                pending_low_intrpt[j] = 1'b0;
              end

              2: begin
                $info("Clearing low global_interrupt on GPIO %0d.", j);
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
                addr = GPIO_INTRPT_LVL_LOW_STATUS_OFFSET + j/32*4;
`else
                addr = GPIO_INTRPT_LVL_LOW_STATUS_0_OFFSET + j/32*4;
`endif
                data = 1<<j%32;
                gpio_reg_driver.send_write(addr, data, strb, error);
                pending_low_intrpt[j] = 1'b0;
              end

              1: begin
                //Don't clear the global_interrupt
              end
            endcase
          end
        end

        foreach(pending_high_intrpt[j]) begin
          if (pending_high_intrpt[j]) begin
            randcase
              4: begin
                $info("Clearing high global_interrupt on GPIO %0d and clearing the gpio input.", j);
                gpio_in_o[j] = 1'b0;
                ##3;
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
                addr = GPIO_INTRPT_LVL_HIGH_STATUS_OFFSET + j/32*4;
`else
                addr = GPIO_INTRPT_LVL_HIGH_STATUS_0_OFFSET + j/32*4;
`endif
                data = 1<<j%32;
                gpio_reg_driver.send_write(addr, data, strb, error);
                pending_high_intrpt[j] = 1'b0;
              end

              2: begin
                $info("Clearing high global_interrupt on GPIO %0d.", j);
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
                addr = GPIO_INTRPT_LVL_HIGH_STATUS_OFFSET + j/32*4;
`else
                addr = GPIO_INTRPT_LVL_HIGH_STATUS_0_OFFSET + j/32*4;
`endif
                data = 1<<j%32;
                gpio_reg_driver.send_write(addr, data, strb, error);
                pending_high_intrpt[j] = 1'b0;
              end

              1: begin
                //Don't clear the global_interrupt
              end
            endcase
          end
        end
        // Re-evaluate level sensitive interrupts
        foreach(interrupt_modes[j]) begin
          case (interrupt_modes[j])
            Low: begin
              if (gpio_in_o[j] == 1'b0)
                pending_low_intrpt[j] = 1'b1;
            end

            High: begin
              if (gpio_in_o[j] == 1'b1)
                pending_high_intrpt[j] = 1'b1;
            end
          endcase
        end

      end else begin
        assert(global_interrupt_i == 1'b0) else begin
          $error("Detected stray global_interrupt!");
          error_count++;
        end
      end
      $info("Clearing all interrupts...");
      foreach(gpio_in_o[i]) begin
        gpio_in_o[i] = interrupt_modes[i] == Low;
      end
      ##3;
      for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth; i++) begin : cfg_gpio_modes
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
        addr = GPIO_INTRPT_STATUS_OFFSET + i*4;
`else
        addr = GPIO_INTRPT_STATUS_0_OFFSET + i*4;
`endif
        data = '1;
        gpio_reg_driver.send_write(addr, data, strb, error);
      end

      ##3;
      assert(global_interrupt_i == 1'b0) else begin
        $error("Failed to clear all interrupts.");
        error_count++;
      end
      pending_rise_intrpt = '0;
      pending_fall_intrpt = '0;
      pending_high_intrpt = '0;
      pending_low_intrpt  = '0;
    end


  endtask

  task automatic test_outputs(gpio_reg_driver_t gpio_reg_driver, int unsigned NumRepetitions);
    logic [DataWidth-1:0] data = 0;
    logic [AddrWidth-1:0] addr;
    logic [DataWidth/8-1:0] strb = '1;
    logic                   error = 0;
    $info("Configuring gpios into random modes.");
    `SV_RAND_CHECK(randomize(gpio_modes));
    for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth*2; i++) begin : cfg_gpio_modes
`ifdef ENABLE_LESS_THAN_16_GPIOS_REG_PKG_WORKAROUND
      addr = GPIO_GPIO_MODE_OFFSET + i*4;
`else
      addr = GPIO_GPIO_MODE_0_OFFSET + i*4;
`endif
      data = gpio_modes[i*(DataWidth/2)+:DataWidth/2];
      gpio_reg_driver.send_write(addr, data, strb, error);
      assert(error == 0) else begin
        $error("Interface write error while writing GPIO mode.");
        error_count++;
      end
    end

    $info("Verifying GPIO outputs with random activity.");
    // Now drive them and check the behavior of the tx_en and the gpio_out ports
    for (int repetition_idx = 0; repetition_idx < NumRepetitions; repetition_idx++) begin : for_repetition
      // Set random gpio out values
      `SV_RAND_CHECK(randomize(gpio_values));
      for (int i = 0; i < (NrGPIOs+DataWidth-1)/DataWidth; i++) begin
`ifdef ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND
        addr = GPIO_GPIO_OUT_OFFSET + i*4;
`else
        addr = GPIO_GPIO_OUT_0_OFFSET + i*4;
`endif
        data = gpio_values[i*DataWidth+:DataWidth];
        gpio_reg_driver.send_write(addr, data, strb, error);
        assert(error == 0) else begin
          $error("Interface write error while writing GPIO out values.");
          error_count++;
        end
      end

      // Check if gpio_out and gpio_tx_en is correct for every gpio
      for (int gpio_idx = 0; gpio_idx < NrGPIOs; gpio_idx++) begin : for_gpio
        unique case (gpio_modes[gpio_idx])
          2'b00: begin // Input Only
            assert(gpio_tx_en_i[gpio_idx] == 1'b0) else begin
              $error("GPIO %d TX  is enabled even though GPIO is supposed to be in Input mode.", gpio_idx);
              error_count++;
            end
          end

          2'b01: begin // Push/Pull mode
            assert(gpio_tx_en_i[gpio_idx] == 1'b1) else begin
              $error("GPIO %d TX is not enabled even though GPIO is suppposed to be in Push/Pull mode.", gpio_idx);
              error_count++;
            end
            assert(gpio_out_i[gpio_idx] == gpio_values[gpio_idx]) else begin
              $error("Got wrong output value on GPIO %d. Was suposed to be %b but was %b.", gpio_idx, gpio_values[gpio_idx], gpio_out_i[gpio_idx]);
              error_count++;
            end
          end

          2'b10: begin // Open Drain mode 0, Drive high on value=1
            if (gpio_values[gpio_idx] == 1'b1) begin
              assert(gpio_out_i[gpio_idx] == 1'b1) else begin
                $error("Got wrong output value on GPIO %d. Was suposed to be %b but was %b.", gpio_idx, gpio_values[gpio_idx], gpio_out_i[gpio_idx]);
                error_count++;
              end
              assert(gpio_tx_en_i[gpio_idx] == 1'b1) else begin
                $error("GPIO %d TX enable is not high even thought the GPIO is in Open Drain Mode 0 and the output is driven high.", gpio_idx);
                error_count++;
              end
            end else begin
              assert(gpio_tx_en_i[gpio_idx] == 1'b0) else begin
                $error("GPIO %d TX enable is asserted even thought the GPIO is in Open Drain Mode 0 and the output is driven low.", gpio_idx);
                error_count++;
              end
            end
          end // case: 2'b10

          2'b11: begin // Open Drain mode 1, Drive low on value=0
            if (gpio_values[gpio_idx] == 1'b0) begin
              assert(gpio_out_i[gpio_idx] == 1'b0) else begin
                $error("Got wrong output value on GPIO %d. Was suposed to be %b but was %b.", gpio_idx, gpio_values[gpio_idx], gpio_out_i[gpio_idx]);
                error_count++;
              end
              assert(gpio_tx_en_i[gpio_idx] == 1'b1) else begin
                $error("GPIO %d TX enable is not high even thought the GPIO is in Open Drain Mode 1 and the output is driven low.", gpio_idx);
                error_count++;
              end
            end else begin
              assert(gpio_tx_en_i[gpio_idx] == 1'b0) else begin
                $error("GPIO %d TX enable is asserted even thought the GPIO is in Open Drain Mode 1 and the output is driven high.", gpio_idx);
                error_count++;
              end
            end
          end
        endcase // case (gpio_modes[reg_idx])
      end // for (int gpio_idx = 0; gpio_idx < NrGPIOs; gpio_idx++)
    end // for (int repetion_idx = 0; repetition_idx < 10; repetition_idx++)
  endtask


  initial begin: test
    automatic logic [DataWidth-1:0] data = 0;
    automatic logic [AddrWidth-1:0] addr;
    automatic logic [DataWidth/8-1:0] strb = '1;
    automatic logic                   error = 0;
    // Instantiate driver
    gpio_reg_driver = new(reg_bus);
    end_of_sim_o    = 0;

    // Wait until reset
    gpio_reg_driver.reset_master();
    @(posedge rst_ni);

    // Debug
    // $info("Check reg  interface behavior");
    // addr = GPIO_DUMMY_0_OFFSET;
    // data = 32'h190;
    // gpio_reg_driver.send_write(addr, data, strb, error);

    test_outputs(gpio_reg_driver, NumRepetitions);
    test_toggle_set_clear(gpio_reg_driver, NumRepetitions);
    test_inputs(gpio_reg_driver, NumRepetitions);
    test_interrupts(gpio_reg_driver, NumRepetitions);

    $info("All tests finished with %0d errors.", error_count);
    end_of_sim_o = 1;
  end // block: logic

endprogram
