#include <iostream>
using namespace std;

// First Method: void changer(int &a, int &b)
void changer(int *a, int *b){
    int temp;
    /* First Method:
    temp = a; 
    a = b;
    b = temp;
    */
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5, b = 7;

    cout << a << "\t" << endl;
    // First Method: changer(a, b);
    changer(&a, &b);
    cout << a << "\t" << endl;

    return 0;
}