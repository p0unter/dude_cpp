#include <iostream>
#include <iterator>
#include <vector>

// Function to print all values of the vector
template <typename T>
void print_vector(const std::vector<T> &vec)
{
    std::cout << "Printing vectors values:\n";
    for (const auto v : vec)
    {
        std::cout << v << '\n'; // Print each value
    }
    std::cout << '\n';
}

int main()
{
    auto my_vector = std::vector{0, 1, 2, 3, 4, 5}; // Initialize a vector with values from 0 to 5

    // ForwardIterator: Iterating from the beginning to the end
    auto it1 = my_vector.begin();  // Iterator pointing to the first element
    auto it2 = my_vector.end();    // Iterator pointing past the last element

    // Modify each element using the forward iterator
    for (; it1 != it2; ++it1)
    {
        *it1 = 1; // Set each element to 1
    }
    print_vector(my_vector); // Print the modified vector

    // BidirectionalIterator: Iterating from the end to the beginning
    auto it3 = my_vector.rbegin(); // Reverse iterator pointing to the last element
    auto it4 = my_vector.rend();   // Reverse iterator pointing past the first element

    // Modify each element using the bidirectional iterator
    for (; it3 != it4; ++it3)
    {
        *it3 = 2; // Set each element to 2
    }
    print_vector(my_vector); // Print the modified vector

    // Const ForwardIterator: Cannot modify the vector, but can read the elements
    auto it5 = my_vector.cbegin(); // Const iterator pointing to the first element
    auto it6 = my_vector.cend();   // Const iterator pointing past the last element

    // Const BidirectionalIterator: Cannot modify the vector, but can read the elements
    auto it7 = my_vector.crbegin(); // Const reverse iterator
    auto it8 = my_vector.crend();   // Const reverse iterator

    // Using std::advance to move the iterator
    auto vec_it = my_vector.begin(); // Point to the first element
    std::advance(vec_it, 2);         // Move the iterator 2 steps forward
    std::cout << "Vector[2] = " << *vec_it << '\n'; // Print the element at index 2

    // Using std::distance to calculate the number of steps between two iterators
    auto dist1 = std::distance(vec_it, my_vector.end()); // Distance from vec_it to the end
    auto dist2 = std::distance(my_vector.begin(), vec_it); // Distance from the beginning to vec_it
    std::cout << "Dist1: " << dist1 << " Dist2: " << dist2 << '\n';

    // Using std::prev and std::next to move the iterator backward and forward
    auto prev = std::prev(vec_it); // Move the iterator one step backward
    std::cout << "Prev Value: " << *prev << '\n';
    auto next = std::next(vec_it); // Move the iterator one step forward
    std::cout << "Next Value: " << *next << '\n';

    return 0;
}
