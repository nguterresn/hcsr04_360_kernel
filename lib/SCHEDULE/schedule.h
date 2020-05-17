#include <avr/io.h> 
#include <avr/interrupt.h>

/* Define the number of tasks available */
#define TASKS_NUMBER 20 

typedef struct {
    /* period in ticks    */
    int period;
    /* ticks to activate  */
    int delay;
    /* function pointer -> type (*pointer-name)(parameter); */
    void (*func)(void);
    /* activation counter */
    int exec;
} Sched_Task_t;

Sched_Task_t Tasks[TASKS_NUMBER];

int Sched_Init();
int Sched_AddTask(void (*function)(void), int delay, int period);

/**
 * Handles when the task is ready to be schedule or not 
 * */
void Sched_Schedule();

void Sched_Dispatch();