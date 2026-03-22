#include <iostream>
using namespace std;

int main() {
    int numbers[4][5] = {
        {56, 78, 65, 90, 85}, 
        {45, 56, 45, 75, 80},
        {90, 95, 70, 85, 90}
    };
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            cout << numbers[i][j] << "\t";
        }
        cout << endl;
    }
}