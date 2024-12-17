#include <iostream>
using namespace std;

int main() {
    int n, total = 0;
    cout << "How many numbers will you collect?: ";
    cin >> n;
    int numbers[n];
    for(int i = 0; i > n; i++) {
        cout << i + 1 << ". Number enter: ";
        cin >> numbers[i];
    }
    for(int i = 0; i < n; i++)
        total += numbers[i];
    
    for(int i = 0; i < n; i++)
        cout << numbers[i];
    
    cout << total << endl;
}