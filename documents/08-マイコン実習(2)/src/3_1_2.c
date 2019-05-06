// #include "c:\work\e3exp.h"

int main(void)
{
  init_LCD();
  init_ADC();

  char msg[10];
  int sensing_position = 0;
  double converted_voltage = 0.0;

  while (1)
  {
    sensing_position = smp_INT();
    converted_voltage = (double)sensing_position * (double)(5. / 4096.);
    sprintf(msg, "%8.6f", converted_voltage);
    clr_LCD();
    put_str(msg);
    delayms(200);
  }
}
