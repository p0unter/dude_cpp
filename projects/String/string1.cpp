#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    char date[] = "1983whatifstring";
    int date2;
    date2 = atoi(date); // Convert integer
    date2 += 10;
    cout << date2 << endl;

    char dateD[] = "1983.25whatifstring";
    double date2D;
    date2D = atof(dateD); // Convert double
    date2D += 10;
    cout << date2D << endl;

    char dateL[] = "1983.25whatifstring";
    long int date2L;
    char *ptrLong;
    date2L = strtol(dateL, &ptrLong, 10); // Long (Binary)
    date2L += 10;
    cout << date2L << endl;

    char dateS[] = "1983.25whatifstring";
    double date2S;
    char *ptrTxt;
    date2S = strtod(dateS, &ptrTxt); // Take string dataa
    cout << date2S << endl;
    cout << ptrTxt << endl;
}
