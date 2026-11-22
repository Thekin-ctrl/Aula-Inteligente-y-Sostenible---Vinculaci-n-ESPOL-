#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Configuración de la pantalla OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_SDA 20     
#define OLED_SCL 21     
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Configuración de pines y sensores
#define DHTPIN 4
#define DHTTYPE DHT22   
#define LDR_PIN 5      

DHT dht(DHTPIN, DHTTYPE);

// Variables globales de lectura
float temperatura = 0.0;
float humedad = 0.0;
int luzPorcentaje = 0;

// Control de tiempos no bloqueante con millis()
unsigned long ultimaLectura = 0;
unsigned long ultimoCambioPantalla = 0;
const unsigned long INTERVALO_LECTURA = 2000;   // Leer sensores cada 2 segundos
const unsigned long INTERVALO_PANTALLA = 3000;  // Alternar pantalla cada 3 segundos

int pantallaActual = 0; // 0: Clima, 1: Luz, 2: Resumen

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LDR_PIN, INPUT);

  // Configurar los nuevos pines I2C ANTES de iniciar la OLED
  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Error al iniciar la pantalla OLED SSD1306"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 20);
  display.println(F("Estacion Ambiental"));
  display.setCursor(18, 35);
  display.println(F("Multiparametro"));
  display.display();
  delay(2000);

  leerSensores();
  actualizarPantalla();
}

void loop() {
  unsigned long tiempoActual = millis();

  // 1. Leer los sensores cada 2 segundos sin pausar el programa
  if (tiempoActual - ultimaLectura >= INTERVALO_LECTURA) {
    ultimaLectura = tiempoActual;
    leerSensores();
  }

  // 2. Alternar la pantalla OLED cada 3 segundos
  if (tiempoActual - ultimoCambioPantalla >= INTERVALO_PANTALLA) {
    ultimoCambioPantalla = tiempoActual;
    pantallaActual = (pantallaActual + 1) % 3; // Cicla: 0 -> 1 -> 2 -> 0
    actualizarPantalla();
  }
}

// --- FUNCIONES MODULARES ---

void leerSensores() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (!isnan(h) && !isnan(t)) {
    humedad = h;
    temperatura = t;
  } else {
    Serial.println(F("Error al leer el sensor DHT"));
  }

  int lecturaADC = analogRead(LDR_PIN);
  luzPorcentaje = map(lecturaADC, 4095, 0, 0, 100);
  luzPorcentaje = constrain(luzPorcentaje, 0, 100);

  Serial.print(F("Temp: ")); Serial.print(temperatura);
  Serial.print(F(" C | Hum: ")); Serial.print(humedad);
  Serial.print(F(" % | Luz: ")); Serial.print(luzPorcentaje);
  Serial.println(F(" %"));
}

void actualizarPantalla() {
  display.clearDisplay();
  if (pantallaActual == 0) {
    mostrarPantallaClima();
  } else if (pantallaActual == 1) {
    mostrarPantallaLuz();
  } else {
    mostrarPantallaResumen();
  }
  display.display();
}

void mostrarPantallaClima() {
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("1/3 CLIMA DEL AULA"));
  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);

  display.setCursor(0, 18);
  display.print(F("Temp: "));
  display.print(temperatura, 1);
  display.println(F(" C"));

  display.setCursor(0, 32);
  display.print(F("Hum:  "));
  display.print(humedad, 1);
  display.println(F(" %"));

  display.setCursor(0, 50);
  if (temperatura > 28.0) {
    display.print(F("Estado: CALUROSO"));
  } else if (humedad > 70.0) {
    display.print(F("Estado: MUY HUMEDO"));
  } else {
    display.print(F("Estado: CONFORTABLE"));
  }
}

void mostrarPantallaLuz() {
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("2/3 ILUMINACION"));
  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);

  display.setCursor(0, 18);
  display.print(F("Luz natural: "));
  display.print(luzPorcentaje);
  display.println(F(" %"));

  display.drawRect(0, 32, 120, 12, SSD1306_WHITE);
  int anchoBarra = map(luzPorcentaje, 0, 100, 0, 116);
  display.fillRect(2, 34, anchoBarra, 8, SSD1306_WHITE);

  display.setCursor(0, 50);
  if (luzPorcentaje >= 50) {
    display.print(F("Apagar luces del aula"));
  } else {
    display.print(F("Encender luces"));
  }
}

void mostrarPantallaResumen() {
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("3/3 RESUMEN INTEGRAL"));
  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);

  display.setCursor(0, 18);
  display.print(F("T: ")); display.print(temperatura, 1); display.println(F(" C"));

  display.setCursor(0, 32);
  display.print(F("H: ")); display.print(humedad, 1); display.println(F(" %"));

  display.setCursor(0, 46);
  display.print(F("L: ")); display.print(luzPorcentaje); display.println(F(" %"));
}