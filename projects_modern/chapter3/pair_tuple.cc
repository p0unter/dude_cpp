#include <cstdint>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>

// Define a struct DataBlaBla with two members: an integer and a float
struct DataBlaBla
{
    std::int32_t i;
    float j;
};

// Function that returns a tuple with an integer, a string, and a float
std::tuple<std::int32_t, std::string, float> some_functions(const std::int32_t input)
{
    return std::make_tuple(input + 1,              // First element: integer
                           std::to_string(input + 2), // Second element: string
                           static_cast<float>(input + 3)); // Third element: float
}

// Function that returns a struct with an integer and a float
DataBlaBla some_functions2(const std::int32_t input)
{
    return DataBlaBla{input + 1, static_cast<float>(input + 3)};
}

int main()
{
    // Create a pair with an integer and a float
    auto my_pair = std::pair<std::int32_t, float>{1337, 42.0F};
    std::cout << my_pair.first << '\n';  // Print the first element (integer)
    std::cout << my_pair.second << '\n'; // Print the second element (float)

    // Create a tuple with an integer, a float, and a string
    auto my_tuple = std::tuple<std::int32_t, float, std::string>{1337, 42.0F, "Jan"};
    std::cout << std::get<0>(my_tuple) << '\n'; // Print the first element (integer)
    std::cout << std::get<1>(my_tuple) << '\n'; // Print the second element (float)
    std::cout << std::get<2>(my_tuple) << '\n'; // Print the third element (string)

    // Call some_functions and print the returned tuple elements
    const auto result = some_functions(42);
    std::cout << std::get<0>(result) << '\n'; // Print the first element (integer)
    std::cout << std::get<1>(result) << '\n'; // Print the second element (string)
    std::cout << std::get<2>(result) << '\n'; // Print the third element (float)

    // Using Structured Binding to directly unpack the tuple
    const auto &[i, s, f] = some_functions(42);
    std::cout << i << '\n'; // Print the first element (integer)
    std::cout << s << '\n'; // Print the second element (string)
    std::cout << f << '\n'; // Print the third element (float)

    // Call some_functions2 and unpack the struct into its members
    const auto &[i1, f1] = some_functions2(42); // Unpack the struct
    // i1 and f1 can be used directly here (e.g., print values)

    return 0;
}
