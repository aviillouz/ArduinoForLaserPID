// myWave.ino

int DACBits = 12;

//PID global variables
double Setpoint = 0, Input = 0, Output = 0;
double k1 = 2;  
double k2 = 5;
double previousSignal = 0;
double previousError = 0;

int incomingByte = 0 ; //incoming serial byte
int testSignal = 4000;
int testDirection = 1;

void setup() {
	Serial.begin(115200);
	//set serial listen timeout
	Serial.setTimeout(1);

	analogWriteResolution(DACBits);  
	analogReadResolution(DACBits);
	Input = analogRead(A0);
	Setpoint = 1000;
	Serial.println("time(ms),Setpoint,Input,Output,CurrentError,previousSignal,previousError");
}

void loop() {
	//Read voltage from wavemeter
  Input = analogRead(A0);


 //  if (Serial.available() > 0) {
	// 	incomingByte = Serial.parseInt();
		
	// 	Serial.print("new Setpoint: ");
	// 	//print 3 digits after the floating point
 //    Serial.println(incomingByte, DEC);

 //    Setpoint = constrain(incomingByte,0,4000);
	// }


  //Convert to error from setpoint //TODO
	double CurrentError = Setpoint - Input;

	//Calculate Output
	Output = previousSignal + k1*CurrentError - k2*previousError;
	previousError = CurrentError;
	previousSignal = Output;
  // analogWrite(DAC1, Output);
  //Serial.print("In: ");
  //Serial.println(Input);
  //Serial.print("Out: ");
  //Serial.println(Output);

  // testSignal += testDirection;
  // if(testSignal <= 0){
  //     testDirection = 1;
  // }
  // if(testSignal >= 4000){
  // 	testDirection = -1;
  // }
  // Output = testSignal;
  Serial.print(millis());
  Serial.print(",");
  Serial.print(Setpoint);
  Serial.print(",");
  Serial.print(Input);
  Serial.print(",");
	Serial.print(Output);
	Serial.print(",");
	Serial.print(CurrentError);
	Serial.print(",");
	Serial.print(previousSignal);
	Serial.print(",");
	Serial.print(previousError);
  Serial.println();
  analogWrite(DAC1, Output);
}






