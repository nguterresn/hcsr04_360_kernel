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

void mod1 () {
	sendTrigger(MODULE_1);
	EchoPulseWidth(&Dist.Measures[MODULE_1]);
}

void mod2 () {
	sendTrigger(MODULE_2);
	EchoPulseWidth(&Dist.Measures[MODULE_2]);
}

void mod3 () {
	sendTrigger(MODULE_3);
	EchoPulseWidth(&Dist.Measures[MODULE_3]);
}

void mod4 () {
	sendTrigger(MODULE_4);
	EchoPulseWidth(&Dist.Measures[MODULE_4]);
}

void mod5 () {
	sendTrigger(MODULE_5);
	EchoPulseWidth(&Dist.Measures[MODULE_5]);
}

void mod7 () {
	sendTrigger(MODULE_7);
	EchoPulseWidth(&Dist.Measures[MODULE_7]);
}

void mod8 () {
	sendTrigger(MODULE_8);
	EchoPulseWidth(&Dist.Measures[MODULE_8]);
}


void Clear_Distance () {
	//reset 
	for (int i = 0; i < NUMBER_MODULES; i++)
	{
		Dist.close[i] = 0;
		Dist.medium[i] = 0;
		Dist.far[i] = 0;
	}
}

void Distance_Handler () {

	int index;

	for (int i = 0; i < NUMBER_MODULES; i++)
	{

		/* FAR */
		if (Dist.Measures[i] > FAR) {
			index = FirstIndexAvailable(Dist.far);
			Dist.far[index] = 2;

		/* MEDIUM */
		} else if ((Dist.Measures[i] <= FAR) && (Dist.Measures[i] > MEDIUM)) {
			index = FirstIndexAvailable(Dist.medium);
			Dist.medium[index] = 3;

		/* CLOSE */
		} else if ((Dist.Measures[i] <= MEDIUM) && (Dist.Measures[i] > CLOSE)) {
			index = FirstIndexAvailable(Dist.close);
			Dist.close[index] = 4;
		}
	}
	
}

int FirstIndexAvailable (int array[]) {
	for (int i = 0; i < NUMBER_MODULES; i++) if (!array[i]) return i;
	return -1;
}

