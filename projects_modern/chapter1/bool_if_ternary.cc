#include <iostream>
#include <cstdint>
int main() {
    bool b1 = true;
    bool b2 = false;

    if (b1) {
        std::cout << "Printy \n";
    }
    else if (!b2) {

    }
    else {

    }

    std::int32_t result;

    if (b1) {
        result = 10;
    }
    else {
        result = -10;
    }

    std::int32_t result_2 = b1 ? 10 : -10; // ternary op.

    return 0;
}
