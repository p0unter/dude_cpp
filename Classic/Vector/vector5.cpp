#include <iostream>
#include <vector>

using namespace std;
main() {
    vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec2;

    vec1.assign(7, 100);
    vec2.assign(vec1.begin() + 2, vec1.end() - 3);
    for(auto content : vec1)
        cout << content << endl;

    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> vec3;

    vec3.assign(array, array+5);
    for(auto content : vec3)
        cout << content << endl;
}