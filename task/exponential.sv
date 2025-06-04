module exponential #(
  parameter int ITERATIONS = 10,
)(
  input real X,
  output real result
);
  
  real sum;
  real term;
  int n;
  
  initial begin
    sum = 1.0;
    term = 1.0;
    
    for (n = 1; n < ITERATIONS; n++) begin
      term = term * X / n;
      sum = sum + term;
    end
    
    result = sum;
    $display("exp(%f) ≈ %f (using %0d Taylor terms)", X, result, ITERATIONS);
  end
  
endmodule