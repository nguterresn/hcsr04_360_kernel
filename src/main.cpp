#include <Arduino.h>

extern "C" {
   #include "hcsr04.h"
   #include "blink.h"
   #include "schedule.h"
   #include "hcsr04_handler.h"
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

void setup() {

	Serial.begin(9600);
	Sched_Init();

	Serial.println("LED TEST - Started!");
	Sched_AddTask(Test_Builtin_Led, 0, 0);
	Serial.println("LED TEST - Ended!");

	Sched_AddTask(Setup_All_Modules, 0, 0);

	Sched_AddTask(Test_All_Modules, 0, 0);
}

void loop() {
	Sched_Dispatch();
}