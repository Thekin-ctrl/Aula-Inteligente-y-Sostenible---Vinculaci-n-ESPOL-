// --- CONFIGURACIÓN DE PINES ---
#define SENSOR_SUELO_PIN 34   // Pin analógico (potenciómetro en Wokwi / AO del sensor físico)
#define RELE_PIN 26           // Pin digital que controla el módulo relé de 5 V

// --- UMBRALES DE HUMEDAD ---
// Enciende la bomba cuando la tierra baja de 35% y la apaga al llegar a 65%
const int UMBRAL_SECO   = 35;
const int UMBRAL_HUMEDO = 65;

bool riegoActivo = false;

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_SUELO_PIN, INPUT);
  pinMode(RELE_PIN, OUTPUT);

  // Asegurar que la bomba arranque apagada
  digitalWrite(RELE_PIN, LOW);
  Serial.println("Sistema de Riego Automatico iniciado.");
}

void loop() {
  // 1. Leer valor analógico (0 a 4095 en ESP32)
  int lecturaADC = analogRead(SENSOR_SUELO_PIN);

  // 2. Convertir a porcentaje de humedad (0% = seco, 100% = húmedo)
  // Nota: en sensores físicos capacitivos/resistivos suele ser invertido: map(lecturaADC, 4095, 0, 0, 100)
  int humedadSuelo = map(lecturaADC, 0, 4095, 0, 100);
  humedadSuelo = constrain(humedadSuelo, 0, 100);

  // 3. Control automático con histéresis
  if (!riegoActivo && humedadSuelo < UMBRAL_SECO) {
    riegoActivo = true;
    digitalWrite(RELE_PIN, HIGH); // Activa el relé en Wokwi (enciende bomba/LED)
    Serial.println(">>> Tierra seca: INICIANDO RIEGO");
  } else if (riegoActivo && humedadSuelo >= UMBRAL_HUMEDO) {
    riegoActivo = false;
    digitalWrite(RELE_PIN, LOW);  // Desactiva el relé (apaga bomba/LED)
    Serial.println(">>> Tierra humeda: DETENIENDO RIEGO");
  }

  // 4. Mostrar estado en el Monitor Serie
  Serial.print("Humedad del suelo: ");
  Serial.print(humedadSuelo);
  Serial.print("%  |  Bomba: ");
  Serial.println(riegoActivo ? "ENCENDIDA" : "APAGADA");

  delay(1000);
}