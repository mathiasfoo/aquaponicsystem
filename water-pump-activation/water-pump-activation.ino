#define MOISTURE_PIN A2  // define the analog input pin for the soil moisture sensor

 int soilMoisture;  

void setup() {
    Serial.begin(9600); // Initialise serial communication for data readout
    pinMode(5, OUTPUT); // Assign pump output pins
    pinMode(6, OUTPUT);
    digitalWrite(5, LOW); // Ensure pump is off initially
    digitalWrite(6, LOW);
}

void loop() {
  digitalWrite(5, LOW); // Ensure pump is off when no conditions are satisfied
  digitalWrite(6, LOW);

  soilMoisture = analogRead(MOISTURE_PIN); // Reading and printing soil moisture value
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisture);

  if ((soilMoisture < 400) && (soilMoisture >= 0)) { // If soil moisture value is 0 - 399
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(1500);          // Turn on water pump for 1.5 seconds
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(2000);         // Turn off water pump for 2 seconds
    } 
    else if ((soilMoisture >= 400) && (soilMoisture < 600)) { // If soil moisture value is 400 - 600
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH);
      delay(1000);          // Turn on pump for 1 second
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(6000);         // Turn off water pump for 6 seconds
    }
    else if (soilMoisture >= 600) { // If soil moisture value is larger than 600
        digitalWrite(5, LOW); // Turn off water pump
        digitalWrite(6, LOW);
        
    }
    delay(4000); // Delay for 4 seconds between each soil moisture reading
}

