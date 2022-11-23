#include <stdio.h>

#include "func.h"

int main() {
  int c, b = 10; // bは区間の分割数
  double x, f21v, f20v, dt2 = 1.0 / (double)b, f[2000], d = 0.0;

  FILE *fp;
  fp = fopen("f2d.csv", "wt");

  for (c = -1; c <= b + 1; c++) {
    x = (double)c / (double)b;
    f[c + 1] = f2(x, 0, 17);
  }

  fprintf(fp, "t,f\'2c,f\'2\n");
  for (c = 0; c <= b; c++) {
    x = (double)c / (double)b;
    f21v = (f[c + 2] - f[c]) / (dt2 * 2.0);
    f20v = f2(x, 1, 17);
    fprintf(fp, "%lf,", x);
    fprintf(fp, "%lf,", f21v);
    fprintf(fp, "%lf\n", f20v);
    d += fabs(f21v - f20v);
  }
  printf("%lf\n", d / (double)b);
  fclose(fp);
  return 0;
}
