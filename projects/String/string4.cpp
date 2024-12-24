#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

main() {
    char str[] = "Pounter";
    char *ptr;
    ptr = strchr(str, 'r');
    printf("%x\n", ptr);
    printf("%s\n", ptr);
    
    char *ptr2;
    ptr2 = strstr(str, "Pounter");
    printf("%x\n", ptr2);
    printf("%s\n", ptr2);

    int location;
    location = strcspn(str, "otr");
    printf("%d\n", location);
}