#include <iostream>
using namespace std;

struct myData {
    int id;
    char name[20];
    char surname[20];
};


main() {
    struct myData my_data;
    cout << "Your name: ";
    cin >> my_data.name;
    
    cout << "Surname : ";
    cin >> my_data.surname;

    cout << "- - - - - - - - - -" << endl;
    cout << my_data.name << endl;
    cout << my_data.surname << endl;
}