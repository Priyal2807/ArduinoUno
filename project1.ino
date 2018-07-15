int led=13;
int obsPin=11;
int trigPin=9;
int echoPin=10;
int obsState=LOW;
long distance;
int duration;

void setup() { 
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 Serail.begin(9600);
 pinMode(led,OUTPUT);
 pinMode(obsPin,OUTPUT); 
}

void loop() {

digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=(duration*0.034)/2;
if(distance<=200)
{
  obsState=digitalWrite(obsPin);
  digitalWrite(led,obsState);
  if(obsState==HIGH){
    Serial.println("Transaction can be done");             //We can send some information from this loop to the gobetwino software and then use that info in our machine learning algo
    Serial.println("Place your face near the Camera");

    /* Serial.print("#S|TIMELOG|[");
   Serial.println("]#");
   delay (1000);

Serial.println("#S|WEBCAM|[]#");        // start Webcam software
  delay (5000);  // wait  5  seconds (max) for answer from Gobetwino (=porcess ID)
  
  Serial.println("#S|SENDK|[0&{HOME}]#");
delay(5000);  // wait  5  seconds (max) for answer from Gobetwino (=porcess ID)
  */
  }
}
else{
  Serial.println("Please step closer");
}

delay(60000); //this delay has been set for the next user

}
