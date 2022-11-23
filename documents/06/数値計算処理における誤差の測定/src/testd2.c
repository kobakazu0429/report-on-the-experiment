#include <math.h>
#include <stdio.h>

#include "func.h"

#define PRECISION 6000

int main() {
  // char buf[10000];
  // setvbuf(stdout, buf, _IOFBF, sizeof(buf));
  setvbuf(stdout, NULL, _IOFBF, 2048 * 1024);

  int c, b; // bは区間の分割数
  double x, f21v, f20v, dt2, f[PRECISION + 1000], d;

  FILE *fp;
  fp = fopen("f2d23.csv", "wt");

  for (b = 1; b <= PRECISION; b++) {
    dt2 = 1.0 / (double)b;
    d = 0.0;

    for (c = -1; c <= b + 1; c++) {
      x = (double)c / (double)b;
      f[c + 1] = f2(x, 0, 17);
    }

    for (c = 0; c <= b; c++) {
      x = (double)c / (double)b;
      f21v = (f[c + 2] - f[c]) / (dt2 * 2.0);
      f20v = f2(x, 1, 17);
      d += fabs(f21v - f20v);
    }

    fprintf(fp, "%d,%.20lf\n", b, d / (double)b);

    if (b % 100 == 0) {
      fprintf(stderr, "%4d / %d\n", b, PRECISION);
    }
  }

  fclose(fp);
  return 0;
}
