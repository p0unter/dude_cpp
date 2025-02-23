#include <array>
#include <cstdint>
#include <iostream>

int main()
{
    // Declare a variable of type std::uint32_t and assign it a value of 30
    // Address (example): F940-F943 -> Value: 30
    auto my_age = std::uint32_t{30U};

    // Print the address of my_age
    std::cout << &my_age << "\n";

    // Print the value of my_age
    std::cout << my_age << "\n";

    // Declare a pointer that stores the address of my_age
    // Address (example): F6E8 -> Stores address of my_age (F940)
    std::uint32_t *pointer_to_some_data = &my_age;

    // Print the address of the pointer itself
    std::cout << &pointer_to_some_data << "\n";

    // Modify the value of my_age through the pointer using the dereference operator (*)
    *pointer_to_some_data = 31;

    // Print the updated value of my_age
    std::cout << my_age << "\n";

    return 0; // End of program
}
