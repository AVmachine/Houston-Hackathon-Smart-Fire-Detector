//smoke sensor variables
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int sensorThres = 570; //threshold value for smoke sensor; can be changed
//temp sensor variables
double fTemp;
double cTemp;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(A5); //smoke sensor
  int analogInput = analogRead(A0); //temp sensor
  
  //converts analog input to celcius
  cTemp = (double)analogInput / 1024 * 5;
  cTemp = cTemp - 0.5;
  cTemp = cTemp * 100;
  // converts celcius to fahrenheit
  fTemp = (cTemp * 9 / 5) + 32;
  
  Serial.print("TEMPERATURE:");
  Serial.println(fTemp);
  Serial.print("SMOKE SENSOR: ");
  Serial.println(analogSensor);
  
  if (analogSensor > sensorThres && fTemp < 65)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 300);
    Serial.println("FIRE");
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(1000);
}
