#include <stdio.h>
#include <stdlib.h>

#include "gene.h"

double vg(int a) { return (double)(a - 4096) / 409.6e0; }

int main() {
  int g[50][2] = {{0, 0}, {8191, 8191}, {4096, 4096}}, bv, c, d, gn;
  double g3v[50], gv;

  for (c = 3; c < 50; c++) { // generate initial genes
  rst0:
    g[c][0] = rand() % 8192;
    g[c][1] = rand() % 8192;
    for (d = 0; d < c; d++) {
      if (g[c][0] == g[d][0] && g[c][1] == g[d][1]) {
        goto rst0;
      }
    }
  }

  for (gn = 0; gn <= 2000; gn++) {
    for (c = 0; c < 50; c++) { // get value
      g3v[c] = g3(vg(g[c][0]), vg(g[c][1]));
    }
    for (c = 0; c < 50 - 1; c++) { // sort
      for (d = c + 1; d < 50; d++) {
        if (g3v[c] > g3v[d]) {
          bv = g[c][0];
          g[c][0] = g[d][0];
          g[d][0] = bv;

          bv = g[c][1];
          g[c][1] = g[d][1];
          g[d][1] = bv;

          gv = g3v[c];
          g3v[c] = g3v[d];
          g3v[d] = gv;
        }
      }
    }

    for (c = 30; c < 31; c++) {
    rst1:
      g[c][0] = g[rand() % 30][0];
      g[c][1] = g[rand() % 30][1];
      for (d = 0; d < c; d++) {
        if (g[c][0] == g[d][0] && g[c][1] == g[d][1]) {
          goto rst1;
        }
      }
    }

    for (c = 31; c < 40; c++) {
    rst2:
      g[c][0] = g[c][0] ^ (rand() % 512);
      g[c][1] = g[c][1] ^ (rand() % 512);
      for (d = 0; d < c; d++) {
        if (g[c][0] == g[d][0] && g[c][1] == g[d][1]) {
          goto rst2;
        }
      }
    }

    for (c = 40; c < 50; c++) {
    rst3:
      g[c][0] = rand() % 8192;
      g[c][1] = rand() % 8192;
      for (d = 0; d < c; d++) {
        if (g[c][0] == g[d][0] && g[c][1] == g[d][1]) {
          goto rst3;
        }
      }
    }

    printf("\n%d %1f %1f %1f\n\n", gn, vg(g[0][0]), vg(g[0][1]),
           g3(vg(g[0][0]), vg(g[0][1])));
  }

  return 0;
}
