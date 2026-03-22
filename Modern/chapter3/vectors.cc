#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    // Empty vector
    auto my_vec_empty = std::vector<std::int32_t>{};
    // Vector with initial values
    auto my_vec = std::vector<std::int32_t>{1, 2, 3, 4, 5};

    // C-style loop for value lookup
    std::cout << "\nC-Style Loop: \n";
    for (std::size_t i = 0; i < my_vec.size(); i++)
    {
        std::cout << my_vec[i] << '\n';
    }

    // C++ range-based for loop
    std::cout << "\nC++ Ranged For Loop: \n";
    for (const auto value : my_vec) // read only
    {
        std::cout << value << '\n';
    }

    // Modify vector elements
    for (auto &value : my_vec) // write and read
    {
        value *= 2; // Double the value
    }

    // Print modified vector
    for (const auto value : my_vec) // read only
    {
        std::cout << value << '\n';
    }

    // Vector initialized with 0s
    auto my_vec2 = std::vector<std::int32_t>(3, 0); // init 3 elements with 0
    std::cout << "\nZero init 3 Elements: \n";
    for (const auto value : my_vec2) // read only
    {
        std::cout << value << '\n';
    }

    // Add elements to the vector
    auto my_vec3 = std::vector<std::int32_t>{};
    my_vec3.push_back(10);
    my_vec3.push_back(22);
    std::cout << "\nPushed 10 and 22 to the vector: \n";
    for (const auto value : my_vec3) // read only
    {
        std::cout << value << '\n';
    }

    // Remove last element
    my_vec3.pop_back();
    std::cout << "\nRemoved the last element: \n";
    for (const auto value : my_vec3) // read only
    {
        std::cout << value << '\n';
    }

    // Using iterators with begin and end
    auto it_begin = my_vec2.begin(); // points to the first element
    auto it_end = my_vec2.end();     // points after the last element
    std::cout << "\nUsing Begin and End Iterators: \n";
    for (it_begin; it_begin != it_end; it_begin++)
    {
        std::cout << *it_begin << '\n';
    }

    // Insert an element at a specific position
    my_vec2.insert(my_vec2.begin() + 1, 100);
    std::cout << "\nInserted 100 at index 3: \n";
    for (const auto value : my_vec2) // read only
    {
        std::cout << value << '\n';
    }

    return 0;
}
