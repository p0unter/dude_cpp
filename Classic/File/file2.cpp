#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /* Line by line read 
        string fileName = "filing1.txt";
        string line;
        ifstream file(fileName);
        
        if (!file.is_open()) {
            cout << "Error: File not found" << endl;
            return 1;
        } else {
            while(getline(file, line)) {
                cout << line << endl;
            }
        }
    */

    /* Word by word read 

    ifstream file("filing1.txt");
    string word;
    file >> word;
     
    while (!file.eof()) {
        file >> word;
        cout << word << endl;
    }
    */

    /* Character by character read */
    ifstream file("filing1.txt");
    char ch;
    
    if (!file.is_open()) {
        cout << "Error: File not found" << endl;
    } else {
        while (file.get(ch)) {
            cout << ch;
        }
    }
    

    file.close();
    return 0;
}