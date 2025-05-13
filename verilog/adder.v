module adder #(parameter WIDTH) 
(
    input [WIDTH-1:0] a,
    input [WIDTH-1:0] b,

    output [WIDTH-1:0] y
);

assign y = a + b;

endmodule