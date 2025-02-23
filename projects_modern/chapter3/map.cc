#include <cstdint>
#include <iostream>
#include <map>

// Function to print map contents (key-value pairs)
void print_map(const std::map<std::string, std::int32_t> &map)
{
    for (const auto &[key, val] : map)
    {
        std::cout << key << ": " << val << '\n'; // Print each key-value pair
    }

    std::cout << '\n'; // Print a newline after printing all elements
}

int main()
{
    // Create a map with initial key-value pair ("Jan", 28)
    auto my_map = std::map<std::string, std::int32_t>{{"Jan", 28}};

    // If the key does not exist, it will be added
    my_map["Sam"] = 40;  // Add "Sam" with value 40
    my_map["Veronika"] = 24; // Add "Veronika" with value 24

    // Print the map after adding new elements
    print_map(my_map);

    // If the key does exist, it will be overridden
    my_map["Veronika"] = 25; // Update "Veronika" to 25

    // Print the map after updating a value
    print_map(my_map);

    // Check if "Sam" exists, if not, add it
    if (!my_map.contains("Sam"))
    {
        my_map["Sam"] = 40;
    }
    // Check if "Lisa" exists, if not, add it
    if (!my_map.contains("Lisa"))
    {
        my_map["Lisa"] = 36; // Add "Lisa" with value 36
    }

    // Print the map after checking and adding values
    print_map(my_map);

    // Search for "Lisa" in the map and print the key if found
    const auto it_find = my_map.find("Lisa"); // Find the iterator for "Lisa"
    if (it_find != my_map.end()) // If "Lisa" exists
    {
        std::cout << (*it_find).first << '\n'; // Print the key of the found element
    }

    return 0;
}
