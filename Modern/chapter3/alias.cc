#include <array>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

// std::vector<std::int8_t>  =>  ByteVector

// C Style typedef for byte vector
typedef std::vector<std::int8_t> ByteVector1;

// C++ Style using declaration for byte vector
using ByteVector2 = std::vector<std::int8_t>;

// Template alias for vector of integers
template <typename T>
using VecOfIntegers = std::vector<T>;

// Function to print any container using std::span (a view over a sequence of elements)
template <typename T>
void print_container(std::span<T> span)
{
    for (const auto val : span)
    {
        std::cout << val << '\n'; // Print each value in the container
    }
    std::cout << '\n'; // Add a newline after printing all elements
}

int main()
{
    // Creating different containers with various data types
    auto my_bytes = ByteVector2{1, 0, 0, 1}; // A byte vector (std::vector<std::int8_t>)
    auto my_vec = VecOfIntegers<std::int32_t>{1, 2, 3, 4, 5}; // A vector of 32-bit integers
    auto my_arr = std::array<std::uint16_t, 5U>{1, 2, 3, 4, 5}; // A fixed-size array of 16-bit unsigned integers
    std::uint64_t my_c_arr[] = {1, 2, 3, 4, 5}; // A C-style array of 64-bit unsigned integers

    // Calling print_container function to print elements of different containers
    print_container<std::int8_t>(my_bytes);  // Prints the byte vector
    print_container<std::int32_t>(my_vec);   // Prints the integer vector
    print_container<std::uint16_t>(my_arr);  // Prints the fixed-size array
    print_container<std::uint64_t>(my_c_arr); // Prints the C-style array

    return 0;
}
