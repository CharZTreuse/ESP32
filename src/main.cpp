
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
#define UID "SMCD9c0k4hNr8xO1zfILn0KGOU42" //principal
#define UID1 "cwotYCmyvPg5nk6mvzqH8rpU9ql1"
#define UID2 "KsU2g1AhS5hiQ3OdQwaP1nuaSVF2"
#define UID3 "57yje8Vtf0eKFqCkK6YLWTQokcz1"
#define UID4 "TBBIaDcA2BaacXIVa31TmOVJRtt1"
#define UID5 "1AmBqXdWM0TqpJwSZV7dzvYfDZ12"
#define UID6 "m9H7yNFIPTZdzmFDxrlt3jnwrYB2"
#define UID7 "w46iNdCjWpRkqAYSks916cuMGuq1"
#define UID8 "aZZs3A9IF0cWlbwvFQXapHesED13"
#define UID9 "i0F0dkdn6PU2ew9l3Asr3EJ9GC42"
#define UID10 "bOlHPx8IMiScIU77h1RNiu39eox2"
#define UID11 "DXuk0TF0C5PYMUFLk27svEooMN53"
#define UID12 "eMDgGAeDE8dPMN5KN3Uhy9ioxVV2"
#define UID13 "1rHalWTBn8NXz8DorW70wAGylt13"
#define UID14 "bIvgNftJfIPCT1jHpbNbW4Z3eij1"
#define UID15 "nu7mRxTeSJRm28AYfgyrERwmKds2"
#define UID16 "YEHFpd3Da2eHGDFj9TCa7JwmRip2"
#define UID17 "HfY6QhEA6vZzlcn9UgPKYZRaQgk2"
#define UID18 "jnpAW6bmChZZiYeMvDbFau8Oer82"
#define UID19 "jvRFY92O21eJ0jlNEpmGTJq7kkU2"
#define UID20 "LOXgirQu7tgTYcHvI0CCg9qW9k52"
#define UID21 "F3a4wK4egdVCHo0WxyGznk9Nevg2"
#define UID22 "tQBBJxPkx4Z9o15gYe7mzcVg2wv1"
#define UID23 "a6fkD91ZzBVF3HSID4WVjAMP1IJ2"
#define UID24 "8dnCeugbx5NbK1w5GC3Ljv7A3qq1"
#define UID25 "jooWIN31PPdfl1MSkBrD9lxsPJ22"
#define UID26 "iaQThp792beVJKL1Z3netAVB2VX2"
#define UID27 "0VxNiT8HDLQNxMgZ5JwCuz3PapI2"
#define UID28 "zi9y8vaY2WeRrJDwsGX9Demr2VF2"
#define UID29 "uim3IWisvxbkUtaOT8qJvxpoZeB3"
#define UID30 "zMxFbs7EbVOpfE6OlNbp9FlXwvF3"
#define UID31 "Kf4AkZBivWT3DxgjQukkn2zfe4h2"
#define UID32 "MDoaUNO1b3PsjnnlHijjRzaeJ3E2"
#define UID33 "BsgZ8OiVfYQDj56CSkNX6G3q6ix2"
#define UID34 "nupmMNkPdNPJ0E4FSJOCstDptCy2"
#define UID35 "QLKDLzDs4EXvzEKXRD2QyEPBuCO2"
#define UID36 "6seN51GubFUeSkBUCC4m2RfO4Ms1"
#define UID37 "p6MrxXmFBJf5upRGjSy5YMv97Sa2"
#define UID38 "nFwFejSwQeTRnf7iAphNyQT91nx1"
#define UID39 "j2PHcBQjOvN73zZI95YDxPYgwVE2"
#define UID40 "VpaMc4Y4eJTZ6oN4N7JIsaCgvN33"
#define UID41 "OHF3oW1UTFdSmQh78fyRbbC0FHw2"
#define UID42 "kaIfrXXLatfnPIUGoUVmyWWHbG22"
#define UID43 "1gE6b5PCWKSsBrYPtDMROuRNGQ53"
#define UID44 "5bL0QO71izcVii3mZqhdg9wx2243"
#define UID45 "U9nneO1hgPUTAlRJGC0HV6BTRi42"
#define UID46 "q8SVSZoIwOhA6sxVnsoheZRd7nj1"
#define UID47 "nb0jVJFAjuNtEIRw3CKtk4nQ4d32"
#define UID48 "8r0l2fPOhRY3iVTWITCktskysFN2"
#define UID49 "OrgMR6CBe1PAL7TCUuzHVdkpP1n2"
#define UID50 "0dozUo4AJiep10Aakm2x1jP4ryB3"

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

        //FirebaseJson jVal;
        //Serial.printf("Get json ref... %s\n", Firebase.RTDB.getJSON(&fbdo,  "/root/" UID "/appareil1", &jVal) ? jVal.raw() : fbdo.errorReason().c_str());

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
//-------------------------------------------------------------------------------------
        /*Firebase.RTDB.setJSON(&fbdo,  "/root/" UID1 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID2 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID3 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID4 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID5 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID6 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID7 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID8 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID9 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID10 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID11 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID12 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID13 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID14 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID15 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID16 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID17 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID18 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID19 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID20 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID21 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID22 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID23 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID24 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID25 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID26 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID27 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID28 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID29 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID30 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID31 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID32 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID33 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID34 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID35 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID36 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID37 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID38 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID39 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID40 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID41 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID42 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID43 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID44 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID45 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID46 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID47 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID48 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID49 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();
        Firebase.RTDB.setJSON(&fbdo,  "/root/" UID50 "/appareil1/RX", &rx) ? "ok" : fbdo.errorReason().c_str();*/
//-------------------------------------------------------------------------------------        
//pH
        FirebaseJson pH;
        pH.setDoubleDigits(3);
        pH.set("pH", 7.7);
        pH.set("calibrationPH", 7.3);
        pH.set("consignePH", 7.5);
        pH.set("seuilAlerteBasPH", 5.9);
        pH.set("seuilAlerteHautPH", 7.9);
        Serial.printf("Envoie données pH... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1/pH", &pH) ? "ok" : fbdo.errorReason().c_str());

//production
        FirebaseJson production;
        production.setDoubleDigits(3);
        production.set("production", 75);
        Serial.printf("Envoie données Production... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1/production", &production) ? "ok" : fbdo.errorReason().c_str());

//salt
        FirebaseJson salt;
        salt.setDoubleDigits(3);
        salt.set("salt", 2.2);
        salt.set("calibrationSalt", 5.9);
        salt.set("seuilAlerteSalt", 3);
        Serial.printf("Envoie données Salt... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1/salt", &salt) ? "ok" : fbdo.errorReason().c_str());

//temperature
        FirebaseJson temperature;
        temperature.setDoubleDigits(3);
        temperature.set("temperature", 17.8);
        temperature.set("calibrationTemperature", 34.9);
        temperature.set("seuilAlerteTemperature", 14.5);
        Serial.printf("Envoie données Temperature... %s\n", Firebase.RTDB.setJSON(&fbdo,  "/root/" UID "/appareil1/temperature", &temperature) ? "ok" : fbdo.errorReason().c_str());
    }
}