#include <array>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

// Function to print the elements of a span
void print_span(std::span<std::int32_t> span)
{
    for (const auto value : span) // Iterate through the span and print each element
    {
        std::cout << value << '\n';
    }
}

// Main function
int main()
{
    // Create a vector of integers
    auto vec = std::vector<std::int32_t>{1, 2, 3};
    print_span(vec); // Pass vector as a span to the print function

    // Create an array of integers
    auto arr = std::array<std::int32_t, 3>{1, 2, 3};
    print_span(arr); // Pass array as a span to the print function

    return 0;
}
