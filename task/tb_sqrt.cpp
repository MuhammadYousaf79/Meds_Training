#include <cmath>
#include <cstdio>
#include "Vsqrt.h"
#include "verilated.h"

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // Create instance of the module
    Vsqrt* dut = new Vsqrt;
    
    // Test cases: {input, expected} (expected calculated with std::sqrt)
    const std::pair<uint32_t, uint32_t> test_cases[] = {
        {0, 0},               // sqrt(0) = 0
        {1, 1},               // sqrt(1) = 1
        {4, 2},               // sqrt(4) = 2
        {25, 5},              // sqrt(25) = 5
        {100, 10},            // sqrt(100) = 10
        {2, 1},               // sqrt(2) ≈ 1 (integer result)
        {10, 3},              // sqrt(10) ≈ 3 (integer result)
        {65536, 256},         // sqrt(65536) = 256
        {123456789, 11111}    // sqrt(123456789) ≈ 11111
    };
    
    printf("Testing square root module (epsilon = 0.00001):\n");
    printf("%-15s %-15s %-15s %-10s\n", "Input", "Expected", "Actual", "Error(%)");
    printf("--------------------------------------------------------\n");
    
    for (const auto& test : test_cases) {
        // Set input value
        dut->number = test.first;
        
        // Evaluate
        dut->eval();
        
        // Get result
        uint32_t actual = dut->result;
        uint32_t expected = test.second;
        double error = (actual != expected) ? 
            std::abs((static_cast<double>(actual) - expected) / expected) * 100 : 0.0;
        
        // Print results
        printf("%-15u %-15u %-15u %-10.4f\n", 
               test.first, expected, actual, error);
    }
    
    // Additional test for verification
    printf("\nDetailed verification test:\n");
    printf("Input\tExact\t\tModule\t\tDifference\n");
    printf("--------------------------------------------\n");
    for (uint32_t i = 0; i <= 20; i++) {
        dut->number = i;
        dut->eval();
        double exact = std::sqrt(i);
        printf("%u\t%-15.8f %-15u %-15.8f\n", 
               i, exact, dut->result, exact - dut->result);
    }
    
    // Clean up
    delete dut;
    return 0;
}