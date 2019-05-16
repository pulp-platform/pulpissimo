// Copyright 2019 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.


module count_clk
  #(
        parameter REF_V =   10000000
    )
    (
    input clk,
    input reset,
    output led
    );
    
    logic [31:0] conta;
    logic led_int;
    //update:
    always @ (posedge clk or negedge reset)
    begin
        if(reset==0 )
        begin
            conta<=0;
            led_int<=0;
        end
        else
        begin
            conta<=conta+1;
            if (conta==REF_V+1)
            begin
                conta<=2;
                led_int<=~led_int;
            end
        end
    end
    
    assign led=led_int;
    
endmodule
