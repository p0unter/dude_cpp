#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string name;
    string surname;
    double grade;
};

vector<Student> inputInfo(int n) {
    vector<Student> temp(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter name: ";
        cin >> temp[i].name;

        cout << "Enter surname: ";
        cin >> temp[i].surname;
        
        cout << "Enter grade: ";
        cin >> temp[i].grade;
    }

    return temp;
}

void infoWrite(const vector<Student>& std) {
    for (const auto& content : std) {
        cout << "Name: " << content.name << endl;
        cout << "Surname: " << content.surname << endl;
        cout << "Grade: " << content.grade << endl;
    }
}

int main() {
    int n;
    cout << "How many students?: ";
    cin >> n;

    vector<Student> std = inputInfo(n);
    infoWrite(std);

    return 0;
}