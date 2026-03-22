#include <array>
#include <cstdint>
#include <iostream>

// Function to print values of a C-style array
// C-style arrays decay to pointers when passed to functions
void print_array_values1(const std::uint32_t *my_array, const std::uint32_t len)
{
    for (std::uint32_t i = 0; i < len; i++)
    {
        std::cout << my_array[i] << "\n"; // Print each element
    }
}

// Function to print values of a C++-style std::array
// Uses a template to handle arrays of any size
template <std::size_t N>
void print_array_values2(const std::array<std::uint32_t, N> my_array)
{
    for (std::size_t i = 0; i < my_array.size(); i++)
    {
        std::cout << my_array[i] << "\n"; // Print each element
    }
}

int main()
{
    // Define a constant size for the arrays
    constexpr auto len = 5U;

    // Declare and initialize a C-style array
    std::uint32_t my_array[len] = {1, 2, 3, 4, 5}; // C-style array
    print_array_values1(my_array, len); // Pass to function

    // Declare and initialize a std::array (C++ style)
    auto my_array2 = std::array<std::uint32_t, len>{6, 7, 8, 9, 10};
    print_array_values2(my_array2); // Pass to function

    return 0; // End program
}
