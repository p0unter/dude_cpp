#include <iostream>
#include <vector>
using namespace std;

vector<int> control(vector<int> numbers) {
    
    vector<int> temp;

    for (int i = 1; i < numbers.size() - 1; i++) {
        if (numbers[i] < numbers[i-1] < numbers[i+1]) {
            temp.push_back(numbers[i]);
        }
    }
    return temp;
}

main() {
    vector<int> numbers = {10, 5, 7, 12, 3, 1, 37, 56};

    cout << "Before: " << endl;

    for (auto content : numbers) {
        cout << content << endl;
    }

    cout << "After: " << endl;
    vector<int> new_numbers = control(numbers);
    for(auto content : new_numbers){
        cout << content << endl;
    }
}