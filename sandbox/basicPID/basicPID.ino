#include <PID_v1.h>
int DACBits = 12;

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,0, DIRECT);

void setup()
{
	Serial.begin(115200);
  
  analogWriteResolution(DACBits); 
  analogReadResolution(DACBits);
  // Input = analogRead(A0);
  Input = analogRead(A0);

  Setpoint = Input;

  //turn the PID on
  myPID.SetOutputLimits(0,4000);
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
	Input = analogRead(A0);
	myPID.Compute();
	analogWrite(DAC1, Input);
	delay(100);
	Serial.print("Input: ");
	Serial.print(Input);
	Serial.print(", Setpoint: ");
	Serial.print(Setpoint);
	Serial.print(" -> Output: ");
	Serial.println(Output);
}



