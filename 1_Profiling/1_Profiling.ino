#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8

/*
 *  Task Profiling makes it easy track the Task being created in a project. 
 *  Three Tasks Profilers are created for three tasks controlling the LEDs. 
 */
typedef int TaskProfiler; //Typedef to create uniformity for TaskProfiler. 

TaskProfiler RedLeDProfiler;
TaskProfiler YellowLeDProfiler;
TaskProfiler BlueLeDProfiler;

void setup() {
   Serial.begin(9600); //Initiate UART
   
   xTaskCreate(redLedControllerTask,"RED LED Task",128,NULL,1,NULL);
   xTaskCreate(blueLedControllerTask,"BLUE LED Task",128,NULL,1,NULL);
   xTaskCreate(yellowLedControllerTask,"YELLOW LED Task",128,NULL,1,NULL);


}

void redLedControllerTask(void *pvParameters)
{
  pinMode(RED,OUTPUT);

  while(1)
  {
     RedLeDProfiler++;
     Serial.print("RedLEDProfiler : ");
     Serial.println(RedLEDProfiler);
     //digitalWrite(RED,digitalRead(RED)^1);
     delay(300);
  }
}

void  blueLedControllerTask(void *pvParameters)
{
 pinMode(BLUE,OUTPUT);

  while(1)
  {
    BlueLeDProfiler++;
    Serial.print("BlueLEDProfiler : ");
    Serial.println(BlueLEDProfiler);
    //digitalWrite(BLUE,digitalRead(BLUE)^1);
    delay(300);
  }
}

void yellowLedControllerTask(void *pvParameters)
{
  pinMode(YELLOW,OUTPUT);

  while(1)
  {
    YellowLeDProfiler++;
    Serial.print("YellowLEDProfiler : ");
    Serial.println(YellowLEDProfiler);
   
   // digitalWrite(YELLOW,digitalRead(YELLOW)^1);
  delay(300);
  }
}
void loop() {}
