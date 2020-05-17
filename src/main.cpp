#include <Arduino.h>

extern "C" {
   #include "hcsr04.h"
   #include "blink.h"
   #include "schedule.h"
   #include "hcsr04_handler.h"
}

void mod1 () {
	sendTrigger(MODULE_1);
	EchoPulseWidth(&Measures[0]);
	Serial.println(Measures[0]);
}

void mod2 () {
	sendTrigger(MODULE_2);
	EchoPulseWidth(&Measures[1]);
	Serial.println(Measures[1]);
}

void mod3 () {
	sendTrigger(MODULE_3);
	EchoPulseWidth(&Measures[2]);
	Serial.println(Measures[2]);
}

void mod4 () {
	sendTrigger(MODULE_4);
	EchoPulseWidth(&Measures[3]);
	Serial.println(Measures[3]);
}

void mod5 () {
	sendTrigger(MODULE_5);
	EchoPulseWidth(&Measures[4]);
	Serial.println(Measures[4]);
}

void mod7 () {
	sendTrigger(MODULE_7);
	EchoPulseWidth(&Measures[5]);
	Serial.println(Measures[5]);
}

void mod8 () {
	sendTrigger(MODULE_8);
	EchoPulseWidth(&Measures[6]);
	Serial.println(Measures[6]);
}

void setup() {

	Serial.begin(9600);
	Sched_Init();

	Serial.println("LED TEST - Started!");
	Sched_AddTask(Test_Builtin_Led, 0, 0);
	Serial.println("LED TEST - Ended!");

	Sched_AddTask(Setup_All_Modules, 0, 0);
	
	/** period with last func to organize priority */
	Sched_AddTask(mod1, 100, 0); 
	Sched_AddTask(mod2, 100, 0);
	Sched_AddTask(mod3, 100, 0);
	Sched_AddTask(mod4, 100, 0);
	Sched_AddTask(mod5, 100, 0);
	Sched_AddTask(mod7, 100, 0);
	Sched_AddTask(mod8, 100, 0);

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
