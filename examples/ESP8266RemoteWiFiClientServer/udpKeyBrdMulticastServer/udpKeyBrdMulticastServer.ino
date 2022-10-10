/*
*  File: udpKeyBrdMulticastServer.ino
*
*  Use WiFi to remotely control many ESP8266 microcontrollers with the attached USB
*  keyboard and the 'ESP8266 USB Host Shield' with UDP broadcast to all listening clients.
*
*  Created by Debinix Team (c). The MIT License (MIT).
*  Date: 2022-10-10.
*/

// Comment this out to remove my debug serial port messages
#define MYDEBUG

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>
#include <SPI.h>

WiFiUDP udp;

#include <hidboot.h>
#include <usbhub.h>
#include "usbkbdparser.h"
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

USB     Usb;

//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
KbdRptParser Prs;

// IPAddress broadcast, i.e., the last address of subnetwork range
IPAddress broadcast=IPAddress(192, 168, 0, 255);

// Set your WiFi credentials
const char* ssid = "FW114";
const char* password = "";

const int port = 8266;    // Port can be any non-used network port number
uint8_t ascii_key;
bool flag_key_is_pressed = false;
unsigned long previousMillis = 0;
const long poll_kbd_status = 250;  // every 250 ms

// Moved and modified the original method slightly (usbkbdparser.h)
void KbdRptParser::OnKeyPressed(uint8_t key)    // called by Usb.Task()
{
#ifdef MYDEBUG
Serial.print("-- You pressed key: ");
Serial.println((char)key);
#endif
ascii_key = key;              // assign key-pressed (key)
flag_key_is_pressed = true;   // add flag event
};

void sendByteUDP(uint8_t pkt) {
    udp.beginPacketMulticast(broadcast, port, WiFi.localIP());
    udp.write(pkt);
    udp.endPacket();
}

void setup(void) {

    Serial.begin( 115200 );
    //#if !defined(__MIPSEL__)
    while (!Serial);
    //#endif
    Serial.println("Start");
    if (Usb.Init() == -1)
    Serial.println("OSC did not start.");

    delay( 200 );
    HidKeyboard.SetReportParser(0, &Prs);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.print("Broadcast address : ");
    Serial.print(broadcast);
    Serial.print(":");
    Serial.println(port);

}

void loop(void) {

    Usb.Task();

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= poll_kbd_status) {
        previousMillis = currentMillis;

        if(flag_key_is_pressed == true) {

            #ifdef MYDEBUG
            Serial.print("-- Send key Ascii#: ");
            Serial.println(ascii_key);
            #endif
            switch(ascii_key){

            case 98:                  // Keybrd "b" (blue LED)
            sendByteUDP(ascii_key);
            break;

            case 114:                  // Keybrd "r" (red LED)
            sendByteUDP(ascii_key);
            break;


            case 103:                  // Keybrd "g" (green LED)
            sendByteUDP(ascii_key);
            break;

            case 121:                  // Keybrd "y" (yellow LED)
            sendByteUDP(ascii_key);
            break;

            default:
            Serial.println("-- Oooops .. undefined key pressed!");
            } // switch

            flag_key_is_pressed = false;
        }
    }
}
// EOF
