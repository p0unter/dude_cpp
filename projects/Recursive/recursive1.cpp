#include <iostream>
using namespace std;

void F(int n) {
	if (n == 0) {
		return;
	}
	F(n - 1);
	cout << n;
}

int FA(int n) {
	if (n == 1) {
		return 1;
	}
	return n * FA(n - 1);
}

int main() {
	F(5);

	cout << FA(5);
}