int trigPin= 10;
int echoPin= 9;
 int counter = 0;
int currentState,previousState;
 void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 }
 
 void loop() {
   Serial.println("Animal Count");
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 
 if (distance <= 100){
 currentState = 1;
 }
 else {
 currentState = 0;
 }
 
 delay(200);
 if(currentState != previousState){
 if(currentState == 1){
 counter = counter + 1;
 
 if(counter>=5)
 Serial.println("Something is Fishy");
 delay(1000);
 
 }
 }
 }
