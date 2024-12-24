#include "calculator.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    Write wte = {0, 0};
    int choice = 0;

    while (choice != 5) {
        cout << "----BASIC CALCULATOR----" << endl;
        cout << "1.\tCollection" << endl;
        cout << "2.\tExtraction" << endl;
        cout << "3.\tImpact" << endl;
        cout << "4.\tDivide" << endl;
        cout << "5.\tExit" << endl;
        cout << "------------------------\n" << endl;

        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Result: " << calcCollection(wte) << endl;
                break;
            case 2:
                cout << "Result: " << calcExtraction(wte) << endl;
                break;
            case 3:
                cout << "Result: " << calcImpact(wte) << endl;
                break;
            case 4:
                cout << "Result: " << calcDivide(wte) << endl;
                break;
            case 5:
                cout << "Exiting the calculator." << endl;
                break;
            default:
                cout << "Error! Please enter a valid option." << endl;
        }
        cout << endl;
    }
    return 0;
}