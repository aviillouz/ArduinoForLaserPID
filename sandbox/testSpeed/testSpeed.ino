// testSpeed.ino

int DACBits = 12;

//PID global variables
double Setpoint = 4000, Input = 0, Output = 0;
double kp = 1;  

void setup() {
	analogWriteResolution(DACBits);  
	analogReadResolution(DACBits);
}

void loop() {
  Input = analogRead(A0);
  Output = kp*(Setpoint - Input);
  analogWrite(DAC1, Output);
}






