/*Octopus engine - oeLAB - 2017/03 TEST - 2020 Hamik164
                    ATtiny 85 
                RST =--U--= VCC        oeLAB dev board1                  
> ANALOG_PIN (A) P3 =     = P2 (A1) (3) i2c Clock 
<    UART TX (A) P4 =     = P1 /    (2) > LED 
                GND =     = P0 /  > (1) i2c Data 
               
> Arduino UNO serial display TTF 320x240*/

#include <SoftwareSerial.h> 

#define RX    3  
#define TX    4  
#define LED1_PIN        1              
#define LED2_PIN        5  
#define ANALOG_PIN      3 

int sensorValue = 0;  // variable to store the value coming from the sensor
SoftwareSerial TSerial(RX, TX); //TSerial for Attiny

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED1_PIN, OUTPUT); //LED_BUILTIN
  //pinMode(ledB, OUTPUT);
  //digitalWrite(ledB, LOW);
  
   delay(5000); //waiting for serial display init
   TSerial.begin(9600); //115200 (v.2020)
   
   //communication with serial monitor:
   TSerial.println("C"); //clear display
   delay(50);
   
   //initial screen:
   TSerial.print("W7");  //change color
   TSerial.print("h");   //horizontal line
   TSerial.print(10);    //set y position 
   delay(20);
   TSerial.print("h");   //horizontal line
   TSerial.print(180);   //set y position
   delay(20);
   TSerial.print("R1QATtiny - serial display*");
   TSerial.print("R9Qoctopuslab.cz*");
   delay(20);
 
   TSerial.print("R5W1R5Q...*");   
}

int cnt = 0; // counter
// the loop function runs over and over again forever
void loop() {
  // blink - wait for a "second"
  digitalWrite(LED1_PIN, HIGH);  
  delay(200);                      
  digitalWrite(LED1_PIN, LOW);  
  delay(800);                      
  
  // read the value from the sensor:
  sensorValue = analogRead(ANALOG_PIN);

  TSerial.print("Q");
  TSerial.print(String(cnt));
  TSerial.print(": ");
  TSerial.print(String(sensorValue));
  TSerial.print("*");

  cnt++;
}
