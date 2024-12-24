#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

main() {
    char name[20] = "Pounter";
    char password[20    ] = "12345";

    char temp_name[20], temp_password[20];
    cout << "Name: ";
    cin >> temp_name;
    cout << "Password: ";
    cin >> temp_password;

    if (strcmp(name, temp_name) == 0 && strcmp(password, temp_password) == 0) {
        cout << "Correct!" << endl;
    } else {
        cout << "Error!" << endl;
    }
}