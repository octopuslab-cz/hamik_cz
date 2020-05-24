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
#define LED_PIN  1              // P1 > LED 
// port: 478 B
// digi: 684 B

void Blink(byte led, byte times){ 
  for (byte i=0; i< times; i++){
    //digitalWrite(led,HIGH);
    PORTB = 0b0000010; // PB2 nastavit do HIGH   
    delay (100);
    //digitalWrite(led,LOW);    
    PORTB &= 0b11111101; // prepnuti vystupu PB1 do LOW - ostatni hodnoty jsou beze zmeny
    delay (100);
  }
}

void setup(){
  //pinMode(LED_PIN,OUTPUT);
  DDRB = 0b00000010;  // nastaveni smeru signalu na portu B ("1" = vystup ; "0" = vstup)
  ///PORTB = 0b0011100; // pull-up pro vstup (PB2) a zaroven vystupy PB3 a PB4 nastavit do HIGH              

}

void loop(){
    Blink(LED_PIN,1);                  // show we transmitted
  }
