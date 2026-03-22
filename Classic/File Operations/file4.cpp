#include <iostream>
#include <cstring>
using namespace std;

main() {
    FILE *fp;
    char text[20], cr;
    fp = fopen("text.txt", "w");
    if (fp == NULL) {
        cout << "File not found."  << endl;
    } else {
        printf("Enter text: ");
        gets(text);
        for (int i = 0; strlen(text); i++) {
            putc(text[i], fp);
        }
        fclose(fp);
    }

    fp = fopen("text.txt", "w");
    if (fp == NULL) {
        cout << "File not found."  << endl;
    } else {
        while((cr = getc(fp)) != EOF) {
            printf("%c", cr)
        }
    }
}