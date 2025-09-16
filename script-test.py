import requests
import random
import time

url = "http://localhost:1880/esp32"

while True:
    data = {
        "heartRate": random.randint(70, 110),
        "calorias": random.randint(5, 15)
    }
    r = requests.post(url, json=data)
    print("Enviado:", data, "| Resposta:", r.status_code)
    time.sleep(2)
