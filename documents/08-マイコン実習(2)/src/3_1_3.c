// #include "c:\work\e3exp.h"

double voltage_to_distance(double voltage);

int main(void) {
  init_LCD();
  init_ADC();

  char msg[10];
  int sensing_position = 0;
  double converted_voltage = 0.0;
  double distance = 0.0;

  while (1) {
    sensing_position = smp_INT();
    converted_voltage = (double)sensing_position * (5 / 4096);
    distance = voltage_to_distance(converted_voltage);
    sprintf(msg, "%8.6f", distance);
    clr_LCD();
    put_str(msg);
    delayms(1500);
  }
}

double voltage_to_distance(double voltage) {
  if (0.49 < voltage && voltage <= 1.99)
    return (56.0 / voltage - 0.12);

  if (1.99 < voltage && voltage <= 2.80)
    return (30.0 / voltage - 1.00);

  return 0;
}
