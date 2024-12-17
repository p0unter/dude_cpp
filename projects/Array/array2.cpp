#include <iostream>
using namespace std;

int main() {
    string text = "Pounter";
    string student[] = { "Ahmet", "Veli", "Mehmet" };
    string names[10];

    for(int i = 0; i < 3; i++) {
        cout << "Enter name & username (separated by space): ";
        cin.ignore();
        getline(cin, names[i]);
    }

    cout << "\nEntered Names and Usernames:\n";
    for(int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << names[i] << endl;
    }

    return 0;
}