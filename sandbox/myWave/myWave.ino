// myWave.ino
// #include "Waveforms.h"

int value = 0;
int DACBits = 12;
int input = 0;
// unsigned long reg = REG_ADC_MR;
// REG_ADC_MR = (REG_ADC_MR & 0xFFF0FFFF) | 0x00020000;

void setup() {
  // Serial.begin(115200);
	analogWriteResolution(DACBits);  // set the analog output resolution to DACBits bit (4096 levels)
  analogReadResolution(DACBits);
}

void loop() {
  // Serial.print("REG_ADC_MR = ");
  // Serial.println(reg, HEX);
  input = analogRead(A0);
  // Serial.print(" input: ");
  // Serial.println(input);
  analogWrite(DAC1, input);
  // delayMicroseconds(1);
  // analogWrite(DAC1, 0);
  // delayMicroseconds(1);
  // i++;
  // if (i == maxSamplesNum) i = 0; // Reset
}
//IDO 0544997948
