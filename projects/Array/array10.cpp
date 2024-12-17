#include <iostream>
using namespace std;

int main() {
    int matrisA[2][3] = {{1,23,}, {4,5,6}};
    int matrisB[3][2] = {{1,2}, {3,4}, {5,6}};
    int matrisC[2][2];
    for(int line = 0; line < 2; line++) {
        for(int column = 0; column < 2; column++) {
            matrisC[line][column] = 0;
            for(int k = 0; k < 3; k++){
                matrisC[line][column] += matrisA[line][k] * matrisB[k][column];
            }
        }
    }
    for(int line = 0; line < 2; line++) {
        for(int column = 0; column < 2; column++) {
            cout << matrisC[line][column] << "\t";
        }
        cout << endl;
    }
}