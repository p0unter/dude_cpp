#include "calculators.h"

int factorialCalc(int input) {
    if (input == 1) {
		return 1;
	}
	return input * factorialCalc(input - 1);
}

void piCalc(int input) {
	area = pi * input * input;
}