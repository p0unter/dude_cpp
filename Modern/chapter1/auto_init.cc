#include <iostream>
#include <cstdint>

int main() {
    float a = 10.0; // implicity conteverted

    std::int32_t b = a; // implicity conteverted

    auto c = static_cast<std::int32_t>(a); // explicitly converted

    // auto d = std::int32_t{a}; // uniform init
    auto e = std::int32_t{}; // uniform init

    auto f = 10 + 15.5;

    return 0;
}
