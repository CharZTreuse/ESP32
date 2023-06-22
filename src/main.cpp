
/**
 * Created by K. Suwatchai (Mobizt)
 *
 * Email: k_suwatchai@hotmail.com
 *
 * Github: https://github.com/mobizt/FirebaseJson
 *
 * Copyright (c) 2023 mobizt
 *
 */

#include <Arduino.h>
#if defined(ESP32) || defined(ARDUINO_RASPBERRY_PI_PICO_W)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <Firebase_ESP_Client.h>

// Provide the token generation process info.
#include <addons/TokenHelper.h>

// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "CORELEC_RD"
#define WIFI_PASSWORD "corelecR&D"
//#define WIFI_SSID "Samsung Galaxy S21 FE"
//#define WIFI_PASSWORD "Pianoball"

//UID
#define UID "SMCD9c0k4hNr8xO1zfILn0KGOU42"

// For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

/* 2. Define the API Key */
#define API_KEY "AIzaSyDytLSTi18linMp9tnzA3svxsfZhqwgLxk"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://esp32-firebase-demo-4b148-default-rtdb.europe-west1.firebasedatabase.app/" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "theo.bruneau15@gmail.com"
#define USER_PASSWORD "Azerty123!"

// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

unsigned long count = 0;

void setup()
{
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(1000);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

    /* Assign the api key (required) */
    config.api_key = API_KEY;

    /* Assign the user sign in credentials */
    auth.user.email = USER_EMAIL;
    auth.user.password = USER_PASSWORD;

    /* Assign the RTDB URL (required) */
    config.database_url = DATABASE_URL;

    /* Assign the callback function for the long running token generation task */
    config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

    // Or use legacy authenticate method
    // config.database_url = DATABASE_URL;
    // config.signer.tokens.legacy_token = "<database secret>";

    Firebase.begin(&config, &auth);

    // Comment or pass false value when WiFi reconnection will control by your code or third party library
    Firebase.reconnectWiFi(true);
}

void loop()
{
    // Flash string (PROGMEM and  (FPSTR), String C/C++ string, const char, char array, string literal are supported
    // in all Firebase and FirebaseJson functions, unless F() macro is not supported.

    // Firebase.ready() should be called repeatedly to handle authentication tasks.

    if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
    {
        sendDataPrevMillis = millis();
        FirebaseJson json;
        json.setDoubleDigits(3);
        json.add("value", count);

        Serial.printf("Set json... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1", &json) ? "ok" : fbdo.errorReason().c_str());

        Serial.printf("Get json... %s\n", Firebase.RTDB.getJSON(&fbdo,  "/root/" UID "/appareil1") ? fbdo.to<FirebaseJson>().raw() : fbdo.errorReason().c_str());

        FirebaseJson jVal;
        Serial.printf("Get json ref... %s\n", Firebase.RTDB.getJSON(&fbdo,  "/root/" UID "/appareil1", &jVal) ? jVal.raw() : fbdo.errorReason().c_str());

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                          Envoie Donnees

//RX
        FirebaseJson rx;
        rx.setDoubleDigits(3);
        rx.set("RX", 498);
        rx.set("calibrationRX", 500);
        rx.set("consigneRX", 705);
        rx.set("seuilAlerteRX", 370);
        Serial.printf("Envoie données RX... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str());
//pH
        FirebaseJson ph;
        ph.setDoubleDigits(3);
        ph.set("pH", 7.7);
        ph.set("calibrationPH", 7.3);
        ph.set("consignePH", 7.5);
        ph.set("seuilAlerteBasPH", 5.9);
        ph.set("seuilAlerteHautPH", 7.9);
        Serial.printf("Envoie données pH... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1/pH", &ph) ? "ok" : fbdo.errorReason().c_str());

//Production
        FirebaseJson production;
        production.setDoubleDigits(3);
        production.set("production", 75);
        Serial.printf("Envoie données Production... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1/production", &production) ? "ok" : fbdo.errorReason().c_str());
//Salt
        FirebaseJson salt;
        salt.setDoubleDigits(3);
        salt.set("salt", 2.2);
        salt.set("calibrationSalt", 5.9);
        salt.set("seuilAlerteSalt", 3);
        Serial.printf("Envoie données Salt... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1/salt", &salt) ? "ok" : fbdo.errorReason().c_str());
//Temperature
        FirebaseJson temp;
        temp.setDoubleDigits(3);
        temp.set("temperature", 17.8);
        temp.set("calibrationTemperature", 34.9);
        temp.set("seuilAlerteTemperature", 14.5);
        Serial.printf("Envoie données Temperature... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1/temperature", &temp) ? "ok" : fbdo.errorReason().c_str());

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Autre
        //Array
        FirebaseJsonArray arr;
        arr.setFloatDigits(2);
        arr.setDoubleDigits(4);
        arr.add("a", "b", "c", true, 45, (float)6.1432, 123.45692789);

        Serial.printf("Set esp32 array...   %s\n", Firebase.RTDB.setArray(&fbdo, "/test/array", &arr) ? "ok" : fbdo.errorReason().c_str());

        Serial.printf("Get array... %s\n", Firebase.RTDB.getArray(&fbdo, "/test/array") ? fbdo.to<FirebaseJsonArray>().raw() : fbdo.errorReason().c_str());

        //Push
        //Serial.printf("Push json... %s\n", Firebase.RTDB.pushJSON(&fbdo, "/test/push", &json) ? "ok" : fbdo.errorReason().c_str());

        //json.set("value", count + 0.29745);
        //Serial.printf("Update json... %s\n\n", Firebase.RTDB.updateNode(&fbdo, "/test/push/" + fbdo.pushName(), &json) ? "ok" : fbdo.errorReason().c_str());
        count++; //augmente de 1 json
    }
}