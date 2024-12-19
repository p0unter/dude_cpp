#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[] = "Ali";
    /*
    printf("Byte size: %d", sizeof(name));
    printf("Character number: %d", strlen(name));
    */

    char *pt;
    pt = name; // array first item ram address value

    // printf("%c", pt); // Ali
    // printf("%c", pt[0]); // A

    /* Arithmatic */
    printf("%c", *(pt + 1)); // l
    /* or
    pt++;
    printf("%c", *pt); // but now pt variable change
    */

    return 0;
}