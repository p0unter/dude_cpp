#include <iostream>
#include <vector>
using namespace std;

// toupper, tolower

vector<string> updateString(vector<string> names) {
    for(int i = 0; i < names.size(); i++) {
        names[i][0] = toupper(names[i][0]);
        for(int j = 1; j < names[i].size(); i++) {
            names[i][j] = tolower(names[i][j]);
        }
    }

    return;
}

main() {
    vector<string> names[] = {"ahMeT", "mehTet"};
    cout << "Before" << endl;
    for(auto content : names) {
        cout << content << endl;
    }

    vector<string> new_names = updateString(names);
}