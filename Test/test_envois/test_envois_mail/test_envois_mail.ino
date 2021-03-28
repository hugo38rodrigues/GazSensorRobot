/*
 * EMailSender library for Arduino, esp8266 and esp32
 * Simple esp32 Gmail send to a distribution list example
 *
 * https://www.mischianti.org/category/my-libraries/emailsender-send-email-with-attachments/
 *
 */

#include "Arduino.h"
#include <EMailSender.h>

uint8_t connection_state = 0;
uint16_t reconnect_interval = 10000;

EMailSender emailSend("hugo38.test1@gmail.com", "toToeap1!");

uint8_t WiFiConnect(const char* nSSID = nullptr, const char* nPassword = nullptr)
{
    static uint16_t attempt = 0;
    Serial.print("Connecting to ");
    if(nSSID) {
        WiFi.begin(nSSID, nPassword);
        Serial.println(nSSID);
    }

    uint8_t i = 0;
    while(WiFi.status()!= WL_CONNECTED && i++ < 50)
    {
        delay(200);
        Serial.print(".");
    }
    ++attempt;
    Serial.println("");
    if(i == 51) {
        Serial.print("Connection: TIMEOUT on attempt: ");
        Serial.println(attempt);
        if(attempt % 2 == 0)
            Serial.println("Check if access point available or SSID and Password\r\n");
        return false;
    }
    Serial.println("Connection: ESTABLISHED");
    Serial.print("Got IP address: ");
    Serial.println(WiFi.localIP());
    return true;
}

void Awaits()
{
    uint32_t ts = millis();
    while(!connection_state)
    {
        delay(50);
        if(millis() > (ts + reconnect_interval) && !connection_state){
            connection_state = WiFiConnect();
            ts = millis();
        }
    }
}
void SendMail(){
    EMailSender::EMailMessage message;
    message.subject = "Robot detection";
    message.message = "Detection CO";

    // Send email
    const char* arrayOfEmail[] = {"hugo38.test1@gmail.com"};
    EMailSender::Response resp = emailSend.send(arrayOfEmail, 1, message);

    Serial.println("Sending status: ");

    Serial.println(resp.status);
    Serial.println(resp.code);
    Serial.println(resp.desc);
}

void setup()
{
    Serial.begin(115200);
    const char* ssid = "Portablehugo";
    const char* password = "0987654321";

    connection_state = WiFiConnect(ssid, password);
    if(!connection_state)  // if not connected to WIFI
    Awaits();          // constantly trying to connect
    pinMode(2,INPUT_PULLUP);   

}

void loop()
{
    if(digitalRead(2) ==HIGH){
        Serial.println("debut de sendmail");
        SendMail();
    }
    delay(100);
}
