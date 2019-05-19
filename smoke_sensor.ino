int redLed = 12;
int greenLed = 8;
int buzzer = 10;
int smokeA0 = A5;
int notes[] = {262, 294, 330, 349};
int analogPin = A0;
int analogInput;
double fTemp;
double cTemp;
// Your threshold value
int sensorThres = 645;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}


void loop() {
  int analogSensor = analogRead(smokeA0);
  analogInput = analogRead(A0);
  cTemp = (double)analogInput / 1024 * 5;
  cTemp = cTemp - 0.5;
  cTemp = cTemp * 100;

  fTemp = (cTemp * 9 / 5) + 32;
  //Serial.print("TEMP:");
  //Serial.println(fTemp);
  
  //Serial.print("Pin A0: ");
  //Serial.println(analogSensor);
  // Checks if it has reached the threshold value
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
