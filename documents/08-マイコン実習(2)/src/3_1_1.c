// #include "c:\work\e3exp.h"

int main(void)
{
  init_LCD();
  init_ADC();

  char msg[10];
  int sensing_position = 0;

  while (1)
  {
    sensing_position = smp_INT();
    sprintf(msg, "%4d", sensing_position);
    clr_LCD();
    put_str(msg);
    delayms(1500);
  }
}
