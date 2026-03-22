#include <iostream>
using namespace std;

void changer(char **pptr) {
    *pptr = "Dude C++";
}
int main() {
    char *text = "Pounter";
    cout << (void *)text << endl;
    cout << text << endl;
    
    changer(&text);

    cout << (void *)text << endl;
    cout << text << endl;
}