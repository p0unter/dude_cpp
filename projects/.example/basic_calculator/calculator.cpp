#include "calculator.h"

void writeSpace(Write &wte) {
    std::cout << "Number 1: ";
    std::cin >> wte.n1;

    std::cout << "Number 2: ";
    std::cin >> wte.n2;
}

double calcCollection(Write &wte) {
    writeSpace(wte);
    return wte.n1 + wte.n2;
}

double calcExtraction(Write &wte) {
    writeSpace(wte);
    return wte.n1 - wte.n2;
}

double calcImpact(Write &wte) {
    writeSpace(wte);
    return wte.n1 * wte.n2;
}

double calcDivide(Write &wte) {
    writeSpace(wte);
    if (wte.n2 == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
    return wte.n1 / wte.n2;
}