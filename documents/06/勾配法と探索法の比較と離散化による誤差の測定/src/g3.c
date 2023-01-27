#include <stdio.h>

#include "gene.h"

int main() {
  FILE *fp;
  double x0, x1;
  int t0, t1;

  fp = fopen("g3.csv", "wt");

  for (t1 = -100; t1 <= 100; t1++) {
    x1 = (double)t1 / 10.e0;
    fprintf(fp, ",%lf", x1);
  }
  fprintf(fp, "\n");

  for (t0 = -100; t0 <= 100; t0++) {
    x0 = (double)t0 / 10.e0;
    fprintf(fp, "%lf", x0);
    for (t1 = -100; t1 <= 100; t1++) {
      x1 = (double)t1 / 10.e0;
      fprintf(fp, ",%lf", g3(x0, x1));
    }

    fprintf(fp, "\n");
  }

  fclose(fp);
  return 0;
}
