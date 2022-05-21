#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
                          
#define FIREBASE_HOST "***your firebase host name***"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "**your firebase auth key***" //Your Firebase Database Secret goes here

#define WIFI_SSID "BELL4G-D552"
#define WIFI_PASSWORD "E9GG46ENN2R"
#define D7 13
int val=0, val3=1000;

void setup() {
  pinMode(D7,OUTPUT);

  Serial.begin(115200);

  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase
delay(1000);
}


int a ;
void loop() { 

digitalWrite(2,1);



  

// Firebase Error Handling ************************************************



a=Firebase.getInt("iot/1/ledstatus"); // location of table
if (Firebase.failed())
  { 
    
  Serial.println(Firebase.error());
  
  }
  else{
   Serial.println(a);  
  }

    if(a==1){
      digitalWrite(D7,HIGH);
    }
    
    if(a==0)
    {
      digitalWrite(D7,LOW); 
    }
  
  delay(500);
  



    /*


    Firebase.setInt("/iot",val);
   Serial.println(val);
    delay(300); Serial.println("uploaded val to firebase \n \n \n");

    /*  Firebase.setInt("/test/val3",val3);
   Serial.println(val3);
    delay(300); Serial.println("uploaded val3 to firebase \n \n \n");
  

  val++; val3++;*/
 }



  
