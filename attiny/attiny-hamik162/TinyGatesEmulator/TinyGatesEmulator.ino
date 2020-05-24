// Simulátor dvou hradel
// during holding button you can select type of gate by presing buttons on inputs

// flipflop
// RS hradlo

#include <TinyWireM.h>
#define PCF TinyWireM
#define PCF_ADDRESS 0x20
#define button 4 // pin 3

int combination;
byte Inputs_byte;
byte Output_byte = 255;
bool In1;
bool In2;
bool In3;
bool In4;
bool In5;
bool In6;
bool In7;
bool In8;
bool Out1 = true;
bool Out2 = true;
bool Out3 = true;
bool Out4 = true;
bool Out5 = true;
bool Out6 = true;
bool Out7 = true;
bool Out8 = true;

void setup() {
  pinMode(button, INPUT_PULLUP);
  PCF.begin();
  combination = 1;
}

void loop() {
  // selects type of gates
  if (digitalRead(button) == false) {
    combination += 1; // do change of combination
    if (combination > 3) {combination = 1; Output_byte = 243;} // 12
    if (combination == 2) Output_byte = 63; // 192
    if (combination == 3) Output_byte = 51; // 204
    PCF.beginTransmission(PCF_ADDRESS);
    PCF.write(Output_byte);
    PCF.endTransmission();
    delay(1500);
  //else {
  }

//read the data
  PCF.requestFrom(PCF_ADDRESS, 1);
  while (!PCF.available()){}
  Inputs_byte = PCF.read();

  In1 = (Inputs_byte & (1<<0));
  In2 = (Inputs_byte & (1<<1));
  In3 = (Inputs_byte & (1<<2));
  In4 = (Inputs_byte & (1<<3));
  In5 = (Inputs_byte & (1<<4));
  In6 = (Inputs_byte & (1<<5));
  In7 = (Inputs_byte & (1<<6));
  In8 = (Inputs_byte & (1<<7));

  switch (combination) {
    case 1: // two AND gates
      Out4 = !In1 & !In2;
      Out3 = !Out4;

      Out8 = !In5 & !In6;
      Out7 = !Out8;
      break;

    case 2: // two OR gates
      Out4 = !In1 | !In2;
      Out3 = !Out4;

      Out8 = !In5 | !In6;
      Out7 = !Out8;
      break;

    case 3: // two XOR gates
      Out4 = !In1 ^ !In2;
      Out3 = !Out4;

      Out8 = !In5 ^ !In6;
      Out7 = !Out8;
      break;
    
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }

  Out1 = true; // overwrite for input pin
  Out2 = true;
  Out5 = true;
  Out6 = true;

  //Outputs_byte =  Out1 + (Out2 * 2) + (Out3 * 4) + (Out4 * 8) + (Out5 * 16) + (Out6 * 32) + (Out7 * 64) + (Out8 * 128);
  Output_byte = 0;

  Output_byte |= Out1 << 0;
  Output_byte |= Out2 << 1;
  Output_byte |= Out3 << 2;
  Output_byte |= Out4 << 3;
  Output_byte |= Out5 << 4;
  Output_byte |= Out6 << 5;
  Output_byte |= Out7 << 6;
  Output_byte |= Out8 << 7;

//send the data
  PCF.beginTransmission(PCF_ADDRESS);
  PCF.write(Output_byte);
  PCF.endTransmission();

}
