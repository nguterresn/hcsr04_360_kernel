#include "hcsr04.h"
#include <Arduino.h>

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
    int close_length;
    int medium[NUMBER_MODULES];
    int medium_length;
    int far[NUMBER_MODULES];
    int far_length;
    double Measures[NUMBER_MODULES];
} Distance;

typedef struct {
    double Measures[NUMBER_MODULES];
} Time_s;

Time_s Time;

Distance Dist;

void Setup_All_Modules ();

void Setup_Distance();

/**
 * Clears indexes stored in far, medium and close arrays 
 * */
void Clear_Distance ();

/**
 * Stores modules' index in far, medium and close arrays depending on the distance measured. 
 * */
void Distance_Handler ();

/**
 * Returns array first empty index 
 * */ 
int FirstIndexAvailable (int array[]);

void mod1 ();
void mod2 ();
void mod3 ();
void mod4 ();
void mod5 ();
void mod7 ();
void mod8 ();