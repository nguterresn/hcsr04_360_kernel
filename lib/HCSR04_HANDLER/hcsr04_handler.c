#include "hcsr04_handler.h"

void Setup_All_Modules() {

	setupHCSR04(MODULE_1);
	setupHCSR04(MODULE_2);
	setupHCSR04(MODULE_3);
	setupHCSR04(MODULE_4);
	setupHCSR04(MODULE_5);
	setupHCSR04(MODULE_6);
	setupHCSR04(MODULE_7);
	setupHCSR04(MODULE_8);

}

void Priority_Handler ( uint16_t dist1, 
                        uint16_t dist2,
                        uint16_t dist3,
                        uint16_t dist4, 
                        uint16_t dist5, 
                        //uint16_t dist6, ** Not Working **
                        uint16_t dist7, 
                        uint16_t dist8) {
}

