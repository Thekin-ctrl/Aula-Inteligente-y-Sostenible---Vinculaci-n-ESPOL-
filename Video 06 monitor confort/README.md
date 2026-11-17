# 06 | Monitor de Confort Térmico del Aula con DHT11 (DHT22) y OLED

## Objetivo del Proyecto
Medir en tiempo real la temperatura y la humedad relativa en el aula escolar para evaluar las condiciones de confort térmico y su impacto en la concentración y bienestar de los estudiantes, utilizando un microcontrolador ESP32.

---

## 🛠️ Componentes Utilizados
* 1x Tarjeta de desarrollo ESP32 DevKit
* 1x Sensor de temperatura y humedad DHT11 *(Nota en Wokwi: se simula con **DHT22**, pero el código es idéntico)*
* 1x Pantalla OLED 0.96" I2C (Controlador SSD1306)
* Cables de conexión (jumpers)

---

## 🔌 Esquema de Conexiones

| Componente | Pin del Componente | Pin del ESP32 |
| :--- | :--- | :--- |
| **DHT22 / DHT11** | VCC | 3V3 |
| | GND | GND |
| | DATA | GPIO 4 |
| **OLED 0.96"** | GND | GND |
| | VCC | 3V3 |
| | SCL | GPIO 22 |
| | SDA | GPIO 21 |

---

## Contenido de la Carpeta
* `sketch.ino` — Código fuente de Arduino para el ESP32.
* `diagram.json` — Archivo de configuración del circuito en Wokwi.
* `circuito.png` — Captura de pantalla de la simulación.
* `ficha-reto.pdf` — Ficha de reto de una página para los docentes.

---

## 🚀 Cómo Probar en Wokwi
1. Abre [Wokwi.com](https://wokwi.com/) y crea un proyecto nuevo basado en **ESP32**.
2. Importa los componentes indicados y conéctalos según la tabla de pines.
3. Asegúrate de incluir las siguientes librerías en tu entorno de Wokwi (`libraries.txt`):
   * `DHT sensor library`
   * `Adafruit Unified Sensor`
   * `Adafruit SSD1306`
   * `Adafruit GFX Library`
4. Pega el código de `sketch.ino`, inicia la simulación y haz clic sobre el sensor DHT22 para simular variaciones de temperatura y humedad en tiempo real.

---

## 📝 Retos para el Aula
* **Básico:** Modificar los umbrales en el código para cambiar el estado a "Caluroso" a partir de los 25°C en lugar de 28°C.
* **Intermedio:** Agregar un LED indicador físico (rojo si el aula es caluroso, verde si está confortable) conectado a un pin digital libre.
* **Avanzado:** Integrar un zumbador (buzzer) activo que emita una alerta sonora intermitente cuando la humedad supere el 70%.
