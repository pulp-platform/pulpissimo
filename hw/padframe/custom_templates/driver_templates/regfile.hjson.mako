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

<%
  import math
  import string
  from padrick.Model.PadSignal import SignalDirection
  from natsort import natsorted

  def sort_by_name(seq):
    return natsorted(seq, lambda x: x.name)

%>
{
% for line in header_text.splitlines():
    # ${line}
% endfor
    name: "${padframe.name}_${pad_domain.name}_config"
    clock_primary: "clk_i"
    reset_primary: "rst_ni"
    bus_interfaces: [
        { protocol: "reg_iface", direction: "device"}
    ]
    regwidth: 32,
    registers: [
        {skipto: "${start_address_offset}"},
        {
            name: INFO
            desc: "Read-only IP Information register"
            swaccess: "ro"
            hwaccess: "hro"
            fields: [
              {
                bits: "15:0"
                name: HW_VERSION
                desc: "Hardware version ID."
                resval: ${hw_version}
              },
              {
                  bits:"31:16"
                  name: PADCOUNT
                  desc: "The number of muxable pads in this IP."
                  resval: "${len([pad for pad in pad_domain.pad_list if not pad.is_static])}"
              }
            ]
        }
% for pad in pad_domain.pad_list:
% if pad.dynamic_pad_signals_soc2pad:
<%
  # Calculate how many config registers we need to accomodate all dynamic
  # pad signals that need a register.
  total_dynamic_padsignal_bits = sum([signal.size for signal in pad.dynamic_pad_signals])
  num_cfg_regs = total_dynamic_padsignal_bits//32 + 1

  # Group pad_signals by config register
  pad_signals_grouping = []
  current_signal_grouping = []
  current_group_size = 0
  for pad_signal in pad.dynamic_pad_signals_soc2pad:
      if current_group_size + pad_signal.size > 32:
          # Start new grouping
          pad_signals_grouping.append(current_signal_grouping)
          current_group_size = 0
          current_signal_grouping = [(pad_signal, (pad_signal.size-1,0))]
      else:
          current_signal_grouping.append((pad_signal, (current_group_size + pad_signal.size-1, current_group_size)))
          current_group_size = current_group_size + pad_signal.size
  pad_signals_grouping.append(current_signal_grouping)

  # Convert the config register index to a capital letter index e.g. 1 -> A, 2 -> B, 3->C
  # If there are more then 26 config registers needed, use another character
  def cfg_suffix(idx: int):
      cfg_suffix = ""
      if num_cfg_regs > 1:
          num_cfg_reg_chars = math.ceil(math.log(num_cfg_regs, 26))
          for k in range(num_cfg_reg_chars):
              cfg_suffix = string.ascii_uppercase[idx % 26]+cfg_suffix
              idx = idx // 26
      return cfg_suffix
%> \
% for i, pad_signals in enumerate(pad_signals_grouping):
     {
          name: ${pad.name.upper()}_CFG${cfg_suffix(i)}
          desc: '''
            Pad signal configuration.
          '''
          swaccess: "rw"
          fields: [
% for pad_signal, (msb, lsb) in pad_signals:
            {
                bits: "${str(msb)+':'+str(lsb) if msb != lsb else lsb}"
                name: ${pad_signal.name}
                desc: '''
                     ${pad_signal.description if pad_signal.description else ""}
                '''
                swaccess: "rw"
                hwaccess: "hro"
                resval: "${pad.connections.get(pad_signal, pad_signal.default_reset_value) if pad.connections else pad_signal.default_reset_value}"
            },
% endfor
          ]
      }
% endfor
% endif
% if pad.dynamic_pad_signals:
<%
    # The reset value depends on whether the dynamic pad has a default_port or not. If it doesn't the resvalue is
    # zero (connect to register file value). If it has one, we need to find the right select value that corresponds
    # to the port.
    connectable_ports = []
    idx = 0
    reset_value = 0
    for port_group in sort_by_name(pad_domain.port_groups):
      for port in sort_by_name(port_group.ports):
        if port.mux_groups.intersection(pad.mux_groups):
          connectable_ports.append((port_group, port))
          idx += 1
          if pad.default_port and pad.default_port[0].name == port_group.name and pad.default_port[1].name == port.name:
            reset_value = idx
%>
       {
          name: ${pad.name.upper()}_MUX_SEL
          desc: '''
              Pad signal port multiplex selection for pad ${pad.name}. The programmed value defines which port
              is connected to the pad.
          '''
          swaccess: "rw"
          hwaccess: "hro"
          resval: ${reset_value}
          fields: [
              {
                  bits: "${max(0,math.ceil(math.log2(len(pad_domain.get_ports_in_mux_groups(pad.mux_groups))+1))-1)}:0"
                  enum: [
                      { value: "0", name: "register", desc: "Connects the Pad to the internal configuration register."}
%for idx, (port_group, port) in enumerate(connectable_ports):
                      { value: "${idx+1}", name: "port_${port_group.name}_${port.name.lower()}", desc: "Connect port ${port.name} from port group ${port_group.name} to this pad." }
%endfor
                  ]
              }
          ]
      }
% endif

% endfor
    ]
}
