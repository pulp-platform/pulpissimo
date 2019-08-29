





module cluster_clock_gating
(
    input  logic clk_i,
    input  logic en_i,
    input  logic test_en_i,
    output logic clk_o
);

    SC8T_CKGPRELATNX4_CSC28L clk_gate_i
    (
        .CLK(clk_i),
        .Z(clk_o),
        .E(en_i),
        .TE(test_en_i)
    );

    // SC8T_CKGPRELATNX1_CSC20SL clk_gate_i
    // (
    //     .CLK(clk_i),
    //     .Z(clk_o),
    //     .E(en_i),
    //     .TE(test_en_i)
    // );

endmodule
