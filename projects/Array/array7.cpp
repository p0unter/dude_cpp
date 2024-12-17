#include <iostream>
using namespace std;

int main() {
    int min_variable, temp;
    int array1[] = {15, 89, 35, 65, 75, 72, 7, 92, 23, 3};
    
    for (int i = 0; i < 10; i++) {
        min_variable = array1[0];
        for(int j = i + 1; j < 10; j++) {
            if (min_variable > array1[j]) {
                min_variable = array1[j];
                temp = array1[j];
                array1[i] = array1[j];
                array1[j] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
        cout << array1[i] << endl;
    
    return 0;
}