String readString;

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT); // Control Forward
  pinMode(8, OUTPUT); // Control Backward
  pinMode(9, OUTPUT); //PWM -- speed
  pinMode(13, OUTPUT); // handles the LED
  pinMode(2, OUTPUT); // Control Forward
  pinMode(4, OUTPUT); // Control Backward
  pinMode(3, OUTPUT); // PWM -- speed
}

void loop() {
  while(Serial.available()) {
      delay(3);
      // reads from serial monitor
      char c = Serial.read();
      // adds it to a string
      readString += c;  
    }
    // checks to see if we're receiving anything
    if (readString.length() > 0) {
        Serial.print(readString);
        Serial.print("\n");
        // logic
        if (readString == "for") {
            digitalWrite(13, HIGH); // turns on LED on
            digitalWrite(8, HIGH);
            digitalWrite(7, LOW);
            analogWrite(9, 255);
            digitalWrite(2, HIGH);
            digitalWrite(4, LOW);
            analogWrite(3, 255);
        }
        if (readString == "back") {
          digitalWrite(8, LOW);
          digitalWrite(7, HIGH);
          analogWrite(9, 255);
          digitalWrite(2, LOW);
          digitalWrite(4, HIGH);
          analogWrite(3, 255);
        }
        if (readString == "stop"){
            digitalWrite(8, LOW);
            digitalWrite(7, LOW);
            analogWrite(9, 0);
            digitalWrite(2, LOW);
            digitalWrite(4, LOW);
            analogWrite(3, 0);
            digitalWrite(13, LOW); // turns LED off
        }  
        // resets the string
        readString = "";
      }
} 
