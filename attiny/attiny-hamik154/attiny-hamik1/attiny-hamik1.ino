/*
attiny-05-i2c2timer.ino
Octopus engine - oeLAB - 2018/07 TEST

ATtiny85 as an I2C Slave  BroHogan 2011/12
 * Example of ATtiny I2C slave receiving and sending data to an Arduino master.
 * SETUP:
 * NOTE! - It's very important to use pullups on the SDA & SCL lines!
 * http://astromik.org/raspi/i2cmultiplex/attiny_1.ino

                Attiny 85 
                RST =--U--= VCC         oeLAB dev board1                  
 > pinAn/Rx (A) P3 =     = P2 (A1) (3) i2c Clock 
        /Tx (A) P4 =     = P1 /    (2) > LED 
               GND =     = P0 /  > (1) i2c Data 
               
> Arduino UNO serial display TTF 320x240                
*/
#define LED_PIN  1              // ATtiny 

void Blink(byte led, byte times){ 
  for (byte i=0; i< times; i++){
    digitalWrite(led,HIGH);
    delay (500);
    digitalWrite(led,LOW);
    delay (500);
  }
}

void setup(){
  pinMode(LED_PIN,OUTPUT);
  //Blink(LED_PIN,3);              

}

void loop(){
    Blink(LED_PIN,1);                  // show we transmitted
  }
