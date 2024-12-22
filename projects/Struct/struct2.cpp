#include <iostream>
#include <cstring>
using namespace std;

struct customerData {
    int customer_id;
    char customer_name[20];
    char customer_surname[20];
};

main() {
    struct customerData cr_data[3];
    
    for (int i = 0; i < 3; i++) {
        cin >> cr_data[i].customer_id;
        cin >> cr_data[i].customer_name;
        cin >> cr_data[i].customer_surname;
    }

    char customer_name[20];
    cout << "Customer Name: ";
    cin >> customer_name;
    for (int i = 0; i < 3; i++) {
        if (strcmp(customer_name, cr_data[i].customer_name) == 0) {
            cout << cr_data[i].customer_id << cr_data[i].customer_name << cr_data[i].customer_surname << endl;
        }
    }
}