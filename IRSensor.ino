int led=13;
int obsPin=7;
int obs=LOW;

void setup() {
 pinMode(led,OUTPUT);
 pinMode(obsPin,OUTPUT);
 Serial.begin(9600); 
}

void loop() {
 obs=digitalRead(obsPin);
 if(obs==HIGH){
  Serial.println("Object detected");
  digitalWrite(led,HIGH);
 }

 else{
  Serial.println("No Object");
  digitalWrite(led,LOW);
 }

}
