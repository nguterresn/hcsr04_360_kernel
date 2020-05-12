#include "blink.h"

void Test_Builtin_Led () {
 
    /* Set as output */
    DDRB |= (1<<BUILTIN_LED);

    /* off */
    PORTB &= ~(1<<BUILTIN_LED);
    /* on */
    PORTB |= (1<<BUILTIN_LED);

    delay(2000);

    PORTB &= ~(1<<BUILTIN_LED);

};