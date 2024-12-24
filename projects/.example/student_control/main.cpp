#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    string surname;
    int age;
    int number;
};

void studentAdd(vector<Student> &std) {
    Student temp;
    cout << "Student name: ";
    cin.ignore();
    getline(cin, temp.name);

    cout << "Student surname: ";
    getline(cin, temp.surname);

    cout << "Student age: ";
    cin >> temp.age;

    cout << "Student number: ";
    cin >> temp.number;

    std.push_back(temp);

    cout << "----------------------------" << endl;
    cout << "\tAdded successfully!\t" << endl;
    cout << "----------------------------\n" << endl;
}

void studentList(const vector<Student> &std) {
    if (std.empty()) {
        cout << "No student" << endl;
        return;
    }
    cout << "--------Student List--------" << endl;
    for (int i = 0; i < std.size(); i++) {
        cout << i + 1 << ". Student" << endl;
        cout << "Name: " << std[i].name << endl;
        cout << "Surname: " << std[i].surname << endl;
        cout << "Age: " << std[i].age << endl;
        cout << "Number: " << std[i].number << endl;
    }
    cout << "----------------------------" << endl;
}

void studentSearch(const vector<Student> &std) {
    int number;
    cout << "Your search number: ";
    cin >> number;
    for (const auto &content : std) {
        if (content.number == number) {
            cout << "Student found!" << endl;
            cout << "----------------------------" << endl;
            cout << "Name: " << content.name << endl;
            cout << "Surname: " << content.surname << endl;
            cout << "Age: " << content.age << endl;
            cout << "Number: " << content.number << endl;
            cout << "----------------------------" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void studentRemove(vector<Student> &std) {
    int number;
    cout << "Student number: ";
    cin >> number;
    for (int i = 0; i < std.size(); i++) {
        if(std[i].number == number) {
            std.erase(std.begin() + i);
            cout << "\tRemove successfully!\t" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

int main() {
    vector<Student> std;
    int vote = 0;
    while(vote != 5) {
        cout << "-----Student Controller-----" << endl;
        cout << "1 -\t" << "Student Add" << endl; 
        cout << "2 -\t" << "Student List" << endl; 
        cout << "3 -\t" << "Student Search" << endl; 
        cout << "4 -\t" << "Student Remove" << endl; 
        cout << "5 -\t" << "Exit" << endl; 
        cout << "----------------------------\n" << endl;
        
        cout << "Your choice: ";
        
        cin >> vote;

        switch (vote) {
            case 1:
                studentAdd(std);
                break;
            case 2:
                studentList(std);
                break;
            case 3:
                studentSearch(std);
                break;
            case 4:
                studentRemove(std);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}