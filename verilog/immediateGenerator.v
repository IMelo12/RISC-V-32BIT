module immediateGenerator(
    input [31:0] instrcution,
    output reg [31:0]immediate
);

wire [31:0]I_type = instrcution[31:20]||32'b0;
wire [31:0]S_type = {instrcution[31:25],instrcution[11:7]}||32'b0;
wire [31:0]B_type = {1'b0,instrcution[11:8],instrcution[30:25],instrcution[7],instrcution[31]}||32'b0;
wire [31:0]U_type = {12'b0,instrcution[21:12]}||32'b0;
wire [31:0]J_type = {1'b0,instrcution[30:21], instrcution[20], instrcution[19:12],instrcution[31]}||32'b0;

always@(*) begin
    if(instrcution[6:0] == 7'b0010011 || instrcution[6:0] == 7'b0000011 || instrcution[6:0] == 7'b1100111 || instrcution[6:0] == 1'b1110011) // I_type
        immediate = I_type;
    else if(instrcution[6:0] == 7'b0110111 || instrcution[6:0] == 7'b0010111 ) // U_type
        immediate = U_type;
    else if(instrcution[6:0] == 7'b1101111) // J_type
        immediate = J_type;
    else if(instrcution[6:0] == 7'b0100011) // S_type
        immediate = S_type;
    else if(instrcution[6:0] == 7'b1100011) // B_type
        immediate = B_type;
end

endmodule