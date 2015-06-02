#include <PID_v1.h>
int DACBits = 12;

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,0, DIRECT);

void setup()
{
  Setpoint = 1000;
	Serial.begin(115200);
  
  analogWriteResolution(DACBits); 
  analogReadResolution(DACBits);
  Input = analogRead(A0);


  //turn the PID on
  myPID.SetOutputLimits(0,3000);
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
	Input = analogRead(A0);
	myPID.Compute();
	analogWrite(DAC1, Output);
	print();
	delay(100);
}

void print(){
  Serial.print(millis());
  Serial.print(",");
  Serial.print(Setpoint);
  Serial.print(",");
  Serial.print(Input);
  Serial.print(",");
  Serial.print(Output);
  Serial.println();
}



