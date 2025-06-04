module exponential (
  input real X,
  output real result
);
  
  real sum;
  real term;
  int n;
  int ITERATIONS = 10;
  
  always_comb begin
    sum = 1.0;
    term = 1.0;
    
    for (n = 1; n < ITERATIONS; n++) begin
      term = term * X / n;
      sum = sum + term;
    end
    
    result = sum;
    $display("exp(%f) ≈ %f", X, result);
  end
endmodule
