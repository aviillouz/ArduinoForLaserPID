/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

 #include <PID_v1.h>

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,0, DIRECT);

void setup()
{
	Serial.begin(9600);
  //initialize the variables we're linked to
  analogWriteResolution(12);
  // Input = analogRead(A0);
  Input = analogRead(A0);

  Setpoint = 2000;

  //turn the PID on
  myPID.SetOutputLimits(0,4000);
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
	Input = analogRead(A0);
	myPID.Compute();
	analogWrite(DAC0, Output);
	delay(100);
	Serial.print("Input: ");
	Serial.print(Input);
	Serial.print(", Setpoint: ");
	Serial.print(Setpoint);
	Serial.print(" -> Output: ");
	Serial.println(Output);
}



