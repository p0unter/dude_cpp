#include <iostream>

enum class Status {
    Unkown,
    Connected,
    Disconnected
};

enum class UserPremission {
    Unkown,
    User,
    Admin
};

// POD
struct User
{
    Status status;
    std::uint64_t id;
};

int main() {
    // User user1 = {Status::Connected, 10U};
    User user1 = {.status = Status::Connected, .id = 42U}; // C++ v20

    std::cout << user1.id << std::endl;

    std::cout << (std::int32_t)user1.status << std::endl;
    std::cout << static_cast<std::int32_t>(user1.status) << std::endl;

    return 0;
}
