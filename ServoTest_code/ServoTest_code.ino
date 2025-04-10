#include <Servo.h>       //includes the servo control library,downloaded from Arduino IDE
Servo ServoA;            //Sets up a servo called "ServoA"
int initial_pos = 90;    //Sets up a variable for intial positon of servo (Disc closed position)


void setup() {
  // put your setup code here, to run once:
ServoA.attach(10);           //Sets up servo to pin 10 which is the digital pin it's attached to 
ServoA.write(initial_pos);   //on the Arduino board and sets it to its initial position (closed)


}

void loop() {
  // put your main code here, to run repeatedly:
servoMove();            // Will continually run servoMove() function

}

void servoMove() {
  ServoA.write(180);           //Moves servo to another position (open)
  delay(2000);                 //waits 2 seconds
  ServoA.write(initial_pos);   //Moves back to initial position (closed)
  delay(2000);                 //Waits at closed position for 2 seconds
}
