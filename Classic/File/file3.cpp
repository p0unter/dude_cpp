#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream file("filing1.txt", ios::in | ios::out | ios::app);
    string line;
    
    if (!file.is_open()) {
        cout << "Error: File not found" << endl;
    } else {
        file << "This is a new line" << endl;

        file.seekg(0, ios::beg);

        while (getline(file, line)) {
            cout << line << endl;
        }
    }
}