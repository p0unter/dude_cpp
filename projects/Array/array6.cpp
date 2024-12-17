// BUBBLE SORT
#include <iostream>
using namespace std;

int main() {
    int temp;
    int array1[] = {15, 7, 35, 65, 75, 40, 50, 46, 74, 56};

    for(int i = 0; i < 10; i++) {
        for (int i = 0; i < 9; i++) {
            if(array1[i] > array1[i + 1]){
                temp = array1[i];
                array1[i] = array1[i+1];
                array1[i+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < 10; i++)
        cout << array1[i] << endl;

    return 0;
}