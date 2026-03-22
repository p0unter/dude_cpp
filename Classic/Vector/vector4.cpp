/*
insert() : Adding apples to the desired location.
erase() : Removing the element.
iterator() : Acts like a pointer.

begin() - iterator : It holds the address of the first element.
end() - iterator : It holds the address of the last element.
*/

#include <iostream>
#include <vector>
using namespace std;

main() {
    vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7};

    /* NORMAL */
    cout << *(vec1.begin() + 3) << endl;
    cout << *(vec1.end() - 1) << endl;

    cout << &(*(vec1.end() - 1)) << endl; // address

    vector<int>::iterator it1, it2;
    it1 = vec1.begin();
    it2 = vec1.end();

    // add
    vec1.insert(it1, 15);
    vec1.insert(it1 + 2, 15);

    vec1.insert(it2, 25);
    vec1.insert(it2 - 2, 25);

    // delete
    vec1.erase(it1 + 3);

    for(auto content : vec1) {
        cout << content << endl;
    }

    /* ITERATOR */
    vector<int>::iterator it;
    for(it = *vec1.begin(); it != vec1.end(); it++) {
        cout << *it << endl;
    }
}