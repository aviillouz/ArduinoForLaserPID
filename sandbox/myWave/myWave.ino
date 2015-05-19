// myWave.ino

int DACBits = 12;

//PID global variables
double Setpoint, Input, Output;
double k1 = 2;  
double k2 = 5;
double previousSignal;
double previousError;

void setup() {
  // Serial.begin(115200);
	analogWriteResolution(DACBits);  
  analogReadResolution(DACBits);
  Input = analogRead(A0);
  Setpoint = 100;
}

void loop() {
	//Read voltage from wavemeter
  Input = analogRead(A0);

  //Convert to error from setpoint //TODO
	double CurrentError;

	//Calculate Output
	Output = previousSignal + k1*CurrentError - k2*previousError;
	previousError = CurrentError;
	previousSignal = Output;
  // analogWrite(DAC1, Output);
  analogWrite(DAC1, Input);
}

//TODO connect to AOM
//go to lab setup




