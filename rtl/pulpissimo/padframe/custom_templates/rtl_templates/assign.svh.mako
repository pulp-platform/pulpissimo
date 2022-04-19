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

// Assignment Macros
// Assigns all members of port struct to another struct with same names but potentially different order


%for pad_domain in padframe.pad_domains:
%for port_group in pad_domain.port_groups:
<%
sig_name_aliases = {}
for port in port_group.ports:
    if port.user_attr and 'port_signal_aliases' in port.user_attr:
       sig_name_aliases.update(port.user_attr['port_signal_aliases'])
%>

%if port_group.port_signals_pads2soc:
`define ASSIGN_${port_group.name.upper()}_PAD2SOC(load, driver) ${"\\"}
%for signal in port_group.port_signals_pads2soc:
%if signal.name in sig_name_aliases:
  assign load.${sig_name_aliases[signal.name]} = driver.${signal.name}; ${"\\"}
%else:
  assign load.${signal.name} = driver.${signal.name}; ${"\\"}
%endif
%endfor
%endif

%if port_group.port_signals_soc2pads:
`define ASSIGN_${port_group.name.upper()}_SOC2PAD(load, driver) ${"\\"}
%for signal in port_group.port_signals_soc2pads:
%if signal.name in sig_name_aliases:
  assign load.${signal.name} = driver.${sig_name_aliases[signal.name]}; ${"\\"}
%else:
  assign load.${signal.name} = driver.${signal.name}; ${"\\"}
%endif
%endfor
%endif

%endfor

%endfor
