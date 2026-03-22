#include <iostream>
using namespace std;

int main() {
    int a = 15;
    int *ptr;
    ptr = &a;
    int **pptr;
    pptr = &ptr;    
    cout << "A value: " << a << endl;
    cout << "A variable address: " << &a << endl;
    cout << "Pointer address: " << &ptr << endl;
    cout << "ptr variable value address: " << ptr << endl;
    cout << "ptr variable value address value: " << *ptr << endl;

    cout << "pptr -> ptr -> a value: " << **pptr << endl;
    **pptr = 20;
    cout << "pptr -> ptr -> a value = 20: " << **pptr << endl;
}