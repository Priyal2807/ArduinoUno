int led1=8;
int led2=9;
int led3=10;
int led4=11;
int obsPin1=2;
int obsPin2=3;
int obsPin3=4;
int obsPin4=5;
int obs1=LOW;
int obs2=LOW;
int obs3=LOW;
int obs4=LOW;
void setup() {
 pinMode(obsPin1,INPUT);
 pinMode(obsPin2,INPUT);
 pinMode(obsPin3,INPUT);
 pinMode(obsPin4,INPUT);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT);
 Serial.begin(9600);

}

void loop() {
obs1=digitalRead(obsPin1);
obs2=digitalRead(obsPin2);
obs3=digitalRead(obsPin3);
obs4=digitalRead(obsPin4);
if(obs1==HIGH)
{
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);
}
else if(obs2==HIGH)
{
digitalWrite(led2,HIGH);
digitalWrite(led1,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);
}
else if(obs3==HIGH)
{
digitalWrite(led3,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led1,LOW);
digitalWrite(led4,LOW);
}

else if(obs4==HIGH){
digitalWrite(led4,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led1,LOW);
}
delay(3000);
}

