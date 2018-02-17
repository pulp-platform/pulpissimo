/* 
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

package tb_driver;

  import "DPI-C"   function chandle dpi_config_get_from_file(string path);
  import "DPI-C"   function chandle dpi_config_get_config(chandle config_handle, string path);
  import "DPI-C"   function int dpi_config_get_int(chandle config_handle);
  import "DPI-C"   function string dpi_config_get_str(chandle config_handle);

  import "DPI-C"   function chandle dpi_driver_set_config(chandle config_handle);
  import "DPI-C"   function int dpi_driver_get_nb_comp(chandle driver_handle);
  import "DPI-C"   function string dpi_driver_get_comp_name(chandle driver_handle, int index);
  import "DPI-C"   function chandle dpi_driver_get_comp_config(chandle driver_handle, int index);
  import "DPI-C"   function int dpi_driver_get_comp_nb_itf(chandle comp_handle, int index);
  import "DPI-C"   function void dpi_driver_get_comp_itf_info(chandle comp_handle, int index, int itf_index, output string itf_name, output string itf_type, output int itf_id, output int itf_sub_id);

  typedef struct { 
    virtual QSPI itf;
    virtual QSPI_CS cs[];
  } qspi_info_t;

  class tb_driver;

    chandle config_handle;
    qspi_info_t qspi_infos[];

    function register_qspim_itf(int itf_id, virtual QSPI itf, virtual QSPI_CS cs[]);
      qspi_infos = new[itf_id+1] (qspi_infos);
      qspi_infos[itf_id].itf = itf;
      qspi_infos[itf_id].cs = cs;
      //qspi_infos[itf_id].cs = new[cs.size] (cs);
    endfunction

    task build_from_json(string path);

      chandle uart;
      int baudrate;
      int nb_comp;
      chandle driver_handle;

      config_handle = dpi_config_get_from_file(path);

      uart = dpi_config_get_config(config_handle, "**/uart_loopback/baudrate");
      baudrate = dpi_config_get_int(uart);

      driver_handle = dpi_driver_set_config(config_handle);
      nb_comp = dpi_driver_get_nb_comp(driver_handle);

      $display("[TB] %t - Baudrate: %d", $realtime, baudrate);
      $display("[TB] %t - NB COMP: %d", $realtime, nb_comp);

      for(int i = 0; i < nb_comp; i++) begin
        string comp_name = dpi_driver_get_comp_name(driver_handle, i);
        chandle comp_config = dpi_driver_get_comp_config(driver_handle, i);
        string comp_type = dpi_config_get_str(dpi_config_get_config(comp_config, "type"));
        int nb_itf = dpi_driver_get_comp_nb_itf(comp_config, i);

        $display("[TB] %t - Found TB driver component (index: %d, name: %s, type: %s)", $realtime, i, comp_name, comp_type);

        if (comp_type == "dpi") begin
          dpi_models::periph_wrapper i_comp = new();
          int err;

          $display("[TB] %t - Instantiating DPI component", $realtime, i);

          err = i_comp.load_model(comp_config);
          if (err != 0) $fatal(1, "[TB] %t - Failed to instantiate periph model", $realtime);

          for(int j = 0; j < nb_itf; j++) begin
            string itf_type;
            string itf_name;
            int itf_id;
            int itf_sub_id;
            dpi_driver_get_comp_itf_info(comp_config, i, j, itf_name, itf_type, itf_id, itf_sub_id);
            $display("[TB] %t - Got interface information (index: %d, name: %s, type: %s, id: %d, sub_id: %d)", $realtime, i, itf_name, itf_type, itf_id, itf_sub_id);

            if (itf_type == "QSPIM") begin
                i_comp.qpim_bind(itf_name, qspi_infos[itf_id].itf, qspi_infos[itf_id].cs[itf_sub_id]);

            end

          end

        end

      end


    endtask

  endclass

endpackage
