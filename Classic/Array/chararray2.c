#include <stdio.h>

int main() {
    int array1[20];

    /*
    printf("Name & Surname: ");
    // scanf("%s", array1);
    gets(array1);
    printf("%s\n", array1);
    */

    int array2[3][15] = {"Ahmet", "Mehmet", "Veli"};

    printf("%s\n", array2[0][0]); // Result: A
    printf("%s\n", array2[1]); // Result: Ahmet
    for(int i = 0; i < 3; i++)
        printf("%s\n", array2[i]);
    
    int array3[3][15];

    for(int i = 0; i < 3; i++) {
        printf("%d - Enter name: ", i);
        gets(array3[i]);
    }
    for(int i = 0; i < 3; i++)
        printf("%s", array3[i]);
    
    return 0;
}