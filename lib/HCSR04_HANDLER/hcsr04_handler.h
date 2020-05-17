#include "hcsr04.h"

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

#define NUMBER_MODULES 8

/* thresholds to split values into priority read */
#define FAR 150
#define MEDIUM 75
#define CLOSE 0

/**
 * Used to store the distance from sensors 
 * */

typedef struct {
    int close[NUMBER_MODULES];
    int medium[NUMBER_MODULES];
    int far[NUMBER_MODULES];
    double Measures[NUMBER_MODULES];
} Distance;

Distance Dist;

void Setup_All_Modules ();
void mod1 ();
void mod2 ();
void mod3 ();
void mod4 ();
void mod5 ();
void mod7 ();
void mod8 ();
void Clear_Distance ();
void Distance_Handler ();
int FirstIndexAvailable (int array[]);