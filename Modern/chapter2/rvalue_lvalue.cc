#include <iostream>

// Function that copies the value (pass-by-value)
// The parameter v is a copy of the argument, so changes do not affect the original variable
void copy_by_value(int v) // Input only
{
    std::cout << v << std::endl;
}

// Function that copies the value but prevents modification inside the function (const pass-by-value)
void copy_by_value_const(const int v) // Input only, cannot modify v
{
    std::cout << v << std::endl;
}

// Function that takes a reference (pass-by-reference)
// Modifications to v will affect the original variable
void reference(int &v) // Input and output (modifiable reference)
{
    std::cout << v << std::endl;
}

// Function that takes a const reference (pass-by-const-reference)
// The original value cannot be modified
void reference_const(const int &v) // Input only (constant reference)
{
    std::cout << v << std::endl;
}

int main()
{
    int lvalue = 2;              // Regular (modifiable) variable
    const int lvalue_const = 2;  // Constant variable (cannot be modified)

    // Call functions with different parameter passing methods
    copy_by_value(lvalue);        // Pass by value (copy of lvalue)
    copy_by_value(lvalue_const);  // Pass by value (copy of lvalue_const)
    copy_by_value(2);             // Pass by value (temporary value)

    copy_by_value_const(lvalue);  // Pass by const value (copy of lvalue)
    copy_by_value_const(lvalue_const); // Pass by const value (copy of lvalue_const)
    copy_by_value_const(2);       // Pass by const value (temporary value)

    reference(lvalue);            // Pass by reference (modifies original variable)
    // reference(lvalue_const);  // Error: Cannot pass a const variable as a non-const reference
    // reference(2);             // Error: Cannot pass a temporary value as a non-const reference

    reference_const(lvalue);      // Pass by const reference (read-only)
    reference_const(lvalue_const);// Pass by const reference (read-only)
    reference_const(2);           // Pass by const reference (temporary value is valid)

    return 0; // End of program
}
