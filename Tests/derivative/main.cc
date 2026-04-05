/*
 * Support for calculating derivatives of the form (f(x))^n.
 * Multi-calculation.
*/

#include <iostream>
#include <string>

#include <cstdio>
#include <cstring>
#include <cmath>

int getInput(std::string *inp);

int main(int argc, char** argv) {
  std::string input = "";

  if (argc >= 2 && strcmp(argv[1], "-h") != 1) {
    input = argv[1];
  } else {
    if (getInput(&input)) {
      printf("Incorrect input.\n");
      exit(EXIT_FAILURE);
    }
  }

  std::string delimiter = "^";
  size_t inp_found = input.find(delimiter);
  size_t inp_size = input.size();
  std::cout << "[Size: " << inp_size << "]\t";

  if (inp_found != std::string::npos) {
    std::cout << "[Degree Index: " << inp_found << "]\t";
  } else {
    printf("Where is the degree of the polynomial?\n");
  }

  float inp_degree = std::stof(input.substr(inp_found + delimiter.length()));
  std::cout << "[Degree Value: " << inp_degree << "]\t";

  float inp_coefficient = std::stof(input.substr(0, inp_found - delimiter.length()));
  std::cout << "[Coefficient Value: " << inp_coefficient << "]\t\n";

  float calc_coe = inp_degree * inp_coefficient;
  float calc_deg = inp_degree - 1;

  std::string m_deg;
  if (std::trunc(calc_deg) == calc_deg) {
    m_deg = std::to_string(static_cast<long long>(calc_deg));
  } else {
    m_deg = std::to_string(calc_deg);
  }

  std::string m_coe;
  if (std::trunc(calc_coe) == calc_coe) {
    m_coe = std::to_string(static_cast<long long>(calc_coe));
  } else {
    m_coe = std::to_string(calc_coe);
  }

  std::string res_deg;
  if (calc_deg == 1) {
    res_deg = "";
  } else {
    res_deg = "x^" + m_deg; 
  }

  std::string res = m_coe + res_deg;
  
  std::cout << "Result: " << res << "\n"; 
  return 0;
}

int getInput(std::string *inp) {
  printf("Input: ");

  std::cin >> *inp;
  if (inp->empty()) {
    return 1;
  }
  return 0;
}
