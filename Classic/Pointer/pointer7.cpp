#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int *p;
    p = (int *)calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++) {
        p[i] = i;
    }
    p = (int *)realloc(p, 10 * sizeof(int));
    for (int i = 10; i < 20; i++) {
        p[i] = i;
    }
}