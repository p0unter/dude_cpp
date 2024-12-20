#include <iostream>
using namespace std;

void updateVariable(int **pptr) {
    **pptr = 15;
}

int main() {
    int a = 15;
    int *ptr = &a;

    cout << "A variable value: " << a << endl;
    updateVariable(&ptr);
    cout << "Update a value: " << a << endl;    
}