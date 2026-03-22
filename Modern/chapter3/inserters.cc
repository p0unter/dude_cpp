#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    // Create a vector with elements from 0 to 5
    const auto my_vector = std::vector{0, 1, 2, 3, 4, 5};

    // Two result vectors to hold copied elements
    auto my_result1 = std::vector<int>{-1, -2};
    auto my_result2 = std::vector<int>{11, 12};

    // Using std::inserter to insert elements of my_vector at the beginning of my_result1
    std::copy(my_vector.begin(),
              my_vector.end(),
              std::inserter(my_result1, std::next(my_result1.begin()))); // Inserts at the second position
    for (const auto val : my_result1)
        std::cout << val << " "; // Print all elements of my_result1
    std::cout << '\n';
    my_result1.clear(); // Clear my_result1 after printing

    // Using std::back_inserter to append elements of my_vector to the end of my_result2
    std::copy(my_vector.begin(),
              my_vector.end(),
              std::back_inserter(my_result2)); // Appends elements at the end
    for (const auto val : my_result2)
        std::cout << val << " "; // Print all elements of my_result2
    std::cout << '\n';
    my_result2.clear(); // Clear my_result2 after printing

    return 0;
}
