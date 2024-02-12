#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

void measure_distance(void);
uint32_t measure_pulse_duration(void)
void Timer0ACapture_init(void);
void Delay_MicroSecond(int time);
void Delay(unsigned long counter);

#endif
