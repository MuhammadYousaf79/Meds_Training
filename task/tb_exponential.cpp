#include <cmath>
#include <cstdio>
#include "Vexponential.h"
#include "verilated.h"

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // Create instance of the module
    Vexponential* dut = new Vexponential;
    
    // Test cases: {input, expected} (expected calculated with std::exp)
    const std::pair<double, double> test_cases[] = {
        {0.0, 1.0},          // e^0 = 1
        {1.0, M_E},          // e^1 ≈ 2.71828
        {2.0, std::exp(2.0)}, // e^2 ≈ 7.38906
        {-1.0, 1.0/M_E},     // e^-1 ≈ 0.36788
        {0.5, std::exp(0.5)}, // e^0.5 ≈ 1.64872
        {3.0, std::exp(3.0)}  // e^3 ≈ 20.0855
    };

    printf("%-10s %-15s %-15s %-10s\n", "Input", "Expected", "Actual", "Error(%)");
    printf("------------------------------------------------\n");
    
    for (const auto& test : test_cases) {
        // Set input value
        dut->X = test.first;
        
        // Reset and evaluate
        dut->eval();
        
        // Get result
        double actual = dut->result;
        double expected = test.second;
        double error = std::abs((actual - expected) / expected) * 100;
        
        // Print results
        printf("%-10.4f %-15.8f %-15.8f %-10.4f\n", 
               test.first, expected, actual, error);
    }
    
    // Clean up
    delete dut;
    return 0;
}
