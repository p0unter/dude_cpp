#include <iostream>

using namespace std;

/*
"w":        Used to open a new file and write data into it.
"r":        Opens the file in read mode.
"a":        Opens the file in append mode.

"w+":       Opens the file in write mode, can also read.
"r+":       Opens the file in read mode, can also write.
"a+":       Opens the file in append mode, can also read.

fopen()     Creates and opens a file.
fclose()    Closes the file.
putc()      Writes a character to the file.
getc()      Reads a character from the file.
feof()      Checks if the end of the file has been reached.
fprintf()   Writes formatted data to the file.
fscanf()    Reads formatted data from the file.
*/

int main() {
    FILE *fp;
    int number;

    /* File creation 
    fopen("D:\\mypath\\pounter.txt", "w");
    */
    fopen("pounter.txt", "w"); // For this path

    /* ERROR CATCHING */
    fp = fopen("Z:\\pounter.txt", "w");
    if (fp == NULL) {
        printf("Driver not found!");
    } else {
        for (int i = 0; i < 5; i++) {
            printf("%d. Number enter: ", i+1);
            scanf("%d", &number);
            fprintf(fp, "%d\n", number);
        }
    }
}