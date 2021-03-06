#include <iostream>
#include <math.h>
#include "main.h"

using std::cin;
using std::cout;


int main() {
  double a0, b0;
  
  cout << "Enter a0: ";
  cin >> a0;
  cout << "Enter b0: ";
  cin >> b0;
  bisection(a0, b0);

  return 0;
}


double equation(double x) {
  return tan(x) - x;
}


void bisection(double a0, double b0) {
  int i = 1;
  double fa, fb, mid = 0.0, fval;

  cout << "Iteration #" << i << ": a0 = " << a0 << "\tb0 = " << b0 << "\n";
  i++;
  fa = equation(a0);
  fb = equation(b0);
  if (fa*fb > 0) {
    cout << "The roots donot exist in this interval.\n";
    return;
  }
  if (fa > 0 && fb < 0) { fval = a0; a0 = b0; b0 = fval; }

  while (modulus(b0-a0) > pow(10, -10)) {
    mid = (a0 + b0) / 2.0;
    fval = equation(mid);
    if (fval < 0) a0 = mid;
    else b0 = mid;
    cout << "Iteration #" << i << ": a0 = " << a0 << "\tb0 = " << b0 << "\n";
    i++;
  }
  cout << "Final Result = " << mid << "\n";
}


inline double modulus(double x) {
  if (x < 0) x = -x;
  return x;
}
