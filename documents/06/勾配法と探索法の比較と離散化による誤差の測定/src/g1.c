#include <stdio.h>

#include "gene.h"

int main() {
  FILE *fp;
  double x;
  int t;

  fp = fopen("g1.csv", "wt");

  for (t = -100; t <= 100; t++) {
    x = (double)t / 10.e0;
    fprintf(fp, "%lf,%lf\n", x, g1(x));
  }
  fclose(fp);
  return 0;
}
