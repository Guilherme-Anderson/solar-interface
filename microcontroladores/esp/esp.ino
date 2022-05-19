#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>


#define FIREBASE_HOST "https://painelsolarteste-default-rtdb.firebaseio.com/"      
#define FIREBASE_AUTH "AIzaSyBC-2HySs9WASCSoKHa9NLOVqsr0-oU5qI"            
#define WIFI_SSID "Quarto"                                  
#define WIFI_PASSWORD "guigu123"                 

const int potenciometro = A0;


void setup() {
  Serial.begin(115200);       
  Serial.println('\n');
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }        
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());                               
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
}

void loop() {

  int leitura=analogRead(potenciometro);
  Firebase.pushString("/leitura/potenciometro", leitura);         

    if (Firebase.failed()) 
    {
 
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
  }
  delay(200);
}