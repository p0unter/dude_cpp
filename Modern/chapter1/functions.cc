#include <cstdint>
#include <iostream>

// declaration
// definiton

void my_print_function(); // mandatory or make definitions here

int main() {
    my_print_function(); // func. call

    return 0;
}

// func. definiton
void my_print_function() {
    std::cout << "Hello World! \n";
}
