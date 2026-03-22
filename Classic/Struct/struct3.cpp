#include <iostream>
using namespace std;

struct myStruct {
    string name;
    int x;
    int y;
};

myStruct update(myStruct a) {
    a.name = "Popo";
    a.x = 5;
    a.y = 2;
    return a;
}

main() {
    myStruct m1 = { "Pounter", 15, 25 };
    cout << m1.x << endl;
    cout << m1.y << endl;

    myStruct m2 = update(m2);
    cout << m2.x << endl;
    cout << m2.y << endl;
}