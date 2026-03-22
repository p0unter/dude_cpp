#include <iostream>
#include <vector>
using namespace std;

// We need C++ Compiler 14 version. Otherwise you may get an error.
int main() {
    vector<int> vec1;
    cout << vec1.size() << endl;

    vector<int> vec2(5); // Min 5 limited
    cout << vec2.size() << endl;

    vector<char> vec3 = { 'A', 'B', 'C' }; // C++ Compiler 14 version
    cout << vec3.size() << endl;

    vector<double> vec4(5, 3.14);
    cout << vec4.size() << endl;
    vector<double> vec5(vec4);
    cout << vec5.size() << endl;

    for(int i = 0; i < vec5.size(); i++) {
        cout << vec5[i] << endl;
        // cout << vec5.at(i) << endl; // OR
    }
}