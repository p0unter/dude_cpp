#include <iostream>
using namespace std;

int collect(int *pt, int size) {
    int total = 0;
    for(int i = 0; i < size; i++) {
        total += *(pt + i);
        printf("%d : %x\n", *(pt + i), (pt + i));
    }
    return total;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};

    printf("%d", collect(numbers, 5));
}