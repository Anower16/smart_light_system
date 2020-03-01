int ledPin = 13; // choose the pin for the LED
int ledPin2 = 8;
int inputPin = 2; // choose the input pin (for PIR
sensor)
int ldrPin = A0;
int pirStatus = 0;
int val = 0; // variable for reading the pin
status
int timer = 0;
void setup() {
pinMode(ledPin, OUTPUT); // declare LED as output
pinMode(inputPin, INPUT); // declare sensor as input
pinMode(ledPin2, OUTPUT);
pinMode(ldrPin, INPUT);
Serial.begin(9600);
}
void loop(){
val = digitalRead(inputPin); // read input value
int ldrStatus = analogRead(ldrPin);
Serial.print("Timer: ");
Serial.print(timer);
if (val == HIGH) { // check if the input is HIGH
digitalWrite(ledPin, HIGH); // turn LED ON
digitalWrite(ledPin2, LOW); // turn off ldr led when pir is
on
pirStatus = 1;
timer = 0;
} else {
if(val == LOW && timer == 1500){
digitalWrite(ledPin, LOW);
pirStatus = 0;
timer = 0;
}
}
if (pirStatus == 0 && ldrStatus > 1013) {
digitalWrite(ledPin2, HIGH);
Serial.print(" Its DARK: ");
Serial.println(ldrStatus);
}
else{
digitalWrite(ledPin2, LOW);
Serial.print(" Its Bright: ");
Serial.println(ldrStatus);
}
timer++;
}