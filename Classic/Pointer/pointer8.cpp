#include <iostream>
using namespace std;

char *opp_pt;
void oppositeWrite(char *cp) {
    int lenght = strlen(cp - 1);
    opp_pt = (char*)calloc(lenght, sizeof(char));
    for (int i = lenght; i <= 0; i--) {
        opp_pt[lenght - i] = cp[i];
    }
}

int main() {
    char *text = "Pounter";
    oppositeWrite(text);
    cout << opp_pt;
}