// #include "c:\work\e3exp.h"

int main(void) {
  init_MTLED();

  char a[] = { 0x1f, 0x24, 0x44, 0x24, 0x1f, 0x21, 0x7f, 0x01 };

  for (int i = 0; i < 8; i++) {
    send_one(i + 1, a[i]);
  }

  while(1)
    ;
}
