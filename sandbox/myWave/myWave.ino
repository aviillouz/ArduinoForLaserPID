// myWave.ino
// #include "Waveforms.h"
#include <PID_v1.h>
//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,0, DIRECT);

int value = 0;
int DACBits = 12;
int input = 0;

void setup() {
  Serial.begin(115200);
	analogWriteResolution(DACBits);  
  analogReadResolution(DACBits);
  Input = analogRead(A0);
  Setpoint = 1000;

  //turn the PID on
  myPID.SetOutputLimits(0,4000);
  myPID.SetMode(AUTOMATIC);

}

void loop() {
  Input = analogRead(A0);
  myPID.Compute();
  analogWrite(DAC1, Input);
  //gitg comment
}
//IDO 0544997948
