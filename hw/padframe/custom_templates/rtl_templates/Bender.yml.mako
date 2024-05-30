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
# ${line}
% endfor
package:
  name: ${padframe.name}_${padframe.user_attr['target_platform']}
  authors:
    - "Padrick"

dependencies:
  register_interface:     { git: "https://github.com/pulp-platform/register_interface.git", version: 0.4.1 }
  common_cells:           { git: "https://github.com/pulp-platform/common_cells.git", version: 1.21.0 }

export_include_dirs:
- include

sources:
  - target: ${padframe.user_attr['target_platform']}
    files:
      - src/pkg_${padframe.name}.sv
    % for pad_domain in padframe.pad_domains:
      - src/pkg_internal_${padframe.name}_${pad_domain.name}.sv
      - src/${padframe.name}_${pad_domain.name}_config_reg_pkg.sv
      - src/${padframe.name}_${pad_domain.name}_config_reg_top.sv
      - src/${padframe.name}_${pad_domain.name}_pads.sv
      - src/${padframe.name}_${pad_domain.name}_muxer.sv
      - src/${padframe.name}_${pad_domain.name}.sv
    % endfor
      - src/${padframe.name}.sv

