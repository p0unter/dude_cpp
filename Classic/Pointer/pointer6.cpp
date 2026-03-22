#include <iostream>
using namespace std;

char *search(char *p, char cr){
    while(*p != '\0') {
        if (*p == cr) {
            return p;
        }
        p++;
    }
}

int main() {
    char text[] = "Pounter";
    char *pt = search(text, 'm');

    if (pt) {
        printf("%x\n", pt);
    } else {
        printf("No character\n");
    }
    printf("%x, %c", (pt + 1), *(pt + 1));
}