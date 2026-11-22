# 18 | Sistema de Riego Automático para el huerto escolar

Repositorio del proyecto correspondiente al **Módulo 4: Agua e integración (Nivel Intermedio)** del programa de Vinculación ESPOL: *Aula Inteligente y Sostenible*.

---

## Objetivo del Proyecto
Construir un sistema de riego automático con ESP32 que mida la humedad del suelo y active una minibomba de 5 V mediante un módulo relé únicamente cuando la tierra esté seca, promoviendo el uso responsable del agua en el huerto escolar.

---

## Componentes Utilizados
* 1x Tarjeta de desarrollo ESP32 DevKit
* 1x Sensor analógico de humedad de suelo *(simulado con un **potenciómetro de 10 kΩ** en Wokwi)*
* 1x Módulo relé de 5 V
* 1x Minibomba de agua de 5 V *(simulada con un **LED azul + resistencia 220 Ω** en Wokwi)*
* Protoboard y cables de conexión

---

## Esquema de Conexiones

| Componente | Pin del Componente | Conexión |
| :--- | :--- | :--- |
| **Potenciómetro / Sensor suelo** | VCC / GND / SIG | 3V3 / GND / **GPIO 34** |
| **Módulo Relé 5 V** | VCC / GND / IN | 5V (VIN) / GND / **GPIO 26** |
| **Carga 5 V (LED azul / Bomba)** | COM / NO | 5V → COM · NO → R 220 Ω → LED (+) · LED (-) → GND |

---

## Seguridad Eléctrica
En prácticas escolares con relés se conectan **únicamente cargas de 5 V** (LED, ventilador o minibomba de 5 V). Nunca conectar equipos de 110 V.

---

## Contenido de la Carpeta
* `sketch.ino` — Código fuente con lectura analógica e histéresis para control de bomba.
* `diagram.json` — Configuración del circuito en Wokwi.
* `circuito.png` — Captura de pantalla de la simulación.
* `ficha-reto.pdf` — Ficha de reto de una página para docentes.

---

## Cómo Probar en Wokwi
1. Abre el proyecto en Wokwi e inicia la simulación.
2. Gira el potenciómetro por debajo del 35% para simular tierra seca: el relé cerrará el circuito y encenderá el LED azul (bomba).
3. Sube el potenciómetro por encima del 65% para simular tierra húmeda y ver cómo se apaga automáticamente.
