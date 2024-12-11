#ifndef IOTMODULE_H
#define IOTMODULE_H

#include <Arduino.h>

// Include platform-specific libraries
#include <WiFi.h>
#include <HTTPClient.h> // Untuk WebServer dan HTTP requests
#include <UniversalTelegramBot.h> // Untuk Telegram
#include <FirebaseESP32.h>        // Untuk Firebase

class IoTModule {
private:
    String platform;
    // Platform-specific variables
    String telegramToken;
    String telegramChatID;
    String firebaseHost;
    String firebaseAuth;
    
    // Telegram-specific variables
    WiFiClientSecure telegramClient;
    UniversalTelegramBot *bot;

public:
    IoTModule();
    void set_platform(String platform_name);
    
    // Telegram-specific functions
    void setTelegramToken(String token);
    void setTelegramChatID(String chatID);
    void sendTelegramMessage(String message);

    // Firebase-specific functions
    void setFirebaseConfig(String host, String auth);
    void sendFirebaseData(String path, String data);

    // WebServer functions
    void startWebServer();

    // Utility functions
    void beginWiFi(const char* ssid, const char* password);
};

#endif
