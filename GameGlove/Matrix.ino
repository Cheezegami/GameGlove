#include <Wire.h>
int i2c_LEDMatrix = 0x70;

void matrixSetup() {
  Wire.begin();
  Wire.beginTransmission(i2c_LEDMatrix);
  Wire.write(0x21); 
  Wire.endTransmission();
}

void _matrixBlink(byte mode) {
  Wire.beginTransmission(i2c_LEDMatrix);
  Wire.write(0x80 | mode);
  Wire.endTransmission();
}

void  matrixBlinkoff() {
  _matrixBlink(0x1);
}

void  matrixBlink2Hz() {
  _matrixBlink(0x3);
}

void matrixBlink1Hz() {
  _matrixBlink(0x5);
}

void matrixBlinkHalfHz() {
  _matrixBlink(0x7);
}


void matrixBrightness (byte sixteenth) {
  Wire.beginTransmission(i2c_LEDMatrix);  
  Wire.write(0xE0 | constrain(sixteenth,0,15));
  Wire.endTransmission();
}

void matrixPattern(byte patt[]){
  Wire.beginTransmission(i2c_LEDMatrix);
  Wire.write(0x00);

  for (int i = 7; i >= 0; i--) {
    Wire.write(_fix(patt[i]));
    Wire.write(0x00);
  }
 
  Wire.endTransmission();
}

byte _fix(byte orig) {
  return orig >> 1 | orig << 7;
}
