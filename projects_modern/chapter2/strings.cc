#include <array>
#include <cstdint>
#include <iostream>
#include <string>

// "Jan": String literal - known at compile time
int main()
{
    char single_chatacter = 'a'; // A single character variable of type char.

    // my_text1: A C-style string using an array of chars with a null terminator at the end.
    char my_text1[] = "Jan"; // \0 - null terminating

    // my_text2: Another C-style string using an array, explicitly adding a null terminator.
    char my_text2[] = {'J', 'a', 'n', '\0'}; // \0 - null terminating

    // my_text3: Using std::array with a fixed size, initializing with "Jan".
    auto my_text3 = std::array<char, 4>{"Jan"};

    // my_text4: Using std::string, a more modern and flexible string type in C++.
    auto my_text4 = std::string{"Jan"};

    std::cout << my_text4.size() << "\n"; // Prints the size of the string 'Jan'.

    // Appending " Schaffranek" to the string my_text4.
    my_text4.append(" Schaffranek");

    std::cout << my_text4.size() << "\n"; // Prints the new size after appending.

    // Which ones are used in modern C++?
    // my_text1 is C-style, while my_text4 is a modern C++ std::string.
    // The recommendation is to use std::string, as it is safer and more flexible.

    return 0;
}
