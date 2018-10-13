const int SpeakerPin = 4;
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;
int safetyDistance;

void setup() {
  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication

}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;

if (safetyDistance <= 40 && safetyDistance > 0){
  
  tone(SpeakerPin, 1000, 100);
  delay(200);

}

if(safetyDistance >= 41 && safetyDistance < 80){
  tone(SpeakerPin, 600, 100);
  delay(400);  
}

if(safetyDistance >= 81 && safetyDistance < 120){
  
  tone(SpeakerPin, 200, 100);
  delay(600);
  
}

Serial.println(safetyDistance);
delay(200);
}
