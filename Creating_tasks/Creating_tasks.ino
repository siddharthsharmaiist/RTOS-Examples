#include <Arduino_FreeRTOS.h>

// Defining tasks for three different tasks.1. RED LED Task 2. Yellow LED Task 3. Blue LED Task 
#define RED    6
#define YELLOW 7
#define BLUE   8

typedef int TaskProfiler;

TaskProfiler  RedLEDProfiler;
TaskProfiler  YellowLEDProfiler;
TaskProfiler  BlueLEDProfiler;

void setup()
{
  Serial.begin(9600);
  xTaskCreate(redLedControllerTask, "Red LED Task", 100, NULL, 1, NULL );
  xTaskCreate(blueLedControllerTask, "Blue LED Task", 100, NULL, 1,NULL);
  xTaskCreate(yellowLedControllerTask,"Yellow LED Task", 100, NULL, 1, NULL );
}

void redLedControllerTask(void *pvParameters)
{
  pinMode(RED,OUTPUT);
  while(1)
  {
   digitalWrite(RED,digitalRead(RED)^1); 
  }
}

void blueLedControllerTask(void *pvParameters)
{
  pinMode(BLUE,OUTPUT);
  while(1)
  {
   digitalWrite(BLUE,digitalRead(BLUE)^1); 
  }
}

void yellowLedControllerTask(void *pvParameters)
{
  pinMode(YELLOW,OUTPUT);
  while(1)
  {
    digitalWrite(YELLOW,digitalRead(YELLOW)^1);
  }
}

void loop(){}
