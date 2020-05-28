#include "c:\work\e3exp.h"

double voltage_to_distance(double voltage);

int main(void) {
  init_LCD();
  init_ADC();

  char LCD_distance[10], LCD_voltage[10];
  int sensing_position = 0;
  double converted_voltage = 0.0;
  double distance = 0.0;

  while (1) {
    sensing_position = smp_INT();
    converted_voltage = (double)sensing_position * (double)(5. / 4096.);
    distance = voltage_to_distance(converted_voltage);

    sprintf(LCD_distance, "%8.6f", distance);
    sprintf(LCD_voltage, "%8.6f", converted_voltage);

    locate(0, 0);
    put_str(LCD_distance);

    locate(0, 1);
    put_str(LCD_voltage);

    delayms(200);
  }
}

double voltage_to_distance(double voltage) {
  if (0.49 < voltage && voltage <= 1.99)
    return (56.0 / voltage - 0.12);

  if (1.99 < voltage && voltage <= 2.80)
    return (30.0 / voltage - 1.00);

  return 0;
}
