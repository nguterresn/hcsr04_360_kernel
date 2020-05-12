#include <Arduino.h>

extern "C" {
   #include "hcsr04.h"
   #include "blink.h"
   #include "schedule.h"
  // #include "hcsr04_handler.h"
}

void Setup_All_Modules() {

	setupHCSR04(MODULE_1);
	setupHCSR04(MODULE_2);
	setupHCSR04(MODULE_3);
	setupHCSR04(MODULE_4);
	setupHCSR04(MODULE_5);
	setupHCSR04(MODULE_6);
	setupHCSR04(MODULE_7);
	setupHCSR04(MODULE_8);
	Serial.println("setup is done");

}

void Test_All_Modules () {

	double d;

	Serial.print("First module measure: ");

	sendTrigger(MODULE_1);

	EchoPulseWidth(&d);

	Serial.println(d);

	/****/

	Serial.print("Second module measure: ");
	sendTrigger(MODULE_2);

	EchoPulseWidth(&d);

	Serial.println(d);

	/****/

	Serial.print("Third module measure: ");
	sendTrigger(MODULE_3);

	EchoPulseWidth(&d);

	Serial.println(d);

	/****/

	Serial.print("Fourth module measure: ");
	sendTrigger(MODULE_4);

	EchoPulseWidth(&d);

	Serial.println(d);

	/****/

	Serial.print("Fifth module measure: ");
	sendTrigger(MODULE_5);

	EchoPulseWidth(&d);

	Serial.println(d);

	/****/

	Serial.print("Sixth module measure: ");
	sendTrigger(MODULE_6);

	EchoPulseWidth(&d);

	Serial.println(d);

	/****/

	Serial.print("Seventh module measure: ");
	sendTrigger(MODULE_7);

	EchoPulseWidth(&d);

	Serial.println(d);

	/****/

	Serial.print("Eight module measure: ");
	sendTrigger(MODULE_8);

	EchoPulseWidth(&d);

	Serial.println(d);

	/****/

	Serial.println("*****************");

	delay(2000);

}

void setup() {

	Serial.begin(9600);
	Serial.println("LED TEST - Started!");
	Test_Builtin_Led();
	Serial.println("LED TEST - Ended!");

	Sched_Init();
	
	Sched_AddTask(Setup_All_Modules, 0, 0);

	Sched_AddTask(Test_All_Modules, 0, 2000);

}

void loop() {

	Sched_Dispatch();
}