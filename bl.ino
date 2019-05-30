/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

//You should put values of pins here, for more info you can google it to find pin you are attaching switches and servo
const int limitswitchup = 15;
const int limitswitchdown = 13;
int x=0;
int y=0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "12e40b72bc5b48d3b5696b19dadf3b06";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "....";//Enter wifi name
char pass[] = "...";// wifi password
// dah ta3reef el servo
Servo servo;
//Creating virtual pin in the blynk app
BLYNK_WRITE(V3) {
  x=digitalRead(limitswitchup);
  if (x!=LOW){
  servo.write(param.asInt());
  }
  else {servo.write(96);}
}

BLYNK_WRITE(V4) {
  y=digitalRead(limitswitchdown);
  if(y!=LOW){
  servo.write(param.asInt());
  }
  else {servo.write(96);
  }
}
//Intitalising setup of switches according to pins
void setup() {
pinMode(limitswitchup,INPUT);
pinMode(limitswitchdown,INPUT);

 Serial.begin(115200);

Blynk.begin(auth, ssid, pass);

// You can also specify server:

Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);

//Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

servo.attach(2); //2 means d4 pin of ESP8266

}

void loop()

{
Blynk.run(); // You can inject your own code or combine it with other sketches.
x= digitalRead(limitswitchup);
y=digitalRead(limitswitchdown);
while (x==LOW) //if limit switch is being touched "Down"
 { servo.write(96);
  break;
    }
 while (y==LOW) // if limit switch being touched "UP"
 {servo.write(96);
 break;
 }
}
