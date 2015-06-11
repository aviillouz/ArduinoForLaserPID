// myWave.ino

int DACBits = 12;

//PID global variables
double Setpoint = 2000, Input = 0, Output = 0;
double k1 = 0.8;  
double k2 = 0.5;
double previousSignal = 0;
double previousError = 0;
double CurrentError = 0;
double Integral = 0;
double IntegralLimit = 4000;

void print();
void setup() {
	Serial.begin(115200);
	analogWriteResolution(DACBits);  
	analogReadResolution(DACBits);
	Input = analogRead(A0);
	Serial.println("time(ms),Setpoint,Input,Output,Error");
}

void loop() {
	//Read voltage from wavemeter
  Input = analogRead(A0);

  //Convert to error from setpoint
	CurrentError = Setpoint - Input;

	//Calculate Output
	Output += previousSignal + k1*CurrentError - k2*previousError;
  analogWrite(DAC1, Output);
	previousError = CurrentError;
  print(); 
  // delay(1);
}

void print(){
	Serial.print(millis());
  Serial.print(",");
  Serial.print(Setpoint);
  Serial.print(",");
  Serial.print(Input);
  Serial.print(",");
	Serial.print(Output);
	Serial.print(",");
	Serial.print(CurrentError);
  Serial.println();

}

//8.6.15 measurement, without print:
//1.6287V is 1.224mW
//pk-pk is 30mV. noise at 250Hz (4ms)
//(un controlled laser shows pk-pk 80mV
//noise at 212mHz (4.7s))
//control with printing adds "noise" of 20ms long
//and pk-pk is about 40mV






