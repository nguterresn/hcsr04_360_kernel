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

void EchoPulseWidth(double *distance) {

    uint64_t start, end, temp;

    /* WHILE ECHO IS LOW */
    while(!(PINC & (1 << ECHO)));

    /* START MEASURE TIME */
    start = micros();

    /* WAIT WHILE ECHO IS HIGH */
    while(PINC & (1 << ECHO)) {

        end =  micros();

        temp = end - start;

        /* 23200 us is the max value of time to reach the maximum value of distance (4 meters).
         * If temp is higher than 23200 it means there is no obstacle.
         */
        if (temp > 23200) break;

    }

    /* END MEASURE TIME */
    end = micros();

    *distance = (end - start) / 58;

}