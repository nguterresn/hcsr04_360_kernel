#include <Arduino.h>

extern "C" {
   #include "hcsr04.h"
   #include "blink.h"
   #include "schedule.h"
   #include "hcsr04_handler.h"
}

void ShowSerialInfo();

void setup() {

	Serial.begin(9600);
	Serial.println("LED TEST - Started!");
	Test_Builtin_Led();
	Serial.println("LED TEST - Ended!");

	Setup_All_Modules();
	Clear_Distance();
	Sched_Init();

	/** period with last func to organize priority */
	/* delay depends on the priority */
	Sched_AddTask(mod1, 0, 0); 
	Sched_AddTask(mod2, 35, 0);
	Sched_AddTask(mod3, 70, 0);
	Sched_AddTask(mod4, 105, 0);
	Sched_AddTask(mod5, 140, 0);
	Sched_AddTask(mod7, 175, 0);
	Sched_AddTask(mod8, 210, 0);
	Sched_AddTask(Distance_Handler, 250, 0);
	Sched_AddTask(ShowSerialInfo, 251, 0);

	/** sort by priority */

}

void loop() {
	Sched_Dispatch();
}

void Test_All_Modules () {

	double d, total;
	int t = 0;

	Serial.print("First module measure: ");
	sendTrigger(MODULE_1);
	EchoPulseWidth(&d);
	Serial.println(d);

	t += d;

	/****/

	Serial.print("Second module measure: ");
	sendTrigger(MODULE_2);
	EchoPulseWidth(&d);
	Serial.println(d);

	t += d;
	
	/****/

	Serial.print("Third module measure: ");
	sendTrigger(MODULE_3);
	EchoPulseWidth(&d);
	Serial.println(d);

	t += d;
	
	/****/

	Serial.print("Forth module measure: ");
	sendTrigger(MODULE_4);
	EchoPulseWidth(&d);
	Serial.println(d);

	t += d;

	/****/

	Serial.print("Fifth module measure: ");
	sendTrigger(MODULE_5);
	EchoPulseWidth(&d);
	Serial.println(d);

	t += d;

	/*** --Not working--

	Serial.print("Six module measure: ");
	sendTrigger(MODULE_6);
	EchoPulseWidth(&d, MODULE_6);
	Serial.println(d);*/

	/****/

	Serial.print("Seven module measure: ");
	sendTrigger(MODULE_7);
	EchoPulseWidth(&d);
	Serial.println(d);

	t += d;

	/****/

	Serial.print("Eight module measure: ");
	sendTrigger(MODULE_8);
	EchoPulseWidth(&d);
	Serial.println(d);

	t += d;

	/****/

	total = t * 0.058;
	Serial.print("total time in ms: ");
	Serial.println(total);

	Serial.println("*****************");
}

void ShowSerialInfo() {
	Serial.println("*** Values measured ***");
	for (int i = 0; i < 8; i++)
	{	
		Serial.print("Position index: ["); Serial.print(i); Serial.print("] value: ( "); Serial.print(Dist.Measures[i]); Serial.println(" )");
	}
	Serial.println("*** Far modules ***");
	for (int i = 0; i < 8; i++)
	{
		Serial.print("Position index: ["); Serial.print(i); Serial.print("] value: ( "); Serial.print(Dist.far[i]); Serial.println(" )");
	}
	Serial.println("*** Medium modules ***");
	for (int i = 0; i < 8; i++)
	{
		Serial.print("Position index: ["); Serial.print(i); Serial.print("] value: ( "); Serial.print(Dist.medium[i]); Serial.println(" )");
	}
	Serial.println("*** Close modules ***");
	for (int i = 0; i < 8; i++)
	{
		Serial.print("Position index: ["); Serial.print(i); Serial.print("] value: ( "); Serial.print(Dist.close[i]); Serial.println(" )");
	}
}
