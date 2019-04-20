
const int tmp = A2;
const int p = 8;

void setup() {

  Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop() {
 
  int Temp = analogRead(tmp);
  float volts = (Temp / 965.0) * 5;
  float c = ( .5 - volts) * 55;
  float f = (c * 9 / 5 + 32);
  Serial.println(c);
 
  delay(3000);
  // put your main code here, to run repeatedly:

}
