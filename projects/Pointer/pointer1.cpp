#include <iostream>
using namespace std;

int main() {
    int a = 15;
    int *pt;
    cout << "A Variable value: " << a << endl;
    
    pt = &a;
    cout << "Pointer address: " << pt << endl;
    cout << "pt Pointer address: " << &pt << endl;
    cout << "Pointer value: " << *pt << endl;

    *pt = 31;
    cout << "New A variable value: " << a << endl;

    /* C */
    printf("a address: %p", pt);
    printf("pt pointer address: %p", &pt);

    return 0;
}