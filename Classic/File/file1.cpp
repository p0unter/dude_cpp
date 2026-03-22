#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string fileName = "filing1.txt";
    ofstream file;
    file.open(fileName);

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    } else {
        file << "This is a 1. line" << endl;      
    }

    file.close();
    
    return 0;
}