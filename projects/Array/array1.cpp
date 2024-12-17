#include <iostream>
using namespace std;

int main() {
    int result;
    int array1[5];
    for(int i = 0; i < 5; i++) {
        cout << "Number" << i+1 << ": ";
        cin >> array1[i];
    }
    for(int i = 0; i < 5; i++) {
        result += array1[i];
    }
    result /= 5;
    cout << "\nResult: " << result << endl;
    for(int i = 0; i < 5; i++) {
        cout << " |" << i+1 << ": " << array1[i] << "| ";
    }
}