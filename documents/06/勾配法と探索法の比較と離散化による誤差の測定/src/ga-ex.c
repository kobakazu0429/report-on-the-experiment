#include <stdio.h>
#include <stdlib.h>

#include "gene.h"

#define SWAP(type, a, b) \
  ({                     \
    type tmp = (a);      \
    (a) = (b);           \
    (b) = (tmp);         \
  })

double vg(int a) {
  return (double)(a - 4096) / 409.6e0;
}

int main() {
  FILE *fp;
  fp = fopen("ga-ex.csv", "wt");
  fprintf(fp, "generation,x,y,v\n");

  int g[50][2] = {
      {0, 0},        // 最小値
      {8191, 8191},  // 最大値
      {4096, 4096}   // 中間値
                     // ...ランダム
  };
  double g3v[50];

  // generate initial genes
  for (int c = 3; c < 50; c++) {
  rst0:
    g[c][0] = rand() % 8192;
    g[c][1] = rand() % 8192;
    for (int d = 0; d < c; d++) {
      if (g[c][0] == g[d][0] && g[c][1] == g[d][1]) goto rst0;
    }
  }

  for (int gn = 0; gn <= 2000; gn++) {
    // get value
    for (int c = 0; c < 50; c++) {
      g3v[c] = g3(vg(g[c][0]), vg(g[c][1]));
    }

    // sort
    for (int c = 0; c < 50 - 1; c++) {
      for (int d = c + 1; d < 50; d++) {
        if (g3v[c] > g3v[d]) {
          SWAP(int, g[c][0], g[d][0]);
          SWAP(int, g[c][1], g[d][1]);
          SWAP(double, g3v[c], g3v[d]);
        }
      }
    }

    for (int c = 30; c < 31; c++) {
    rst1:
      g[c][0] = g[rand() % 30][0];
      g[c][1] = g[rand() % 30][1];
      for (int d = 0; d < c; d++) {
        if (g[c][0] == g[d][0] && g[c][1] == g[d][1]) goto rst1;
      }
    }

    for (int c = 31; c < 40; c++) {
    rst2:
      g[c][0] = g[c][0] ^ (rand() % 512);
      g[c][1] = g[c][1] ^ (rand() % 512);
      for (int d = 0; d < c; d++) {
        if (g[c][0] == g[d][0] && g[c][1] == g[d][1]) goto rst2;
      }
    }

    for (int c = 40; c < 50; c++) {
    rst3:
      g[c][0] = rand() % 8192;
      g[c][1] = rand() % 8192;
      for (int d = 0; d < c; d++) {
        if (g[c][0] == g[d][0] && g[c][1] == g[d][1]) goto rst3;
      }
    }

    fprintf(fp,                           //
            gn,                           // generation
            vg(g[0][0]),                  // x
            vg(g[0][1]),                  // y
            g3(vg(g[0][0]), vg(g[0][1]))  // v
    );
  }

  return 0;
}
