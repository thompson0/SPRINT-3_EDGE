# Monitor de Frequência Cardíaca IoT (ESP32 + Node-RED)

Este projeto simula um **monitor de batimentos cardíacos** usando **ESP32**, enviando os dados para um servidor (ex.: **Node-RED**) através de requisições HTTP.  
Os dados também são exibidos em um **display LCD I2C**.

---
## Integrantes
- Gabriel Thompson – RM563126
- Nicolas Baradel - RM563245
- João Pedro Sassarão - RM562499
- Juan Pablo Molina - RM564445

## 🛠️ Tecnologias utilizadas
- **ESP32** (WiFi integrado)  
- **C++ (Arduino IDE / PlatformIO)**  
- **Bibliotecas**:  
  - `WiFi.h` → conexão WiFi  
  - `HTTPClient.h` → envio de dados via HTTP  
  - `LiquidCrystal_I2C.h` → controle do LCD  
  - `Wire.h` → comunicação I2C  

---

## 📋 Funcionalidades
- Simula a leitura de **batimentos cardíacos (BPM)**.  
- Calcula de forma simples as **calorias gastas**.  
- Exibe os dados no **display LCD 16x2**.  
- Envia os dados em formato **JSON** para um **endpoint HTTP** (ex.: `Node-RED`).  

---

## 📡 Fluxo de dados
1. Sensor (simulado no código) → **ESP32**  
2. ESP32 → **POST JSON** → Endpoint HTTP (`Node-RED` / `httpbin`)  
3. Dados exibidos no **Serial Monitor** e no **LCD**  

---

## 🤖 Link do projeto
- https://wokwi.com/projects/441856236545510401

## 📦 Estrutura do JSON
Exemplo de payload enviado:
```json
{
  "heartRate": 82,
  "calorias": 7
}
