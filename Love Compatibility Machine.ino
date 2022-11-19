/* Use two photoresistors to turn on the red LED */

//constants
const int photoResistor1 = A0; // Photoresistor1 at Arduino analog pin A0
int photoResistor2 = A1; //Photoresistor2 at Arduino analog pin A1
//positions for LED
const int redLed = 10; // Red Led pin at Arduino pin 10
const int blueLed = 9; // Blue Led pin at Arduino pin 9
//variables
int lightValue;
int lightValue2;  // Store value from photoresistor (0-1023)

void setup() {
  //light into the photoresistor is input, LED is output //Serial.begin(9600);
//Set Red Lep Pin - 10 & Blue Led Pin - 9 as output
pinMode(redLed, OUTPUT);
pinMode(blueLed, OUTPUT);
Serial.begin(9600);
//Set photoResistor1 - A0 & photoResistor2 - A1 as input
pinMode(photoResistor1, INPUT);
pinMode(photoResistor2, INPUT);
}

void loop() {
  lightValue = analogRead(photoResistor1);
  lightValue2 = analogRead(photoResistor2);
  Serial.println("light1:");
  Serial.println(lightValue);
  Serial.println("light2:");
  Serial.println(lightValue2);

//Blue LED turn on when the two photocells not equal
 if (lightValue > 70 || lightValue2 > 70) {
digitalWrite(blueLed, HIGH); 
} else {
digitalWrite(blueLed, LOW);
}

//Red LED turn on -- "love"
if (lightValue < 30 && lightValue2 < 30 ){
digitalWrite(redLed, HIGH);
} else if (lightValue < 70 && lightValue2 == 70){
  digitalWrite(redLed, HIGH);
} else {
 digitalWrite(redLed, LOW);
}

}
