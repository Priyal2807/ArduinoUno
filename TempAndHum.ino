#include <dht.h>
#define dht_apin A0
dht DHT;
int temp=0;
int hum=0;
const int ldr=A1;
int sensorValue=0;
int led1=10;//led for humidity
int led2=11;// led for temperature
int ledState2=LOW;
int ledState1=LOW;
char buffer[5];
int pId=0;



void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("Evaluating a greenhouse tmp");
  delay(1000);
  Serial.println("#S|SPXL|[]#"); // Start Excel
}



void loop() {
  sensorValue=analogRead(ldr);  //this is used for the detection light and dark for different vegetables
  DHT.read11(dht_apin);
  temp=DHT.temperature;
  hum=DHT.humidity;
 /*for tomato daytime:80-90  nighttime:65-75 Tomatoes grow best when the daytime temperature is between 19 and 30 degrees Celsius. They stop growing above 35 degrees Celcius.
 If nighttime temperatures are above 30  degrees Fahrenheit, the fruit will not turn red. Tomatoes need full sun and warm, well-drained soil.*/
 if(sensorValue<=100) //confirm value of light intensity  for the night
 {   
  if(hum<=65 || hum>=75)
  {    
    digitalWrite(led1,HIGH);
  } 
   if(temp>32){
    digitalWrite(led2,HIGH);
  }
 /* Serial.println(temp);
  Serial.println(hum);*/
  Serial.print("#S|SENDK|[");
   Serial.print(itoa((pId), buffer, 10));
   Serial.print("&");
   Serial.print(itoa((temp), buffer, 10));
   Serial.print(" {TAB} ");
   Serial.print(itoa((hum), buffer, 10));   //*http://www.valpont.com/saving-data-from-an-arduino-on-a-pc-using-gobetwino/pst/  
   Serial.print(" {DOWN} ");
   Serial.print(" {LEFT} ");
   Serial.println("]#");
  // readSerialString(serInString, 1000); // read response from PC
   // Deal with response from PC here. Ignored for now.
   delay(2000); // block code for 2 seconds - ensure excel has fully executed commands on PC
 
   // Save file after each write
   Serial.print("#S|SENDK|[");
   Serial.print(itoa((pId), buffer, 10));
   Serial.print("& ");
   Serial.print("%Fs");  //=   ALT f   ALT g  = save and exit in danish Excell
   Serial.println("]#");
   // Wait 2 seconds for the save to finish
   delay(2000);

 }


 

 else
 {
   if(hum<=70 || hum>=80)
  {
    digitalWrite(led1,HIGH);
    
  }

 if(temp>33){
   digitalWrite(led1,HIGH);
  }

  Serial.print("#S|SENDK|[");
   Serial.print(itoa((pId), buffer, 10));
   Serial.print("&");
   Serial.print(itoa((temp), buffer, 10));
   Serial.print(" {TAB} ");
   Serial.print(itoa((hum), buffer, 10));   //*http://www.valpont.com/saving-data-from-an-arduino-on-a-pc-using-gobetwino/pst/  
   Serial.print(" {DOWN} ");
   Serial.print(" {LEFT} ");
   Serial.println("]#");
  // readSerialString(serInString, 1000); // read response from PC
   // Deal with response from PC here. Ignored for now.
   delay(2000); // block code for 2 seconds - ensure excel has fully executed commands on PC
 
   // Save file after each write
   Serial.print("#S|SENDK|[");
   Serial.print(itoa((pId), buffer, 10));
   Serial.print("& ");
   Serial.print("%Fs");  //=   ALT f   ALT g  = save and exit in danish Excell
   Serial.println("]#");
   // Wait 2 seconds for the save to finish
   delay(2000);
 
   

 }
 /*for cabbage temp 40 degree cel optimum can go up to 80 deg cel */
 /* for citrus fruits dies below 0 degree celsius best range between 20-30 degree celsuis humidity 60-65 */
 /* for spinach cold time crop grows best when the temp is around 21-24 degree Celsius */

 
delay(3000);
}
