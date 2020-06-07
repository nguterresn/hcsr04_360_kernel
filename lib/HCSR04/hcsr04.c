#include "hcsr04.h"

void setupHCSR04(uint8_t trigger) {

    /* check if trig pin is within 0 and 1 */
    if (trigger < 2) {
        // Set trig as output 
        DDRB |= (1<<trigger);
    } else {
        // Set trig as output 
        DDRD |= (1<<trigger);
    }

}

void sendTrigger(uint8_t trigger) {

    if (trigger < 2) {

        PORTB &= ~(1<<trigger);
        PORTB |= (1<<trigger);
        _delay_us(10);
        PORTB &= ~(1<<trigger);

    } else {

        PORTD &= ~(1<<trigger);
        PORTD |= (1<<trigger);
        _delay_us(10);
        PORTD &= ~(1<<trigger);

    }

}

void EchoPulseWidth(double *distance, double *time) {

    uint64_t start, end;

    /* WHILE ECHO IS LOW */
    while(!(PINC & (1 << ECHO)));

    /* START MEASURE TIME */
    start = micros();

    /* WAIT WHILE ECHO IS HIGH */
    while(PINC & (1 << ECHO)) {

        /* 23200 us is the max value of time to reach the maximum value of distance (4 meters).
         * If temp is higher than 23200, it means there is no obstacle.
         * Sometimes it can occur a "loss of echo" meaning the line is always HIGH for a huge period of time
         * --LOSS OF ECHO--
         * New trigger and reading.

        end =  micros();
        temp = end - start;

        if (temp > 23200) {
             Timeout function ()
        } */

    }

    /* END MEASURE TIME */
    end = micros();

    *time = end - start;

    *distance = (end - start) / 58;

}