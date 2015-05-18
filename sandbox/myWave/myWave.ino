// myWave.ino

//Define Variables we'll be connecting to
double Setpoint, Input, Output;
int DACBits = 12;

void setup() {
  // Serial.begin(115200);
	analogWriteResolution(DACBits);  
  analogReadResolution(DACBits);
  Input = analogRead(A0);
  Setpoint = 1000;
}

void loop() {
  Input = analogRead(A0);
  analogWrite(DAC1, gain*Input);
}



