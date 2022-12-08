## Manuel Eggimann <meggimann@iis.ee.ethz.ch>
##
## Copyright (C) 2021-2022 ETH Zürich
## 
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##
##     http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.

% for line in header_text.splitlines():
// ${line}
% endfor
module ${padframe.name}
  import pkg_${padframe.name}::*;
#(
  parameter int unsigned   AW = 32,
  parameter int unsigned   DW = 32,
  parameter type req_t = logic, // reg_interface request type
  parameter type resp_t = logic, // reg_interface response type
  parameter logic [DW-1:0] DecodeErrRespData = 32'hdeadda7a,
  localparam int unsigned NGPIO = ${padframe.user_attr['num_gpios']}
)(
  input logic                                clk_i,
  input logic                                rst_ni,
% if any([pad_domain.override_signals for pad_domain in padframe.pad_domains]):
  input override_signals_t                   override_signals,
% endif
% if any([pad_domain.static_connection_signals_pad2soc for pad_domain in padframe.pad_domains]):
  output static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
% endif
% if any([pad_domain.static_connection_signals_soc2pad for pad_domain in padframe.pad_domains]):
  input  static_connection_signals_soc2pad_t static_connection_signals_soc2pad,
% endif
% if any([port_group.port_signals_soc2pads for pad_domain in padframe.pad_domains for port_group in pad_domain.port_groups]):
  output port_signals_pad2soc_t              port_signals_pad2soc,
% endif
% if any([port_group.port_signals_soc2pads for pad_domain in padframe.pad_domains for port_group in pad_domain.port_groups]):
  input port_signals_soc2pad_t               port_signals_soc2pad,
% endif
  // Landing Pads
% for pad_domain in padframe.pad_domains:
% for pad in pad_domain.pad_list:
% if not(pad.user_attr and 'custom_toplevel_connection' in pad.user_attr and pad.user_attr['custom_toplevel_connection']):
% for signal in pad.landing_pads:
  inout wire logic                           ${pad.name},
% endfor
% endif
% endfor
% endfor
## The muxed IO pads in PULPissimo are treated specially. We render them as an array of wires to make the connections easier.
  inout wire [NGPIO-1:0]                     pad_io,
  // Config Interface
  input req_t                                config_req_i,
  output resp_t                              config_rsp_o
  );


% for pad_domain in padframe.pad_domains:
  req_t ${pad_domain.name}_config_req;
  resp_t ${pad_domain.name}_config_resp;
  ${padframe.name}_${pad_domain.name} #(
    .req_t(req_t),
    .resp_t(resp_t)
  ) i_${pad_domain.name} (
   .clk_i,
   .rst_ni,
% if pad_domain.override_signals:
   .override_signals_i(override_signals.${pad_domain.name}),
% endif
% if pad_domain.static_connection_signals_pad2soc:
   .static_connection_signals_pad2soc(static_connection_signals_pad2soc.${pad_domain.name}),
% endif
% if pad_domain.static_connection_signals_soc2pad:
   .static_connection_signals_soc2pad(static_connection_signals_soc2pad.${pad_domain.name}),
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
   .port_signals_pad2soc_o(port_signals_pad2soc.${pad_domain.name}),
% endif
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
   .port_signals_soc2pad_i(port_signals_soc2pad.${pad_domain.name}),
% endif
% for pad in pad_domain.pad_list:
% if not(pad.user_attr and 'custom_toplevel_connection' in pad.user_attr and pad.user_attr['custom_toplevel_connection']):
% for signal in pad.landing_pads:
   .pad_${pad.name}_${signal.name}(${pad.name}),
% endfor
% endif
% endfor
% for i in range(padframe.user_attr['num_gpios']):
   .pad_pad_io${f'{i:02d}'}_${signal.name}(pad_io[${i}]),
% endfor
   .config_req_i(${pad_domain.name}_config_req),
   .config_rsp_o(${pad_domain.name}_config_resp)
  );

% endfor
<%
  import math
  config_req_o_collection    = ", ".join(f"{pad_domain.name}_config_req" for pad_domain in reversed(padframe.pad_domains))
  config_resp_i_collection = ", ".join(f"{pad_domain.name}_config_resp" for pad_domain in reversed(padframe.pad_domains))
  reg_addr_width = math.ceil(math.log2(address_space_size+1))
  num_pad_domains = len(padframe.pad_domains)
%>
   localparam int unsigned NUM_PAD_DOMAINS = ${num_pad_domains};
   localparam int unsigned REG_ADDR_WIDTH = ${reg_addr_width};
   typedef struct packed {
      int unsigned idx;
      logic [REG_ADDR_WIDTH-1:0] start_addr;
      logic [REG_ADDR_WIDTH-1:0] end_addr;
   } addr_rule_t;

   localparam addr_rule_t[NUM_PAD_DOMAINS-1:0] ADDR_DEMUX_RULES = '{
% for idx, pad_domain in enumerate(padframe.pad_domains):
     '{ idx: ${idx}, start_addr: ${reg_addr_width}'d${address_ranges[pad_domain.name][0]},  end_addr: ${reg_addr_width}'d${address_ranges[pad_domain.name][1]}}${"," if idx != num_pad_domains-1 else ""}
% endfor
     };
   logic[$clog2(NUM_PAD_DOMAINS+1)-1:0] pad_domain_sel; // +1 since there is an additional error slave
   addr_decode #(
       .NoIndices(NUM_PAD_DOMAINS+1),
       .NoRules(NUM_PAD_DOMAINS),
       .addr_t(logic[REG_ADDR_WIDTH-1:0]),
       .rule_t(addr_rule_t)
     ) i_addr_decode(
       .addr_i(config_req_i.addr[REG_ADDR_WIDTH-1:0]),
       .addr_map_i(ADDR_DEMUX_RULES),
       .dec_valid_o(),
       .dec_error_o(),
       .idx_o(pad_domain_sel),
       .en_default_idx_i(1'b1),
       .default_idx_i(${math.ceil(math.log2(num_pad_domains+1))}'d${num_pad_domains}) // The last entry is the error slave
     );

     req_t error_slave_req;
     resp_t error_slave_rsp;

     // Config Interface demultiplexing
     reg_demux #(
       .NoPorts(NUM_PAD_DOMAINS+1), //+1 for the error slave
       .req_t(req_t),
       .rsp_t(resp_t)
     ) i_config_demuxer (
       .clk_i,
       .rst_ni,
       .in_select_i(pad_domain_sel),
       .in_req_i(config_req_i),
       .in_rsp_o(config_rsp_o),
       .out_req_o({error_slave_req, ${config_req_o_collection}}),
       .out_rsp_i({error_slave_rsp, ${config_resp_i_collection}})
     );

     assign error_slave_rsp.error = 1'b1;
     assign error_slave_rsp.rdata = DecodeErrRespData;
     assign error_slave_rsp.ready = 1'b1;

endmodule
