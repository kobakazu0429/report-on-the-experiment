#include <math.h>
#include <stdio.h>

#include "gene.h"

int main() {
  int c = 0;
  double a = 0.6, x0, x1 = -10.e0;

  do {
    x0 = x1;
    x1 = x0 - a * (g1(x0 + 0.5e-3) - g1(x0 - 0.5e-3)) / 1.e-3;
    c++;
  } while (fabs(x1 - x0) > 1.e-8);

  printf("%1f %d\n", x1, c);
  return 0;
}
