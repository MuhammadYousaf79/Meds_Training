module sqrt (
	input logic [31:0] number,
	output logic [31:0] result
);

	real guess;
	real epsilon = 0.00001;
	real r_number;

	always_comb begin
		r_number = number;
		
		guess = r_number / 2;
		
		while (((guess * guess) - r_number) > epsilon || (r_number - (guess * guess)) > epsilon) begin
			guess = (guess + (r_number / guess)) / 2;	
		end
		
		result = int'(guess);
	end

endmodule
