//#define bitGet(p,m) ((p) & (m))  
// Get the value of a bit: bitGet(PORTB, BIT(5));  

//#define bitSet(p,m) ((p) |= (m))  
// Set the value of a bit (set it to 1), like bitSet(PORTB, BIT(2));  

//#define bitClear(p,m) ((p) &= ~(m))  
// Clear a bit (set it to 0), like bitClear(PORTB, BIT(2));

#define GET_BIT(X,N) ( ( (X) >> (N) ) & 1 )
#define SET_BIT(X,N) ( (X) |  (1 << (N) ) )
#define RST_BIT(X,N) ( (X) & ~(1 << (N) ) )

#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit))) 
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit))) 
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit))) 
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))  

//example:


void setup() 
{  
DDRB = 0b00000010; //Data Direction (PB1 = out)  
PORTB = 0b0011000; //pull-up for PB3, BB4 (in)

if (bitcheck(PORTB, 5)) { bitset( PORTB ,2); } 
} 

void loop() 
{ 
if ((PINB & 0b00001000) && (PINB & 0b00010000)) //A, B  
  {  
   //PORTB |= 0b00000010; //PB1 to HIGH (LED on) 
   SET_BIT(PORTB, 2);
  } 
else 
  {  
  PORTB &= 0b11111101; //PB1 to LOW (LED off)
  } 
}
