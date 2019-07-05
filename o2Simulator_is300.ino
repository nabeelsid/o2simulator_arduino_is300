#include <time.h>
int ledPin1 = 3;
int ledPin2 = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
      /*create a random number between 3400 and 3100 milliseconds so the ecu does not know its simulated
       * formula for random number: num = (rand() % (upperRange - lowerRange + 1)) + lowerRange;
       * is300 ecu expects voltage flip approximately every 3.3 seconds
       */
      int num1 = (rand() % (3400 - 2800 )) + 2800; 
      int num2 = (rand() % (3400 - 2800 )) + 2800;
      o2Sim1(num1);
      o2Sim2(num2);
}

void o2Sim1(int i) //function takes a the random int generated to give out random pulse for first bank cat
{
  for (int fadeValue = 5  ; fadeValue <= 37; fadeValue += 1) {
    analogWrite(ledPin1, fadeValue);
    delay(10); //just to give out a smooth ramp up of voltage 
  }
  
  delay(i); //random delay between upper and lower bounds
  Serial.print("bank1 time: ");
  Serial.println(i); //just for debugging purposes not required for the code to run
  
  for (int fadeValue = 37 ; fadeValue >= 5; fadeValue -= 1) {
    analogWrite(ledPin1, fadeValue); //fade value 37 gives out 0.7v
    delay(10); //just to give out a smooth ramp up of voltage 
  }
  
}
void o2Sim2(int i) //same function as the o2Sim1() except for second bank cat
{
  for (int fadeValue = 5 ; fadeValue <= 37; fadeValue += 1) {
    analogWrite(ledPin2, fadeValue);
    delay(10); //just to give out a smooth ramp up of voltage 
  }
  
  delay(i); //3.3 seconds on
  Serial.print("bank2 time: ");
  Serial.println(i); //just for debugging purposes not required for the code to run
  
  for (int fadeValue = 37 ; fadeValue >= 5; fadeValue -= 1) {
    analogWrite(ledPin2, fadeValue); //fade value 37 gives out 0.7v
    delay(10); //just to give out a smooth ramp up of voltage 
  }
  
}
