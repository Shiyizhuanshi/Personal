module lfsr (
    input logic clk,
    input logic en,
    input logic rst,
    output [4:1] data_out
);

    logic [4:1] sreg;

    always_ff @(posedge clk, posedge rst)
        if (rst)
            sreg <= 4'b1;
        else if (en)
            sreg <= {sreg[3:1], sreg[4] ^ sreg[3]};
        else 
            sreg <= sreg;

    assign data_out = sreg;

endmodule
