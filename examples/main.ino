#include "iot.h"

IoTModule IoT;

void setup() {
    Serial.begin(115200);
    IoT.beginWiFi("SSID", "PASSWORD");

    // Set platform to Telegram
    IoT.set_platform("Telegram");
    IoT.setTelegramToken("YOUR_TELEGRAM_BOT_TOKEN");
    IoT.setTelegramChatID("YOUR_CHAT_ID");
    IoT.sendTelegramMessage("Hello from IoTModule!");

    // Set platform to Firebase
    IoT.set_platform("Firebase");
    IoT.setFirebaseConfig("FIREBASE_HOST", "FIREBASE_AUTH");
    IoT.sendFirebaseData("/test", "Hello Firebase!");

    // Set platform to WebServer
    IoT.set_platform("WebServer");
    IoT.startWebServer();
}

void loop() {
    // Add periodic tasks here
}
