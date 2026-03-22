#include <array>
#include <cstdint>
#include <iostream>

int main()
{
    // Define a constant size for a stack array
    const auto len = std::size_t{5};

    // Declare an array of 5 elements on the stack
    std::uint32_t my_array[len] = {1, 2, 3, 4, 5}; // Stack allocation

    // Declare a variable to store user input for dynamic array size
    auto len2 = std::size_t{};
    std::cin >> len2; // Get the size from the user

    // Allocate memory dynamically on the heap for len2 elements
    std::uint32_t *heap_arr = new std::uint32_t[len2];

    // Print the address of the allocated memory
    std::cout << heap_arr << '\n';

    // Check if memory allocation was successful
    if (heap_arr != nullptr)
    {
        // Initialize the array with index values
        for (std::size_t i = 0; i < len2; i++)
        {
            heap_arr[i] = static_cast<std::uint32_t>(i);
        }

        // Print the elements of the heap array
        for (std::size_t i = 0; i < len2; i++)
        {
            std::cout << heap_arr[i] << '\n';
        }
    }

    // Free the dynamically allocated memory
    delete[] heap_arr;
    heap_arr = nullptr; // Set the pointer to nullptr to avoid dangling pointer

    // Checking pointer validity
    if (heap_arr)
    {
        // This is unsafe because memory has already been freed
        std::cout << heap_arr[1];
    }

    if (!heap_arr)
    {
        // Expected output after memory deallocation
        std::cout << "Invalid Ptr!\n";
    }

    return 0;
}
