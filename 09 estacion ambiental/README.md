# 09 | Estación Ambiental Multiparámetro: temperatura, humedad y luz

Repositorio del proyecto correspondiente al **Módulo 1: Monitoreo ambiental (Nivel Avanzado)** del programa de Vinculación ESPOL: *Aula Inteligente y Sostenible*.

---

## Objetivo del Proyecto
Integrar en un solo dispositivo basado en ESP32 la medición de temperatura, humedad e iluminación natural del aula, mostrando los resultados en una pantalla OLED que alterna automáticamente cada 3 segundos mediante programación no bloqueante (`millis()`) y funciones modulares.

---

## Componentes Utilizados
* 1x Tarjeta de desarrollo ESP32 DevKit
* 1x Sensor DHT11 *(en Wokwi se simula con **DHT22**)*
* 1x Sensor de luz LDR *(módulo fotoresistor en Wokwi o LDR + resistencia de 10 kΩ en físico)*
* 1x Pantalla OLED 0.96" I2C (SSD1306)
* Protoboard y cables de conexión

---

## Esquema de Conexiones

| Componente | Pin del Componente | Pin del ESP32 |
| :--- | :--- | :--- |
| **DHT22 / DHT11** | VCC / GND / DATA | 3V3 / GND / **GPIO 4** |
| **Módulo LDR** | VCC / GND / AO | 3V3 / GND / **GPIO 5** |
| **OLED 0.96" I2C** | VCC / GND / SCL / SDA | 3V3 / GND / **GPIO 21** / **GPIO 20** |

---

## Contenido de la Carpeta
* `sketch.ino` — Código fuente con `millis()` y funciones modulares.
* `diagram.json` — Configuración del circuito en Wokwi.
* `circuito.png` — Captura de pantalla de la simulación.
* `ficha-reto.pdf` — Ficha de reto de una página para docentes.

---

## 🚀 Cómo Probar en Wokwi
1. Abre [Wokwi.com](https://wokwi.com/) y crea un proyecto de **ESP32**.
2. Conecta el DHT22, el módulo Photoresistor (LDR) y la pantalla OLED según la tabla.
3. Agrega las librerías en `libraries.txt`: `DHT sensor library`, `Adafruit Unified Sensor`, `Adafruit SSD1306` y `Adafruit GFX Library`.
4. Pega el código de `sketch.ino`, inicia la simulación y modifica los controles deslizantes del DHT22 y del LDR para ver cómo cambian las tres pantallas cada 3 segundos.
