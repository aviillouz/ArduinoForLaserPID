// analogWriteSerial.ino
// write serial input to DAC

//used for ascii - integer conversions
const int ASCII_ZERO = 48;

//number of bits (resolution)
int bits = 12;

// for incoming serial data
int incomingByte = 0;
int incomingValue = 0; 

void setup() {

	Serial.begin(115200);

	//set serial listen timeout to 10 ms
	Serial.setTimeout(10);

	analogWriteResolution(12);
}

void loop() {
	if (Serial.available() > 0) {
		incomingByte = Serial.parseInt();
		
		Serial.print("received: ");
		//print 3 digits after the floating point
        Serial.println(incomingByte, DEC);

        analogWrite(DAC1, constrain(incomingByte,0,2000));
	}
}

int asciiToInt (int asciiChar){
	return asciiChar - ASCII_ZERO;
}





