#include "hcsr04.h"

void Setup_All_Modules ();
void Priority_Handler ( uint16_t dist1, 
                        uint16_t dist2,
                        uint16_t dist3,
                        uint16_t dist4, 
                        uint16_t dist5, 
                        //uint16_t dist6, ** Not Working **
                        uint16_t dist7, 
                        uint16_t dist8);