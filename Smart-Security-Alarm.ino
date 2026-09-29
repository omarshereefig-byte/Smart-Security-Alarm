int pirPin = 13;
int motion = 0;
int tregPin =4;
int echoPin = 3;
float distance;
float timeInverval;
int buzzerPin = 10;

void setup() {

  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pirPin,INPUT);
pinMode(tregPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(buzzerPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
motion = digitalRead(pirPin);
if(motion == HIGH){
  Serial.println("An intruder detected! ");
  digitalWrite(tregPin,LOW);
  delayMicroseconds(2);
  digitalWrite(tregPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(tregPin,LOW);
  timeInverval = pulseIn(echoPin,HIGH);
  distance = (timeInverval) * (0.000001)*(330);
    if(distance < 0.50){
    analogWrite(buzzerPin,255);
    

  }
    else{
        analogWrite(buzzerPin,0);

}
if (motion == LOW){
  Serial.println("No one detected ");

}
delay(200);


}
Serial.println("The distance from the Ultra sound sensor is "+String(distance)+ " m");


}