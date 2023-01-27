#include <stdio.h>

#include "gene.h"

int main() {
  double x00, x01 = -10.e0, x10, x11 = -10.e0, a = 0.3;
  int c = 0;

  do {
    x00 = x01;
    x10 = x11;

    x01 = x00 - a * (g3(x00 + 0.5e-3, x10) - g3(x00 - 0.5e-3, x10)) / 1.e-3;
    x11 = x10 - a * (g3(x00, x10 + 0.5e-3) - g3(x00, x10 - 0.5e-3)) / 1.e-3;

    if (x01 >  10.e0) x01 =  10.e0;
    if (x01 < -10.e0) x01 = -10.e0;
    if (x11 >  10.e0) x11 =  10.e0;
    if (x11 < -10.e0) x11 = -10.e0;
    c++;
  } while (fabs(x01 - x00) > 1.e-8 || fabs(x11 - x10) > 1.e-8);

  printf("x0 = %lf, x1 = %lf, g3() = %lf, %d\n", x01, x11, g3(x01, x11), c);
  return 0;
}
