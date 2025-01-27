const int LED = 13; 
int brightness = 255;
const int fadeAMOUNT = 5;

void setup() {
  pinMode(LED, OUTPUT); // Set the LED pin as an output
}

void loop() {
  if(brightness = 255){
    analogWrite(LED, 255); // Turn the LED on (full brightness)
    delay(500);               // Wait for 250 milliseconds (0.25 second)
    analogWrite(LED, 0);   // Turn the LED off
    delay(500);               // Wait for 250 milliseconds (0.25 second)
  }  
  do{
    analogWrite(LED, brightness); 
    delay(30);
    brightness -= fadeAMOUNT;                       // Wait for 30 milliseconds
  }while(brightness != 0);

  // Optional: Pause before repeating the loop
  delay(500);
  }