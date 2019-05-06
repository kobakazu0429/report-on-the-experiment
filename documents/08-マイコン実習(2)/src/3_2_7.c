#include <stdio.h>
#include "c:\work\e3exp.h"

int main(void) {
  init_MTLED();

  char char_set[] = {
    0x00, 0x02, 0x25, 0x21, 0x21, 0x21, 0x01, 0x00,
    0x7f, 0x00, 0x12, 0x15, 0x55, 0x3e, 0x51, 0x00,
    0x21, 0x2e, 0x70, 0x22, 0x15, 0x11, 0x11, 0x00,
    0x7e, 0x00, 0x10, 0x11, 0x7e, 0x10, 0x10, 0x00
  };

  int offset = 0;
  int i = 0;

  while (1) {
    for (i = 0; i < 8; i++) {
      int address = i + 1;
      int left = i + offset;
      int right = left + 8;
      int text_length = 4

      send_dual(
        address,
        char_set[left % (text_length * 8)],
        address,
        char_set[right % (text_length * 8)]
      );
    }
    delayms(200);
    offset++;
  }
}
