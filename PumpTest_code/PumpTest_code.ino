int count = 0;           //A count variable initially set to 0 when the board is powered on
void setup() {
  // put your setup code here, to run once:
 pinMode(5, OUTPUT);     // Pins 5 and 6 are used to send/output signals to the pump
 pinMode(6, OUTPUT);     //

 digitalWrite(5, LOW);   //Initially pump pins are set to low which keeps them turned off
 digitalWrite(6, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

if (count == 0){           //if count is 0
  delay(20000);            //delay 20000ms (20seconds)
  digitalWrite(5, HIGH);   //Turn on pump
  digitalWrite(6, HIGH);
  
  count = 1;   //After pump has operated, count is now 1
}              // The code in the brackets after void loop will repeat with count = 1 now
               
else{                     //If count is 1(not zero) which occurs after the pump has turned on.
  digitalWrite(5, LOW);   //Turns off pumps after running for 20 seconds.
  digitalWrite(6, LOW);   
}                         
}             // The code in the brackets after void loop will now repeat,pump will now stay off
              //count is now 1 so loop will always go to else statement
              //Only way to turn on pump now is to restart Arduino,press reset button on board
              //Or unplug power supply and plug in again to restart code from beginning
