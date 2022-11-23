#include <math.h>
#include <stdio.h>

#include "func.h"

#define PRECISION 2000

int main() {
  char buf[10000];
  // setvbuf(stdout, buf, _IOFBF, sizeof(buf));
  setvbuf(stdout, NULL, _IOFBF, 512 * 1024);

  int a, b; // bは区間の分割数
  double x, d, s;

  FILE *fp;
  fp = fopen("f2i.csv", "wt");

  for (b = 1; b <= PRECISION; b++) {
    if (b % 100 == 0) {
      fprintf(stderr, "%d / %d\n", b, PRECISION);
    }
    d = 1.0 / (double)b;
    s = 0.0;
    for (a = 0; a < b; a++) {
      x = (double)a / (double)b;
      s += (f2(x, 0, 17) + f2(x + d, 0, 17)) / 2.0 * d;
    }
    fprintf(fp, "%d,%.20lf\n", b, fabs(f2(0.0, 2, 17) - s));
  }

  fclose(fp);
  return 0;
}
