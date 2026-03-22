// ARRAY COPY

#include <iostream>
using namespace std;

int main() {
    int number1[] = {15, 26, 32, 72};
    int number2[4];

    /*
    for (int i = 0; i < 4; i++)
        number2[i] = number1[i];
    for (int i = 0; i < 4; i++)
        cout << number1[i] << endl;
    */
    
    cout << sizeof(number1) << endl;
    memcpy(number2, number1, sizeof(number1));

    return 0;
}