// analogReadToSerial.ino
// Read ADC to Serial monitor

//used for ascii - integer conversions
const int ASCII_ZERO = 48;

//number of bits (resolution)
int bits = 12;

void setup() {

	Serial.begin(9600);

	//set serial listen timeout to 10 ms
	// Serial.setTimeout(10);
	// analogWriteResolution(12);
	analogReadResolution(bits);
}

void loop() {
	Serial.print("Voltage at A0: ");
	Serial.println(analogRead(A0));
	delay(1000);
}


int asciiToInt (int asciiChar){
	return asciiChar - ASCII_ZERO;
}







