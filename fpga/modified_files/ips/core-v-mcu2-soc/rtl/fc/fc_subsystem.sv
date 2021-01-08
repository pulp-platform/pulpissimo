// Copyright 2018 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

// Modified by Hugh Pollitt-Smith, CMC Microsystems

//`include "soc_bus_defines.sv"

module fc_subsystem #(
    parameter CORE_TYPE           = 0,
    parameter USE_FPU             = 1,
    parameter USE_HWPE            = 1,
    parameter N_EXT_PERF_COUNTERS = 1,
    parameter EVENT_ID_WIDTH      = 8,
    parameter PER_ID_WIDTH        = 32,
    parameter NB_HWPE_PORTS       = 4,
    parameter PULP_SECURE         = 1,
    parameter TB_RISCV            = 0,
    parameter CORE_ID             = 4'h0,
    parameter CLUSTER_ID          = 6'h1F
)
(
    input  logic                      clk_i,
    input  logic                      rst_ni,
    input  logic                      test_en_i,

    XBAR_TCDM_BUS.Master              l2_data_master,
    XBAR_TCDM_BUS.Master              l2_instr_master,
    XBAR_TCDM_BUS.Master              l2_hwpe_master [NB_HWPE_PORTS-1:0],
`ifdef QUENTIN_SCM
    UNICAD_MEM_BUS_32.Master          scm_l2_data_master,
    UNICAD_MEM_BUS_32.Master          scm_l2_instr_master,
`endif
    APB_BUS.Slave                     apb_slave_eu,
    APB_BUS.Slave                     apb_slave_hwpe,

    input  logic                      fetch_en_i,
    input  logic [31:0]               boot_addr_i,
    input  logic                      debug_req_i,

    input  logic                      event_fifo_valid_i,
    output logic                      event_fifo_fulln_o,
    input  logic [EVENT_ID_WIDTH-1:0] event_fifo_data_i, // goes indirectly to core interrupt
    input  logic [31:0]               events_i, // goes directly to core interrupt, should be called irqs
    output logic [1:0]                hwpe_events_o,

    output logic                      supervisor_mode_o
);

    localparam USE_IBEX   = CORE_TYPE == 1 || CORE_TYPE == 2;
    localparam IBEX_RV32M = CORE_TYPE == 1;
    localparam IBEX_RV32E = CORE_TYPE == 2;


    // Interrupt signals
    logic        core_irq_req   ;
    logic        core_irq_sec   ;
    logic [4:0]  core_irq_id    ;
    logic [4:0]  core_irq_ack_id;
    logic        core_irq_ack   ;
    logic [15:0] core_irq_fast  ;
    logic [31:0] core_irq_x;
    logic	 core_irq_external ;
    logic	 core_irq_software ;
    logic	 core_irq_timer ;

    logic [3:0]  irq_ack_id;

    // Core sleep signal (not used in pulpissimo)
    logic	 core_sleep ;

    // Boot address, core id, cluster id, fethc enable and core_status
    logic [31:0] boot_addr        ;
    logic        fetch_en_int     ;
    logic        core_busy_int    ;
    logic        perf_counters_int;
    logic [31:0] hart_id;
    
    logic [31:0] dm_halt_addr; //added for cv32e40p
    logic [31:0] dm_exception_addr;  //added for cv32e40p
    logic [31:0] mtvec_addr; //added for cv32e40p

    //EU signals
    logic core_clock_en;
    logic fetch_en_eu  ;

    //Core Instr Bus
    logic [31:0] core_instr_addr, core_instr_rdata;
    logic        core_instr_req, core_instr_gnt, core_instr_rvalid, core_instr_err;

    //Core Data Bus
    logic [31:0] core_data_addr, core_data_rdata, core_data_wdata;
    logic        core_data_req, core_data_gnt, core_data_rvalid, core_data_err;
    logic        core_data_we  ;
    logic [ 3:0]  core_data_be ;
    logic is_scm_instr_req, is_scm_data_req;

    assign perf_counters_int = 1'b0;
    assign fetch_en_int      = fetch_en_eu & fetch_en_i;

    assign hart_id = {21'b0, CLUSTER_ID[5:0], 1'b0, CORE_ID[3:0]}; //hart_id = 992
    assign mtvec_addr = 32'h00000000 ; //added for cv32e40p
    assign dm_halt_addr = 32'h1A110800 ; //added for cv32e40p
    assign dm_exception_addr = 32'h1A118080 ; //added for cv32e40p; value taken from IBEX

    XBAR_TCDM_BUS core_data_bus ();
    XBAR_TCDM_BUS core_instr_bus ();

    //********************************************************
    //************ CORE DEMUX (TCDM vs L2) *******************
    //********************************************************
