#include <array>
#include <cstdint>
#include <iostream>

// Function to print the values of a std::array
// Takes a constant reference to avoid modifying the original array
// Uses only 8 bytes for the reference, making it efficient
template <std::size_t N>
void print_array_values(const std::array<std::uint32_t, N> &arr)
{
    for (std::size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << '\n'; // Print each element
    }
}

// Function to double the values of a std::array
// Takes a reference without const, allowing modification of the array
// Modifies the input array directly
template <std::size_t N>
void double_value(std::array<std::uint32_t, N> &arr)
{
    for (std::size_t i = 0; i < arr.size(); i++)
    {
        arr[i] = arr[i] * 2; // Double each element
    }
}

int main()
{
    // Declare and initialize a std::array with 5 elements
    auto my_array = std::array<std::uint32_t, 5U>{1, 2, 3, 4, 5};

    // Print the original array values
    print_array_values(my_array);

    // Double each value in the array
    double_value(my_array);

    // Print the modified array values
    print_array_values(my_array);

    return 0; // End program
}
