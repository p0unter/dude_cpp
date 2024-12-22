#include <iostream>
#include <vector>
using namespace std;

// VECTOR & POINTER

void calculator(vector<int>& numbers) {
    for(int i = 0; i < numbers.size(); i++) {
        numbers[i] *= 10;
        cout << numbers[i] << endl;
    }
}

main() {
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    calculator(numbers);
}