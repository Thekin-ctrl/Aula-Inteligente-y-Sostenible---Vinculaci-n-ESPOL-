#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 4     
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Inicializar pantalla OLED con dirección 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falla en la asignacion de SSD1306"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("Monitor Confort"));
  display.display();
  delay(2000);
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Temperatura en Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Error al leer el sensor DHT!"));
    return;
  }

  // Determinar estado de confort térmico básico para el aula
  String estado = "Confortable";
  if (t > 28.0) {
    estado = "Caluroso";
  } else if (h > 70.0) {
    estado = "Muy Humedo";
  }

  // Mostrar en la pantalla OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print(F("Temp: "));
  display.print(t);
  display.print(F(" C"));

  display.setCursor(0, 16);
  display.print(F("Humedad: "));
  display.print(h);
  display.print(F(" %"));

  display.setCursor(0, 35);
  display.setTextSize(1);
  display.print(F("Estado Aula:"));
  
  display.setCursor(0, 48);
  display.setTextSize(1.5);
  display.print(estado);

  display.display();

  // Depuración por Monitor Serie
  Serial.print(F("Temperatura: ")); Serial.print(t);
  Serial.print(F("°C  Humedad: ")); Serial.print(h);
  Serial.print(F("%  Estado: ")); Serial.println(estado);
}