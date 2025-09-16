#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const char* ssid = "Wokwi-GUEST";
const char* password = "";
String serverName = "https://httpbin.org/post"; // Futuro endpoint do node-red

float t = 0;
int heartRate;
int calorias;
#define SCREEN_WIDTH 16
#define SCREEN_HEIGHT 2

LiquidCrystal_I2C lcd(0x27, SCREEN_WIDTH, SCREEN_HEIGHT);


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado ao WiFi!");
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  // Simula BPM
  heartRate = 80 + 15 * sin(t);
  t += 0.2;

  // Calorias simples
  calorias = 5 + (heartRate - 80) / 5;

  // Enviar para Node-RED
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    String json = "{\"heartRate\":" + String(heartRate) + ",\"calorias\":" + String(calorias) + "}";
    int code = http.POST(json);

    Serial.println("Enviado, resposta: " + String(code));
    http.end();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("HR:" + String(heartRate) + " BPM");
      lcd.setCursor(0, 1);
      lcd.print("Cal:" + String(calorias) + " kcal");

  delay(2000);
  }

  delay(2000);
}
