const int trigPin=8;
const int echoPin=7;
int buzzer=11;
long duration;//DURATION
int distance;

void setup()
{
  pinMode(echoPin,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  
  Serial.print(distance);
  Serial.println(" ");
 
  
  
  
  
  
  if(distance<=80 && distance>=30)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
  }
  if(distance<=30)
  {
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    tone(buzzer,2000);
    delay(1000);
    noTone(buzzer);
    delay(250);
    tone(buzzer,2000);
    delay(500);
    noTone(buzzer);
   delay(250);
    tone(buzzer,2000);
    delay(500);
    noTone(buzzer);
    delay(250);
  }
  else
  {
    digitalWrite(12,LOW);
  }
}
