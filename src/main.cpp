#include <Arduino.h>

extern "C" {
   #include "hcsr04.h"
   #include "blink.h"
   #include "schedule.h"
   #include "hcsr04_handler.h"
}

void ShowSerialInfo();
int Test_All_Modules();

void setup() {

	int delay;

	Serial.begin(9600);

	/* Setup Trigger pins as outputs */
	Setup_All_Modules();

	/* Initializes struct variables */
	Setup_Distance();

	/* Initializes schedule */
	Sched_Init();

	/* Triggers and reads values from all sensores to measure a delay on to the next measure */
	delay = Test_All_Modules();
	Serial.print("Delay: "); Serial.println(delay);

	/** Sorts by priority of distance - FAR, MEDIUM and CLOSE */
	Sched_AddTask(Distance_Handler, 0, 5000);
	Sched_AddTask(ShowSerialInfo, 0, 5000);

}

void loop() {
	Sched_Dispatch();
}

int Test_All_Modules () {

	int t = 0;

	sendTrigger(MODULE_1);
	EchoPulseWidth(&Dist.Measures[MODULE_1]);

	t += Dist.Measures[MODULE_1];

	/****/

	sendTrigger(MODULE_2);
	EchoPulseWidth(&Dist.Measures[MODULE_2]);

	t += Dist.Measures[MODULE_2];
	
	/****/

	sendTrigger(MODULE_3);
	EchoPulseWidth(&Dist.Measures[MODULE_3]);

	t += Dist.Measures[MODULE_3];
	
	/****/

	sendTrigger(MODULE_4);
	EchoPulseWidth(&Dist.Measures[MODULE_4]);

	t += Dist.Measures[MODULE_4];

	/****/

	sendTrigger(MODULE_5);
	EchoPulseWidth(&Dist.Measures[MODULE_5]);

	t += Dist.Measures[MODULE_5];

	/*** --Not working--

	Serial.print("Six module measure: ");
	sendTrigger(MODULE_6);
	EchoPulseWidth(&d, MODULE_6);
	Serial.println(d);*/

	/****/

	sendTrigger(MODULE_7);
	EchoPulseWidth(&Dist.Measures[MODULE_7]);

	t += Dist.Measures[MODULE_7];

	/****/

	sendTrigger(MODULE_8);
	EchoPulseWidth(&Dist.Measures[MODULE_8]);

	t += Dist.Measures[MODULE_8];

	/****/

	return (t * 0.058);
}

void ShowSerialInfo() {
	Serial.println("*** Values measured ***");
	for (int i = 0; i < 8; i++)
	{	
		Serial.print("Position index: ["); Serial.print(i); Serial.print("] value: ( "); Serial.print(Dist.Measures[i]); Serial.println(" )");
	}
	Serial.println("*** Far modules ***");
	Serial.println(Dist.far_length);
	for (int i = 0; i < Dist.far_length; i++)
	{
		Serial.print("Position index: ["); Serial.print(i); Serial.print("] value: ( "); Serial.print(Dist.far[i]); Serial.println(" )");
	}
	Serial.println("*** Medium modules ***");
	Serial.println(Dist.medium_length);
	for (int i = 0; i < Dist.medium_length; i++)
	{
		Serial.print("Position index: ["); Serial.print(i); Serial.print("] value: ( "); Serial.print(Dist.medium[i]); Serial.println(" )");
	}
	Serial.println("*** Close modules ***");
	Serial.println(Dist.close_length);
	for (int i = 0; i < Dist.close_length; i++)
	{
		Serial.print("Position index: ["); Serial.print(i); Serial.print("] value: ( "); Serial.print(Dist.close[i]); Serial.println(" )");
	}
}
