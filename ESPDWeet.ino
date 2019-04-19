//
// Esempio di utilizzo di deweet come storage di dati con ESP8266
//
// maurizio.conti@fablabromagna.org
// 19 Aprile 2019
//
// dipendenze:
//
// libreria dweetESP8266
// https://github.com/gamo256/dweet-esp/archive/master.zip
//
// Libreria ArduinoJson (attento: solo versione 5.x, non usare la 6.x)
// https://arduinojson.org/
// Installare con il library manager di Arduino
//

#include "dweetESP8266.h"

#define WIFISSID "NuovoBuscone"
#define PASSWORD "Prova1234"

// Il client che usiamo per postare su dweet...
dweet client;

#define THIG_NAME  "lab01"  // ogni "cosa" in dweet ha un nome

// valori da postare nella "cosa"
int value1, value2, value3;


void setup(){
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
}

void loop(){
  
    // preparo i valori da postare...
    client.add( "v1", String(value1) );
    client.add( "v2", String(value2) );
    client.add( "v3", String(value3) );
    
    // li posto tutti insieme
    client.sendAll(THIG_NAME);

    // aspetto almeno 1 secondo tra un post e l'altro altrimenti dweet mi banna
    delay(1000);

    // aggiorno i valori ad ogni giro...
    value1++;
    value2++;
    value3++;

    // Per visualizzare i dati postati sulla "cosa" lab01
    // lanciare il browser qui:
    // http://dweet.io/follow/lab01

    // per rileggere i dati da dweet
    String value = client.getDweet(THIG_NAME, "v1");
    Serial.println(value);

    // aspetto almeno 1 secondo tra un post e l'altro altrimenti dweet mi banna
    delay(1000);
}
