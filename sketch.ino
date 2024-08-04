#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

//defining pin for MQ2
#define mq2 A0
float mq2_data = 0;

void setup() {
  // setting bboud rate for data communication
Serial.begin(9600);
// initializing softwareSerial 
mySerial.begin(9600);
delay(100);
// defining nature of pins
pinMode(A0,INPUT);
}


void loop() {
  
// reading sensor data

mq2_data = analogRead(A0);
Serial.println(mq2_data);

// Applying conditions here....
if (mq2_data>120){
  // sending sms to registered mobile no.
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+917456005172\"\r"); 
     delay(1000);
     mySerial.println("Driver is Drunk");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
}

}
