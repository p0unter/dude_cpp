#include <iostream>
#include <cstdlib>

using namespace std;

struct Write {
    double n1;
    double n2;
};

void writeSpace(Write &wte) {
    cout << "Number 1: ";
    cin >> wte.n1;

    cout << "Number 2: ";
    cin >> wte.n2;

    cout << "Result: ";
}

double calcCollection(Write &wte) {
    writeSpace(wte);

    return wte.n1 + wte.n2;
}

double calcExtraction(Write &wte) {
    writeSpace(wte);

    return wte.n1 - wte.n2;
}

double calcImpact(Write &wte) {
    writeSpace(wte);

    return wte.n1 * wte.n2;
}

double calcDivide(Write &wte) {
    writeSpace(wte);

    return wte.n1 / wte.n2;
}

main() {
    Write wte = {0, 0};

    int choice = 0;
    while (choice != 5)
    {
        cout << "----BASIC CALCULATOR----" << endl;
        cout << "1.\t" << "Collection" << endl;
        cout << "2.\t" << "Extraction" << endl;
        cout << "3.\t" << "Impact" << endl;
        cout << "4.\t" << "Divide" << endl;
        cout << "5.\t" << "Exit" << endl;
        cout << "------------------------\n" << endl;

        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << calcCollection(wte) << endl;
                break;
            case 2:
                cout << calcExtraction(wte) << endl;
                break;
            case 3:
                cout << calcImpact(wte) << endl;
                break;
            case 4:
                cout << calcDivide(wte) << endl;
                break;
            default:
                system("cls");
                cout << "Error!" << endl;
        }
    }
    
}