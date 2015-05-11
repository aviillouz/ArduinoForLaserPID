int val;
void setup()
{

}
void loop()
{
  val = analogRead(A0);
  analogWrite(DAC1, val);
}