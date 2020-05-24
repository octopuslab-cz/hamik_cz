/*
attiny-01-blink.ino
Octopus engine - oeLAB - 2018/07 TEST (916B)
                Attiny 13/85 
                RST =--U--= VCC         oeLAB dev board1                  
 > pinAn/Rx (A) P3 =     = P2 (A1) (3) i2c Clock 
        /Tx (A) P4 =     = P1 /    (2) > LED 
               GND =     = P0 /  > (1) i2c Data 
*/
#define LED1_PIN        1  //LED_BUILTIN = Led2  
#define S2_PIN          3  // RED S2
int buttonState = 0; 

// the setup function runs once when you press reset or power the board
void setup() {  
  pinMode(LED1_PIN, OUTPUT); // initialize digital pin as an output
  pinMode(S2_PIN, INPUT);

  for (int i = 0; i<2; i++) {
    blink(300); // start test
  }
}

// the loop function runs over and over again forever
void loop() {
  blink(300); 
  buttonState = digitalRead(S2_PIN);
  if (buttonState == HIGH) {
    digitalWrite(LED1_PIN, HIGH);
    delay(10); 
  } else {
    digitalWrite(LED1_PIN, LOW); 
    delay(1000);
  }               

              
}

void blink(int pause) {
  digitalWrite(LED1_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(pause);                     // wait for a second
  digitalWrite(LED1_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(pause);          
}
