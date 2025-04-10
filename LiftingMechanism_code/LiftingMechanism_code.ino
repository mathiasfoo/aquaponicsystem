#include <Servo.h> // Include the servo library

Servo servo1;      // Create servo objects
Servo servo2;
int pos = 10;      // Define starting/lowered position of servo

int soilMoisture; 
#define MOISTURE_PIN A0 // Define soil moisture analog pin

void setup() {
Serial.begin(9600); // Initialise serial communication for data readout

servo1.attach(9); // Assign digital pins to servos
servo2.attach(8);
servo1.write(pos); // Move servos to starting position
servo2.write(pos);
}

void loop() {
  soilMoisture = analogRead(MOISTURE_PIN); // Read and print soil moisture value
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisture);
  Serial.print("\t");

  if (soilMoisture >= 400 && pos == 10)  {    // If soil is moist and lid is lowered
    pos += 83;            // Rotate servo by 85 degrees - lifting lid
    servo1.write(pos);
    servo2.write(pos);
    delay(2000);           // Give servos time to rotate
    
  } 
  else if (soilMoisture < 400 && pos == 93) {     //If soil is dry and lid is lifted
    pos -= 83;       // Rotate servo in opposite direction by 85 degrees - lowering lid
    servo1.write(pos);
    servo2.write(pos);
    delay(2000);          // Give servos time to rotate
  }   
  delay(3000);        // Wait 3 seconds before taking soil moisture readings
}
  




  




