#include <iostream>
using namespace std;

int F(int n) {
	if (n < 10) {
		return n;
	}
	return n % 10 + F(n / 10);
}


int main() {
	int number1;
	cout << "Enter number: ";
	cin >> number1;
	cout << F(number1);
}