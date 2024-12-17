#include <iostream>
using namespace std;

int total(int number[], int size) {
    int collect = 0;
    for(int i = 0; i < size; i++)
        collect += number[i];
    return collect;
}

int main() {
    int collect;
    int numbers[] = {32, 12, 45, 43, 32, 78};
    collect = total(numbers, 6);

    return 0;
}