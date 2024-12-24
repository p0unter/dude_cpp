#include <iostream>

using namespace std;

main() {
    FILE *fp;
    int number;

    fp = fopen("Z:\\pounter.txt", "w");
    if (fp == NULL) {
        printf("File not found.");
    } else {
        while(fscanf(fp, "%d", &number) != EOF) {
            printf("%d\n", number);
        }
    }
}