`ifdef QUENTIN_SCM
    assign is_scm_instr_req = (core_instr_addr < `SOC_L2_PRI_CH0_SCM_END_ADDR) && (core_instr_addr >= `SOC_L2_PRI_CH0_SCM_START_ADDR) || (core_instr_addr < `ALIAS_SOC_L2_PRI_CH0_SCM_END_ADDR) && (core_instr_addr >= `ALIAS_SOC_L2_PRI_CH0_SCM_START_ADDR);

    fc_demux fc_demux_instr_i (
        .clk          ( clk_i               ),
        .rst_n        ( rst_ni              ),
        .port_sel_i   ( is_scm_instr_req    ),
        .slave_port   ( core_instr_bus      ),
        .master_port0 ( l2_instr_master     ),
        .master_port1 ( scm_l2_instr_master )
    );

    assign core_instr_bus.req   = core_instr_req;
    assign core_instr_bus.add   = core_instr_addr;
    assign core_instr_bus.wen   = ~1'b0;
    assign core_instr_bus.wdata = '0;
    assign core_instr_bus.be    = 4'b1111;
    assign core_instr_gnt       = core_instr_bus.gnt;
    assign core_instr_rvalid    = core_instr_bus.r_valid;
    assign core_instr_rdata     = core_instr_bus.r_rdata;
    assign core_instr_err       = 1'b0;

    assign is_scm_data_req = (core_data_addr < `SOC_L2_PRI_CH0_SCM_END_ADDR) && (core_data_addr >= `SOC_L2_PRI_CH0_SCM_START_ADDR) || (core_data_addr < `ALIAS_SOC_L2_PRI_CH0_SCM_END_ADDR) && (core_data_addr >= `ALIAS_SOC_L2_PRI_CH0_SCM_START_ADDR);

    fc_demux fc_demux_data_i (
        .clk          ( clk_i              ),
        .rst_n        ( rst_ni             ),
        .port_sel_i   ( is_scm_data_req    ),
        .slave_port   ( core_data_bus      ),
        .master_port0 ( l2_data_master     ),
        .master_port1 ( scm_l2_data_master )
    );

    assign core_data_bus.req   = core_data_req;
    assign core_data_bus.add   = core_data_addr;
    assign core_data_bus.wen   = ~core_data_we;
    assign core_data_bus.wdata = core_data_wdata;
    assign core_data_bus.be    = core_data_be;
    assign core_data_gnt       = core_data_bus.gnt;
    assign core_data_rvalid    = core_data_bus.r_valid;
    assign core_data_rdata     = core_data_bus.r_rdata;
    assign core_data_err       = 1'b0;
`else

    assign l2_data_master.req    = core_data_req;
    assign l2_data_master.add    = core_data_addr;
    assign l2_data_master.wen    = ~core_data_we;
    assign l2_data_master.wdata  = core_data_wdata;
    assign l2_data_master.be     = core_data_be;
    assign core_data_gnt         = l2_data_master.gnt;
    assign core_data_rvalid      = l2_data_master.r_valid;
    assign core_data_rdata       = l2_data_master.r_rdata;
    assign core_data_err         = l2_data_master.r_opc;


    assign l2_instr_master.req   = core_instr_req;
    assign l2_instr_master.add   = core_instr_addr;
    assign l2_instr_master.wen   = 1'b1;
    assign l2_instr_master.wdata = '0;
    assign l2_instr_master.be    = 4'b1111;
    assign core_instr_gnt        = l2_instr_master.gnt;
    assign core_instr_rvalid     = l2_instr_master.r_valid;
    assign core_instr_rdata      = l2_instr_master.r_rdata;
    assign core_instr_err        = l2_instr_master.r_opc;


`endif

    //********************************************************
    //************ RISCV CORE ********************************
    //********************************************************
    generate
    if ( USE_IBEX == 0) begin: FC_CORE
    assign boot_addr = boot_addr_i;
    cv32e40p_core #(
	.PULP_XPULP	( 1	), //not in riscy         
	.NUM_MHPMCOUNTERS	( 1	), //not in riscy
//	.N_EXT_PERF_COUNTERS ( N_EXT_PERF_COUNTERS ), //not used in cv32 (=NUM_MHPMCOUNTERS?)
//        .PULP_SECURE         ( 1                   ), //not used in cv32
        .PULP_CLUSTER        ( 0                   ), //riscy=cv32
        .FPU                 ( 0             ) //riscy=cv32
//        .FP_DIVSQRT          ( USE_FPU             ), //not used in cv32
//        .SHARED_FP           ( 0                   ), //not used in cv32
//        .SHARED_FP_DIVSQRT   ( 2                   ) //not used in cv32
    ) lFC_CORE (
        .clk_i                 ( clk_i             ), //riscy=cv32
        .rst_ni                ( rst_ni            ),//riscy=cv32
        .pulp_clock_en_i       ( core_clock_en     ), //clock_en_i in riscy
        .scan_cg_en_i          ( test_en_i         ), //test_en_i in riscy
        .boot_addr_i           ( boot_addr         ), //riscy=cv32
        .hart_id_i             ( hart_id           ), // not in ricsy; in IBEX
	.dm_halt_addr_i	       ( dm_halt_addr	   ), //not in riscy
	.dm_exception_addr_i   ( dm_exception_addr ), //not in riscy
	.mtvec_addr_i	       ( mtvec_addr	   ), //not in riscy

        // Instruction Memory Interface:  Interface to Instruction Logaritmic interconnect: Req->grant handshake
        .instr_addr_o          ( core_instr_addr   ), //riscy=cv32
        .instr_req_o           ( core_instr_req    ), //riscy=cv32
        .instr_rdata_i         ( core_instr_rdata  ), //riscy=cv32
        .instr_gnt_i           ( core_instr_gnt    ), //riscy=cv32
        .instr_rvalid_i        ( core_instr_rvalid ), //riscy=cv32

        // Data memory interface:
        .data_addr_o           ( core_data_addr    ), //riscy=cv32
        .data_req_o            ( core_data_req     ), //riscy=cv32
        .data_be_o             ( core_data_be      ), //riscy=cv32
        .data_rdata_i          ( core_data_rdata   ), //riscy=cv32
        .data_we_o             ( core_data_we      ), //riscy=cv32
        .data_gnt_i            ( core_data_gnt     ), //riscy=cv32
        .data_wdata_o          ( core_data_wdata   ), //riscy=cv32
        .data_rvalid_i         ( core_data_rvalid  ), //riscy=cv32

        // apu-interconnect
        // handshake signals
//        .apu_master_req_o      (                   ), //riscy=cv32
//        .apu_master_ready_o    (                   ), //riscy=cv32
//        .apu_master_gnt_i      ( 1'b1              ), //riscy=cv32
        // request channel
//        .apu_master_operands_o (                   ), //riscy=cv32
//        .apu_master_op_o       (                   ), //riscy=cv32
//        .apu_master_type_o     (                   ), //riscy=cv32
//        .apu_master_flags_o    (                   ), //riscy=cv32
        // response channel
//        .apu_master_valid_i    ( '0                ), //riscy=cv32
//        .apu_master_result_i   ( '0                ), //riscy=cv32
//        .apu_master_flags_i    ( '0                ), //riscy=cv32

        .irq_i                 ( core_irq_x ), //only single bit wide in riscy
 //       .irq_id_i              ( core_irq_id       ), //not used in cv32
        .irq_ack_o             ( core_irq_ack      ), //riscy=cv32
        .irq_id_o              ( core_irq_ack_id   ), //riscy=cv32
 //       .irq_sec_i             ( 1'b0              ), //not used in cv32
 //       .sec_lvl_o             (                   ), //not used in cv32

        .debug_req_i           ( debug_req_i       ), //riscy=cv32

        .fetch_enable_i        ( fetch_en_int      ), //riscy=cv32
//	.core_busy_o	       (		   ), //not used in cv32
        .core_sleep_o          (                   ) //not used in riscy
 //       .ext_perf_counters_i   ( perf_counters_int ), //not used in cv32
 //       .fregfile_disable_i    ( 1'b0              ) // try me! not used in cv32
    );
    end else begin: FC_CORE
    assign boot_addr = boot_addr_i & 32'hFFFFFF00; // RI5CY expects 0x80 offset, Ibex expects 0x00 offset (adds reset offset 0x80 internally)
`ifdef VERILATOR
    ibex_core #(
`elsif TRACE_EXECUTION
    ibex_core_tracing #(
`else
    ibex_core #(
`endif
        .PMPEnable           ( 0            ),
        .MHPMCounterNum      ( 8            ),
        .MHPMCounterWidth    ( 40           ),
        .RV32E               ( IBEX_RV32E   ),
        .RV32M               ( IBEX_RV32M   ),
        .DmHaltAddr          ( 32'h1A110800 ),
        .DmExceptionAddr     ( 32'h1A110808 )
    ) lFC_CORE (
        .clk_i                 ( clk_i             ),
        .rst_ni                ( rst_ni            ),

        .test_en_i             ( test_en_i         ),

        .hart_id_i             ( hart_id           ),
        .boot_addr_i           ( boot_addr         ),

        // Instruction Memory Interface:  Interface to Instruction Logaritmic interconnect: Req->grant handshake
        .instr_addr_o          ( core_instr_addr   ),
        .instr_req_o           ( core_instr_req    ),
        .instr_rdata_i         ( core_instr_rdata  ),
        .instr_gnt_i           ( core_instr_gnt    ),
        .instr_rvalid_i        ( core_instr_rvalid ),
        .instr_err_i           ( core_instr_err    ),

        // Data memory interface:
        .data_addr_o           ( core_data_addr    ),
        .data_req_o            ( core_data_req     ),
        .data_be_o             ( core_data_be      ),
        .data_rdata_i          ( core_data_rdata   ),
        .data_we_o             ( core_data_we      ),
        .data_gnt_i            ( core_data_gnt     ),
        .data_wdata_o          ( core_data_wdata   ),
        .data_rvalid_i         ( core_data_rvalid  ),
        .data_err_i            ( core_data_err     ),

        .irq_software_i        ( 1'b0              ),
        .irq_timer_i           ( 1'b0              ),
        .irq_external_i        ( 1'b0              ),
        .irq_fast_i            ( 15'b0	           ),
        .irq_nm_i              ( 1'b0              ),

        .debug_req_i           ( debug_req_i       ),

        .fetch_enable_i        ( fetch_en_int      ),
        .core_sleep_o          (                   )
    );
    end
    endgenerate

    assign supervisor_mode_o = 1'b1;

    generate
    // Use similar technique as Ibex to convert ID to interrupt lines
	    if ( USE_IBEX == 0) begin : convert_cv32_irqs
    always_comb begin : gen_core_irq
	core_irq_x = '0;
	if (core_irq_req) begin
		core_irq_x[core_irq_id] = 1'b1;
	end
    end
    end
    endgenerate
   
    apb_interrupt_cntrl #(.PER_ID_WIDTH(PER_ID_WIDTH)) fc_eu_i (
        .clk_i              ( clk_i              ),
        .rst_ni             ( rst_ni             ),
        .test_mode_i        ( test_en_i          ),
        .events_i           ( events_i           ),
        .event_fifo_valid_i ( event_fifo_valid_i ),
        .event_fifo_fulln_o ( event_fifo_fulln_o ),
        .event_fifo_data_i  ( event_fifo_data_i  ),
        .core_secure_mode_i ( 1'b0               ),
        .core_irq_id_o      ( core_irq_id        ),
        .core_irq_req_o     ( core_irq_req       ),
        .core_irq_ack_i     ( core_irq_ack       ),
        .core_irq_id_i      ( core_irq_ack_id    ),
        .core_irq_sec_o     ( /* SECURE IRQ */   ),
        .core_clock_en_o    ( core_clock_en      ),
        .fetch_en_o         ( fetch_en_eu        ),
        .apb_slave          ( apb_slave_eu       )
    );


    generate
    if(USE_HWPE) begin : fc_hwpe_gen
        fc_hwpe #(
            .N_MASTER_PORT ( NB_HWPE_PORTS ),
            .ID_WIDTH      ( 2             )
        ) i_fc_hwpe (
            .clk_i             ( clk_i          ),
            .rst_ni            ( rst_ni         ),
            .test_mode_i       ( test_en_i      ),
            .hwacc_xbar_master ( l2_hwpe_master ),
            .hwacc_cfg_slave   ( apb_slave_hwpe ),
            .evt_o             ( hwpe_events_o  ),
            .busy_o            (                )
        );
    end
    else begin : no_fc_hwpe_gen
        assign hwpe_events_o = '0;
        assign apb_slave_hwpe.prdata  = '0;
        assign apb_slave_hwpe.pready  = '0;
        assign apb_slave_hwpe.pslverr = '0;
        for(genvar ii=0; ii<NB_HWPE_PORTS; ii++) begin
            assign l2_hwpe_master[ii].req   = '0;
            assign l2_hwpe_master[ii].wen   = '0;
            assign l2_hwpe_master[ii].wdata = '0;
            assign l2_hwpe_master[ii].be    = '0;
            assign l2_hwpe_master[ii].add   = '0;
        end
    end
    endgenerate

endmodule
