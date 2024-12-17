#include <stdio.h>

int main() {
    char characters[] = {'P', 'O', 'U', 'N', 'T', 'E', 'R'};
    char simpleCH[] = "POUNTER";

    printf("Chars: %s\n", characters);
    printf("String: %s\n", simpleCH);

    for(int i = 0; i < 7; i++)
        printf("%c\n", simpleCH[i]);

    return 0;
}