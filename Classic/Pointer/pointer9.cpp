#include <iostream>
#include <cstdlib>
using namespace std;

void integerController(int &number) {
    char *cp;
    char input[20];
    int temp;

    while(1) {
        cin >> input;
    
        temp = strtol(input, &cp, 10);

        if(*cp != '\0' || input == "") {
            cout << "Error!" << endl;
            continue; // again run
            cout << "Please again: ";
        }
        else {
            number = static_cast<int>(temp); // convert no required
            break; // quit
        }
        cout << number << endl;
    }
}

int main() {
    int number1, number2;
    cout << "First Number Enter: ";
    integerController(number1);

    cout << "Second Number Enter: ";
    integerController(number2);
}