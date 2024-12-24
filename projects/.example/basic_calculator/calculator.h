#pragma once

#include <iostream>

struct Write {
    double n1;
    double n2;
};

void writeSpace(Write &wte);

double calcCollection(Write &wte);
double calcExtraction(Write &wte);
double calcImpact(Write &wte);
double calcDivide(Write &wte);