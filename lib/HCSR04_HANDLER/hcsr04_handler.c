#include "hcsr04_handler.h"

int Sched_AddTask(void (*function)(void),  int delay, int period);

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

void Setup_Distance() {
	Dist.far_length = 8; Dist.medium_length = 8; Dist.close_length = 8;
}

void Clear () {
	for (int i = 0; i < Dist.close_length; i++)
		Dist.close[i] = -1;
	for (int i = 0; i < Dist.medium_length; i++)
		Dist.medium[i] = -1;
	for (int i = 0; i < Dist.far_length; i++)
		Dist.far[i] = -1;
}

void Distance_Handler () {
	
	int index, far = 0, medium = 0, close = 0;

	Clear();

	/* Stores index depending on the values measured */
	for (int i = 0; i < NUMBER_MODULES; i++)
	{
		/* FAR */
		if (Dist.Measures[i] > FAR) {
			index = FirstIndexAvailable(Dist.far);
			Dist.far[index] = i;
			far++;

		/* MEDIUM */
		} else if ((Dist.Measures[i] <= FAR) && (Dist.Measures[i] > MEDIUM)) {
			index = FirstIndexAvailable(Dist.medium);
			Dist.medium[index] = i;
			medium++;

		/* CLOSE */
		} else if ((Dist.Measures[i] <= MEDIUM) && (Dist.Measures[i] > CLOSE)) {
			index = FirstIndexAvailable(Dist.close);
			Dist.close[index] = i;
			close++;
		}
	}

	/* length of distance arrays */
	Dist.far_length = far;
	Dist.medium_length = medium;
	Dist.close_length = close;

	for (int i = 0; i < Dist.close_length; i++)
	{
		switch (Dist.close[i])
		{
		case 0: Sched_AddTask(mod7, 0, 0); break;
		case 1: Sched_AddTask(mod8, 0, 0); break;
		case 2: Sched_AddTask(mod1, 0, 0); break;
		case 3: Sched_AddTask(mod2, 0, 0); break;
		case 4: Sched_AddTask(mod3, 0, 0); break;
		case 5: Sched_AddTask(mod4, 0, 0); break;
		case 6: Sched_AddTask(mod5, 0, 0); break;

		default:
			break;
		}
	}

	for (int i = 0; i < Dist.medium_length; i++)
	{
		switch (Dist.medium[i])
		{
		case 0: Sched_AddTask(mod7, 0, 0); break;
		case 1: Sched_AddTask(mod8, 0, 0); break;
		case 2: Sched_AddTask(mod1, 0, 0); break;
		case 3: Sched_AddTask(mod2, 0, 0); break;
		case 4: Sched_AddTask(mod3, 0, 0); break;
		case 5: Sched_AddTask(mod4, 0, 0); break;
		case 6: Sched_AddTask(mod5, 0, 0); break;

		default:
			break;
		}
	}

	for (int i = 0; i < Dist.far_length; i++)
	{
		switch (Dist.far[i])
		{
		case 0: Sched_AddTask(mod7, 0, 0); break;
		case 1: Sched_AddTask(mod8, 0, 0); break;
		case 2: Sched_AddTask(mod1, 0, 0); break;
		case 3: Sched_AddTask(mod2, 0, 0); break;
		case 4: Sched_AddTask(mod3, 0, 0); break;
		case 5: Sched_AddTask(mod4, 0, 0); break;
		case 6: Sched_AddTask(mod5, 0, 0); break;

		default:
			break;
		}
	}

	//Time.Global = 0.0;
}

int FirstIndexAvailable (int array[]) {
	/* If array is not defined (-1) */
	for (int i = 0; i < NUMBER_MODULES; i++) if (array[i] == -1) return i;

	/* Returns -1 if array is full */
	return -1;
}

void mod1 () {

	sendTrigger(MODULE_1);
	EchoPulseWidth(&Dist.Measures[MODULE_1], &Time.Measures[MODULE_1]);

	Time.Global += Time.Measures[MODULE_1];
}

void mod2 () {

	sendTrigger(MODULE_2);
	EchoPulseWidth(&Dist.Measures[MODULE_2], &Time.Measures[MODULE_2]);

	Time.Global += Time.Measures[MODULE_2];
}

void mod3 () {

	sendTrigger(MODULE_3);
	EchoPulseWidth(&Dist.Measures[MODULE_3], &Time.Measures[MODULE_3]);

	Time.Global += Time.Measures[MODULE_3];
}

void mod4 () {

	sendTrigger(MODULE_4);
	EchoPulseWidth(&Dist.Measures[MODULE_4], &Time.Measures[MODULE_4]);

	Time.Global += Time.Measures[MODULE_4];
}

void mod5 () {

	sendTrigger(MODULE_5);
	EchoPulseWidth(&Dist.Measures[MODULE_5], &Time.Measures[MODULE_5]);

	Time.Global += Time.Measures[MODULE_5];
}

/* Modulo 6 nao está funcional */

void mod7 () {

	sendTrigger(MODULE_7);
	EchoPulseWidth(&Dist.Measures[MODULE_7], &Time.Measures[MODULE_7]);

	Time.Global += Time.Measures[MODULE_7];
}

void mod8 () {

	sendTrigger(MODULE_8);
	EchoPulseWidth(&Dist.Measures[MODULE_8], &Time.Measures[MODULE_8]);

	Time.Global += Time.Measures[MODULE_8];
}



