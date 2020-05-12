#include "stdint.h"
#include <avr/io.h>
#include <util/delay.h>
#include <time.h>
#include "Arduino.h"

//PD
#define MODULE_1 2
#define MODULE_2 3
#define MODULE_3 4
#define MODULE_4 5
#define MODULE_5 6
#define MODULE_6 7
//PB
#define MODULE_7 0
#define MODULE_8 1

//PC0
#define ECHO 0

void setupHCSR04(uint8_t trigger);
void sendTrigger(uint8_t trigger);
void EchoPulseWidth(double *distance);