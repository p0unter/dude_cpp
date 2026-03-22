#include <iostream>

using namespace std;

main() {
    FILE *fp;
    int number;

    fp = fopen("Z:\\pounter.txt", "a"); // a: append
    if (fp == NULL) {
        printf("File not found.");
    } else {
        for (int i = 0; i < 3; i++) {
            printf("%d. Number enter: ", i++);
            scanf("%d", &number);
            fprintf(fp, "%d", number);
        }
    }

    fclose(fp);
}