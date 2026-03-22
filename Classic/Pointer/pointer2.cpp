#include <iostream>
using namespace std;

int main() {
    /* INT: 4byte DOUBLE: 8byte
    double numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    */

    int numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    /* NO POINTER USE
    for(int i = 0; i < 10; i++) {
        cout << &numbers[i] << "-->" << numbers[i] << endl; 
    }
    */
    
    int *spt;
    spt = numbers;
    for(int i = 0; i < 10; i++) {
        /* *spt = ram address, *(spt + 1) address + 4byte = last item. */
        /* cout << *(spt += 1) << endl; (first use) */
        cout << spt[i] << "-->" << &spt[i] << endl; // (second use)
    }

    return 0;
}