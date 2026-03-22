#include <array>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>

// Template function to print the elements of any container as a span
template <typename T>
void print_container(std::span<T> span)
{
    for (const auto val : span) // Iterate through the span and print each value
    {
        std::cout << val << '\n';
    }
}

int main()
{
    // Create a vector of int32_t
    auto my_vec = std::vector<std::int32_t>{1, 2, 3, 4, 5};
    // Create an array of uint16_t
    auto my_arr = std::array<std::uint16_t, 5U>{1, 2, 3, 4, 5};
    // Create a C-style array of uint64_t
    std::uint64_t my_c_arr[] = {1, 2, 3, 4, 5};

    // Print elements of the vector (int32_t)
    print_container<std::int32_t>(my_vec);
    // Print elements of the array (uint16_t)
    print_container<std::uint16_t>(my_arr);
    // Print elements of the C-style array (uint64_t)
    print_container<std::uint64_t>(my_c_arr);

    return 0;
}
