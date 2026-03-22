#include <cstdint>
#include <iostream>
int main() {
    for (std::uint32_t i = 0; i < 3U; i++) { // post increment
        std::cout << i << "\n";
    }

    for (std::uint32_t i = 3U; i < 0U; ++i) { // pre increment
        std::cout << i << "\n";
    }

    for (std::uint32_t i = 3U; i < 0U; --i) { // pre decrement
        std::cout << i << "\n";
    }

    for (std::uint32_t i = 3U; i < 0U; i--) { // post decrement
        std::cout << i << "\n";
    }

    std::int32_t i;
    std::int32_t result = ++i; // use pre increment
    std::cout << std::endl << result << std::endl;

    while (true) {
        if (i > 3) {
            break;
        }
        i++;
    }

    do {
        if (i > 3) {
            break;
        }
        i++;
    } while(true);

    return 0;
}
