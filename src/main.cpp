#include <Arduino.h>

extern "C" {
   #include "hcsr04.h"
   #include "blink.h"
   #include "schedule.h"
   #include "hcsr04_handler.h"
}

void ShowSerialInfo();
void Test_All_Modules();

void setup() {

	Serial.begin(9600);

	/* Setup Trigger pins as outputs */
	Setup_All_Modules();

	/* Initializes struct variables */
	Setup_Distance();

	/* Initializes schedule */
	Sched_Init();

	/* Triggers and reads values from all sensores to measure a delay on to the next measure */
	Test_All_Modules();
	Serial.print("Initial Delay: "); Serial.println(Time.Global);

	/** Sorts by priority of distance - FAR, MEDIUM and CLOSE */
	Sched_AddTask(Distance_Handler, 0, 10000);
	//Sched_AddTask(Test_All_Modules, 0, 10000);
	Sched_AddTask(ShowSerialInfo, 0, 10000);

}

void loop() {
	Sched_Dispatch();
}

/** Trigger sensors without task scheduling */
void Test_All_Modules () {

	mod1();

	/****/

	mod2();
	
	/****/

	mod3();
	
	/****/

	mod4();

	/****/

	mod5();

	/*** --Not working--

	Serial.print("Six module measure: ");
	sendTrigger(MODULE_6);
	EchoPulseWidth(&d, MODULE_6);
	Serial.println(d);*/

	/****/

	mod7();

	/****/

	mod8();

	/****/
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
	Serial.println("*** Time by measure ***");
	Serial.print("Period Time: "); Serial.println(Time.Global);
	for (int i = 0; i < 8; i++)
	{
		Serial.print("Position index: ["); Serial.print(i); Serial.print("] Time: ( "); Serial.print(Time.Measures[i]); Serial.println(" )");
	}
	Time.Global = 0;
}
