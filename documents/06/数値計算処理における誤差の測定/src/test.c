#include <stdio.h>

#include "func.h"

int main() {
  int a;
  FILE *fp;
  double t;

  fp = fopen("f2.csv", "wt");
  fprintf(fp, "t,f2,f2d\n");
  for (a = 0; a <= 100; a++) {
    t = (double)a / 100.0;
    fprintf(fp, "%lf,%lf,%lf\n", t, f2(t, 0, 17), f2(t, 1, 17));
  }
  fclose(fp);
  return 0;
}
