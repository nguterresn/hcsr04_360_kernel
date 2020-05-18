#include "schedule.h"

ISR (TIMER1_COMPA_vect)
{
    Sched_Schedule();
}

/**
 * 1ms @ 16mhz 
 * */
void Config_Timer() {

    // Set the Timer Mode to CTC
    TCCR1A |= (1 << WGM12);

    OCR1A = 15999;

    TIMSK1 |= (1 << OCIE1A);    //Set the ISR COMPA vect

    sei();         //enable interrupts

    // n = 1
    TCCR1B |= (1 << CS10);

} 

int Sched_Init() {

    for (int x = 0; x < TASKS_NUMBER; x++) Tasks[x].func = 0;
    
    /*
    * Also configures
    * interrupt that
    * periodically calls * Sched_Schedule(). */

    Config_Timer();

    return 0;

}

void Sched_Schedule() {

    for(int x = 0; x < TASKS_NUMBER; x++) { 

        /* SEarchs for tasks initialized */
        if(Tasks[x].func) { 
            /* If there is a delay, waits and reduces "Tasks[x].delay" variable */
            if(Tasks[x].delay) { 

                Tasks[x].delay--;

            /* If there is no delay, the task MUST start */
            } else {

                /* Schedules Task to Start */
                Tasks[x].exec++;
                Tasks[x].delay = Tasks[x].period-1; 
           }
        }
    }
}

int Sched_AddTask(void (*function)(void),  int delay, int period){

    for(int x = 0; x < TASKS_NUMBER; x++)
        if (!Tasks[x].func) { 
            Tasks[x].period = period; 
            Tasks[x].delay = delay; 
            Tasks[x].exec = 0; 
            Tasks[x].func = function; 
            return x;
        }

    return -1;
}

void Sched_Dispatch() { 

    for(int x = 0; x < TASKS_NUMBER; x++) {

        if((Tasks[x].func) && (Tasks[x].exec)) {

            Tasks[x].exec--; 
            Tasks[x].func();

            /* Delete task * if one-shot */
            if(!Tasks[x].period) Tasks[x].func = 0;

            return;
        }
    }
}