#include <iostream>
using namespace std;
int calculator(int n) {
	if (n == 0) {
		return 0;
	}
	else 
	{
		return n + calculator(n - 1);
	}
}

int main() {
	int number1;
	cin >> number1;
	cout << "Result: " << calculator(5);
}