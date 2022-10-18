/*
*  File: udpKeyBrdMulticastClient.ino
*
*  WiFi controlled ESP8266 client(s). Waiting for UDP broadcasted packages on port 8266
*  and upon reception, take action, here toggle GPIO ports and their attached LEDs.
*
*  Created by Debinix Team (c). The MIT License (MIT).
*  Date: 2022-10-10.
*/

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <string.h>

// Set your WiFi credentials (SSID, PASSWORD)
#define WIFI_SSID "FW114"
#define WIFI_PASS ""
#define UDP_PORT 8266   // Port can be any non-used network port number

// UDP
WiFiUDP UDP;

bool is_redlight = false;
bool is_bluelight = false;
bool is_greenlight = false;
bool is_yellowlight = false;
int packet;
char receive_msg[]="Packet received!";  // Use 'Packet Sender' to view the message. (https://packetsender.com).

const int redLED = 14;
const int blueLED = 15;
const int yellowLED = 12;
const int greenLED = 13;

void setup() {
    // Setup serial port
    Serial.begin(115200);
    Serial.println();

    pinMode(redLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(greenLED, OUTPUT);

    // Begin WiFi
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // Connecting to WiFi...
    Serial.print("Connecting to ");
    Serial.print(WIFI_SSID);
    // Loop continuously while WiFi is not connected
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print(".");
    }

    // Connected to WiFi
    Serial.println();
    Serial.print("Connected! IP address: ");
    Serial.println(WiFi.localIP());

    // Begin listening to UDP port
    UDP.begin(UDP_PORT);
    Serial.print("Listening on UDP port ");
    Serial.println(UDP_PORT);
    
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);  // Listening OK
}

void blinkAtPacketReceived(void) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
    digitalWrite(LED_BUILTIN, HIGH);    
}

void loop() {

    int packetSize = UDP.parsePacket();
    if (packetSize) {

        packet = UDP.read();
        Serial.print("-- Packet received: '");
        Serial.print(packet);
        Serial.println("'");
        blinkAtPacketReceived();

        // Command table for various GPIO ports
        switch(packet){

            case 98:    // Keybrd "b"
            Serial.println("-- Toggle Blue LED");
            if(!is_bluelight){
                digitalWrite(blueLED, HIGH);    // GPIO15
            } else {
                digitalWrite(blueLED, LOW);
            }
            is_bluelight  = !is_bluelight;
            break;

            case 114:    // Keybrd "r"
            Serial.println("-- Toggle Red LED");
            if(!is_redlight){
                digitalWrite(redLED, HIGH);     // GPIO14
            } else {
                digitalWrite(redLED, LOW);
            }
            is_redlight  = !is_redlight;
            break;

            case 103:    // Keybrd "g"
            Serial.println("-- Toggle Green LED");
            if(!is_greenlight){
                digitalWrite(greenLED, HIGH);   // GPIO13
            } else {
                digitalWrite(greenLED, LOW);
            }
            is_greenlight  = !is_greenlight;
            break;

            case 121:    // Keybrd "y"
            Serial.println("-- Toggle Yellow LED");
            if(!is_yellowlight){
                digitalWrite(yellowLED, HIGH);  // GPIO12
            } else {
                digitalWrite(yellowLED, LOW);
            }
            is_yellowlight  = !is_yellowlight;
            break;

            default:
            Serial.println("-- Oooops .. unrecognized Ascii command!");
        } // switch

        // Send received packet to log (i.e., Packet Sender)
        UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
        UDP.write(receive_msg);
        UDP.endPacket();
    }

    yield();

}
