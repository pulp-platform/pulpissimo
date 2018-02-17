/* 
 * dev_dpi.sv
 * Germain Haugou <haugoug@iis.ee.ethz.ch>
 *
 * Copyright (C) 2013-2018 ETH Zurich, University of Bologna.
 *
 * Copyright and related rights are licensed under the Solderpad Hardware
 * License, Version 0.51 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 * http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
 * or agreed to in writing, software, hardware and materials distributed under
 * this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License.
 *
 */

interface QSPI_CS  ();

  logic csn;

endinterface

interface QSPI ();

  logic sck;
  logic data_0_in;
  logic data_0_out;
  logic data_1_in;
  logic data_1_out;
  logic data_2_in;
  logic data_2_out;
  logic data_3_in;
  logic data_3_out;

endinterface


package dpi_models;

  virtual QSPI    qspim_itf[];
  int             nb_qspim_itf = 0;

  import "DPI-C"   context function void dpi_qspim_cs_edge(chandle handle, longint timestamp, input logic csn);
  import "DPI-C"   context function void dpi_qspim_sck_edge(chandle handle, longint timestamp, input logic sck, input logic data_0, input logic data_1, input logic data_2, input logic data_3);
  import "DPI-C"   context function chandle dpi_qspim_bind(chandle dpi_model, string name, int handle);

  import "DPI-C"   context function chandle dpi_model_load(chandle comp_config);

  export "DPI-C"   function         dpi_print;
  export "DPI-C"   function         dpi_qspim_set_data;

  //export "DPI-C"   function         sv_qspim_set_output;

  function void dpi_print(chandle handle, input string msg);
    $display("[TB] %t - %s", $realtime, msg);
  endfunction : dpi_print

  function void dpi_qspim_set_data(int handle, int data_0, int data_1, int data_2, int data_3);
    automatic virtual QSPI itf = qspim_itf[handle];
    itf.data_0_out = data_0;
    itf.data_1_out = data_1;
    itf.data_2_out = data_2;
    itf.data_3_out = data_3;
  endfunction : dpi_qspim_set_data

  class periph_wrapper #(int NB_SPIS_CHANNELS = 0);

    virtual QSPI    qspi_itf;
    virtual QSPI_CS qspi_cs_itf;
    chandle dpi_model;

    function int load_model(chandle comp_config);
      dpi_model = dpi_model_load(comp_config);
      if (dpi_model == null) return -1;
      else return 0;
    endfunction

    task qpim_bind(string name, virtual QSPI qspi_itf, virtual QSPI_CS qspi_cs_itf);

      chandle dpi_handle;

      qspi_itf.data_0_out = 'bz;
      qspi_itf.data_1_out = 'bz;
      qspi_itf.data_2_out = 'bz;
      qspi_itf.data_3_out = 'bz;

      nb_qspim_itf = nb_qspim_itf + 1;
      qspim_itf = new[nb_qspim_itf](qspim_itf);
      qspim_itf[nb_qspim_itf - 1] = qspi_itf;

      dpi_handle = dpi_qspim_bind(dpi_model, name, nb_qspim_itf - 1);

      //handle = chandle'(qspi_itf);

      this.qspi_itf = qspi_itf;
      this.qspi_cs_itf = qspi_cs_itf;
      fork
      do begin

        @(negedge qspi_cs_itf.csn);
        dpi_qspim_cs_edge(dpi_handle, $realtime*1000, qspi_cs_itf.csn);

        do begin
          @(edge qspi_itf.sck or posedge qspi_cs_itf.csn);

          if (qspi_cs_itf.csn == 1'b0) begin
            dpi_qspim_sck_edge(dpi_handle, $realtime*1000, qspi_itf.sck,
              qspi_itf.data_0_in, qspi_itf.data_1_in, qspi_itf.data_2_in,
              qspi_itf.data_2_in
            );
          end

        end while (qspi_cs_itf.csn == 1'b0);

        dpi_qspim_cs_edge(dpi_handle, $realtime*1000, qspi_cs_itf.csn);

      end while(1);
      join_none
    endtask

    task toggle () ;
      do begin
      end while(1);
    endtask


  endclass

  function void sv_qspim_set_output(input chandle handle, input logic data_0, input logic data_1, input logic data_2, input logic data_3);
    virtual QSPI itf;
    $cast(itf, handle);
    itf.data_0_out = data_0;
    itf.data_1_out = data_1;
    itf.data_2_out = data_2;
    itf.data_3_out = data_3;
  endfunction

endpackage




//module dev_dpi2
//  #(
//    parameter N_QSPIS_CHANNELS = 0
//  )
//  (
//     QSPI qspis[0:N_QSPIS_CHANNELS-1]
//  );
//
//  initial
//  begin
//
//  end
//
//  generate
//  begin
//    for (genvar i=0; i<N_QSPIS_CHANNELS; i++)
//    begin
//      always @(posedge qspis[i].sck)
//      begin
//      end
//    end
//  end
//
//endmodule
