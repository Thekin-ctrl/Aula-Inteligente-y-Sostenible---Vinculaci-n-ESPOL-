# Aula Inteligente y Sostenible | Vinculación ESPOL

Repositorio oficial de código, diagramas de simulación, fichas de reto y guías para las clases prácticas sobre IoT, sensores y automatización con **ESP32** y **Arduino** orientadas a docentes de educación básica y media.

---

## 📋 Índice General de Proyectos (Playlist)

| N° | Título del Video en YouTube | Módulo | Nivel | Responsable | Estado | Carpeta / Enlace |
| :---: | :--- | :--- | :---: | :---: | :---: | :--- |
| **01** | Wokwi y Tinkercad: simula tus circuitos antes de construirlos | 0. Fundamentos y simulación | Inicial | E1 | Público | [Ver carpeta](./video-01-wokwi-tinkercad/) |
| **02** | Eco-Semáforo Inteligente: paso peatonal a demanda | 0. Fundamentos y simulación | Inicial | Sesión grabada | Grabado | [Ver carpeta](./video-02-eco-semaforo/) |
| **03** | Semáforo de Conciencia Energética: lectura analógica y LED RGB | 0. Fundamentos y simulación | Inicial | Sesión grabada | Grabado | [Ver carpeta](./video-03-semaforo-energia/) |
| **04** | Contador Automático de Reciclaje con sensor infrarrojo y pantalla OLED | 0. Fundamentos y simulación | Intermedio | Sesión grabada | Grabado | [Ver carpeta](./video-04-contador-reciclaje/) |
| **05** | Del simulador al ESP32 real: Arduino IDE, drivers y primera carga | 0. Fundamentos y simulación | Inicial | E2 | Por grabar | [Ver carpeta](./video-05-simulador-real/) |
| **06** | Monitor de Confort Térmico del Aula con DHT11 y OLED | 1. Monitoreo ambiental | Intermedio | **E3** | Por grabar | [Ver carpeta](./video-06-monitor-confort/) |
| **07** | Registro Ambiental en la Nube con ThingSpeak | 1. Monitoreo ambiental | Intermedio | E1 | Por grabar | [Ver carpeta](./video-07-registro-thingpeak/) |
| **08** | Medidor de Iluminación Natural: ¿hace falta encender la luz? | 1. Monitoreo ambiental | Intermedio | E2 | Por grabar | [Ver carpeta](./video-08-medidor-luz/) |
| **09** | Estación Ambiental Multiparámetro: temperatura, humedad y luz | 1. Monitoreo ambiental | Avanzado | **E3** | Por grabar | [Ver carpeta](./video-09-estacion-multiparametro/) |
| **10** | Iluminación Automática con Relé y Sensor de Luz | 2. Automatización | Intermedio | E1 | Por grabar | [Ver carpeta](./video-10-iluminacion-rele/) |
| **11** | Alarma de Ocupación Fuera de Horario con sensor PIR | 2. Automatización | Intermedio | E2 | Por grabar | [Ver carpeta](./video-11-alarma-pir/) |
| **12** | Notificaciones al Celular con Telegram desde el ESP32 | 2. Automatización | Avanzado | **E3** | Por grabar | [Ver carpeta](./video-12-telegram/) |
| **13** | Ventilación Automática con Servomotor y DHT11 | 2. Automatización | Intermedio | E1 | Por grabar | [Ver carpeta](./video-13-ventilacion-servo/) |
| **14** | Cortina Solar Automatizada con dos sensores de luz | 2. Automatización | Avanzado | E2 | Por grabar | [Ver carpeta](./video-14-cortina-solar/) |
| **15** | Servidor Web en el ESP32: control de LEDs desde el navegador | 3. Conectividad e IoT | Intermedio | **E3** | Por grabar | [Ver carpeta](./video-15-servidor-web/) |
| **16** | Panel Web de Monitoreo Ambiental en tiempo real | 3. Conectividad e IoT | Avanzado | E1 | Por grabar | [Ver carpeta](./video-16-panel-web/) |
| **17** | Barrera de Acceso Inteligente con Bluetooth | 3. Conectividad e IoT | Avanzado | E2 | Por grabar | [Ver carpeta](./video-17-barrera-bluetooth/) |
| **18** | Sistema de Riego Automático para el huerto escolar | 4. Agua e integración | Intermedio | **E3** | Por grabar | [Ver carpeta](./video-18-riego-automatico/) |
| **19** | Medidor de Nivel de Agua con sensor ultrasónico | 4. Agua e integración | Intermedio | E1 | Por grabar | [Ver carpeta](./video-19-nivel-agua/) |
| **20** | Integración de Proyectos: cómo combinar sensores sin que el código falle | 4. Agua e integración | Avanzado | E2 | Por grabar | [Ver carpeta](./video-20-integracion/) |
| **21** | Guía del Proyecto Final Docente: de la idea al prototipo | 4. Agua e integración | Guía | **E3** | Por grabar | [Ver carpeta](./video-21-proyecto-final/) |

---

## 🛠️ Instrucciones para Colaboradores (E1, E2 y E3)

Cada responsable debe crear una carpeta independiente en la raíz de este repositorio por cada video asignado (siguiendo el formato `video-XX-nombre-corto/`). Cada carpeta debe contener obligatoriamente:
1. `sketch.ino` — Código fuente de Arduino/ESP32.
2. `diagram.json` — Archivo de configuración del circuito en Wokwi.
3. `circuito.png` — Captura de pantalla del diseño de la simulación.
4. `ficha-reto.pdf` — Ficha resumen de una página con objetivo, materiales y retos (Básico, Intermedio, Avanzado).
5. `README.md` — Descripción breve y pasos de reproducción local.
