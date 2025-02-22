#include <iostream>
#include <cstdint>

constexpr std::uint64_t faculty(const std::uint8_t n) {
    auto result = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    const auto result1 = faculty(6);
    constexpr auto var = faculty(6);

    return 0;
}
