#include <iostream>
#include <vector>
using namespace std;

/*
push_back: Allows adding elements to the end of the vector
pop_back: Allows deleting the last element of the vector.
front: Writes the first element of the vector to the screen.
back: Writes the last element of the vector to the screen.
swap: It allows swapping the elements of two vectors.
*/

main() {
    vector<int> vec1(5, 10);
    
    vec1.push_back(11);
    vec1.push_back(12);
    vec1.push_back(13);
    vec1.push_back(14);

    cout << "Back: " << vec1.back() << endl;
    cout << "Front: " << vec1.front() << endl;
    
    cout << "\n- - - - - - - - -\n" << endl;

    cout << "Vec1" << endl;
    for(auto content : vec1) {
        cout << content << endl;
    }

    cout << "Vec2" << endl;
    vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7};
    for(auto content : vec2) {
        cout << content << endl;
    }
    vec1.swap(vec2);

    cout << "\n- - - - - - - - -\n" << endl;

    cout << "Vec1" << endl;
    for(auto content : vec1) {
        cout << content << endl;
    }

    cout << "Vec2" << endl;
    for(auto content : vec2) {
        cout << content << endl;
    }
}