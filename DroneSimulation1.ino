int enA = 11;
int in1 = 10;
int in2 = 9;
// Motor B connections
int enB = 6;
int in3 = 5;
int in4 = 3;
const int trigPin1   = 13;
const int echoPin1  = 12;
// defines variables
long duration1;
int distance1;
const int trigPin2 = 2;
const int echoPin2 = 7;
// defines variables
long duration2;
int distance2;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);  
}

void loop() {
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);                                   // Sets the trigPin on HIGH state for 10 micro seconds
 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);                                   // Sets the trigPin on HIGH state for 10 micro seconds
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin2, LOW);

 
   duration1 = pulseIn(echoPin1, HIGH);
   // Calculating the distance for the ulrasonic 1
   distance1= duration1*0.034/2;
   duration2 = pulseIn(echoPin2, HIGH);
    // Calculating the distance
   distance2 = duration2*0.034/2;
   Avance();
   if (distance1<100){
     if(distance2>100)
      GoRight();
    
    else if (distance2<100)
      GoLeft();
     
    
   else
       descender();
   }
}

// This function lets you control spinning direction of motors

void GoRight(){
   analogWrite(enA, 250);
   analogWrite(enB, 200); // j'ai choisi au hasard, normalement ca besoin d'une etude d'equilibre pour trouver la bonne valeur a fin de guarentir l'equilibre.
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
 
}
void GoLeft(){
   analogWrite(enA, 200);
   analogWrite(enB, 250); 
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
}
void Avance(){
   analogWrite(enA, 250);
   analogWrite(enB, 250); 
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH); 
}
void reculer(){
   analogWrite(enA, 250);
   analogWrite(enB, 250);  // j;ai choisi au hasard ,normalement ca besoin d'une etude d'equilibre pour trouver la bonne valeur a fin de guarentir l'equilibre.
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW); 
}
void descender(){
    
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}
