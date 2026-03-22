#include <iostream>
using namespace std;

int main() {
    int matris[3][3];
    for(int line = 0; line < 3; line++) {
        for(int column = 0; column < 3; column++) {
            cout << line + 1 << ". Line and" << column + 1 << ". Column value enter.";
            cin >> matris[line][column];
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int k = 0; k < 3; k++) {
            cout << matris[i][k] << "\t";
        }
    }
}