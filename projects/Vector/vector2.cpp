#include <iostream>
#include <vector>
using namespace std;

main() {
    vector<int> vec1;
    vec1.push_back(10);
    cout << "size: " << vec1.size() << endl;
    cout << "capacity: " << vec1.capacity() << endl;

    for(int i = 0; i < 65; i++) {
        vec1.push_back(10);
        cout << "size: " << vec1.size() << endl;
        cout << "capacity: " << vec1.capacity() << endl;

        // Capacity: size*2
    }
    cout << "- - - - - - - - - - - -" << endl;

    vec1.shrink_to_fit(); // space free...

    cout << "size: " << vec1.size() << endl;
    cout << "capacity: " << vec1.capacity() << endl;
}