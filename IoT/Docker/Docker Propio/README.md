# Sistema Web de Registro de Pacientes para Veterinaria

## Descripción

Este proyecto despliega una aplicación web para el **registro y seguimiento de pacientes en una veterinaria** usando **Docker**, **Python**, **Flask**, **HTML**, **CSS** y **JavaScript**.

La interfaz permite capturar datos como:

- Nombre del paciente
- Nombre del propietario
- Correo de contacto
- Fecha de alta
- Síntomas

También incluye un área para visualizar el listado de pacientes registrados.

---

## Estructura del proyecto

~~~bash
Propio/
├── Dockerfile
├── Makefile
├── app.py
├── requirements.txt
└── Veterinario/
    ├── index.html
    ├── dist/
    │   └── css/
    │       └── output.css
    └── js/
        ├── app.js
        ├── funciones.js
        ├── selectores.js
        ├── variables.js
        └── classes/
~~~

---

## ¿Por qué se usa Python?

Aunque la interfaz está hecha con **HTML, CSS y JavaScript**, esos archivos necesitan un **servidor web** para cargarse correctamente en el navegador.

En este proyecto:

- **JavaScript** maneja la lógica del frontend
- **Python + Flask** sirven los archivos al navegador
- **Docker** encapsula todo el entorno

---

## Dockerfile

### Código

~~~dockerfile
FROM python:3.12-slim

WORKDIR /app

RUN apt-get update && apt-get install -y make && rm -rf /var/lib/apt/lists/*

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY app.py .
COPY Makefile .
COPY Veterinario ./Veterinario

EXPOSE 5000

CMD ["make", "run"]
~~~

- `FROM python:3.12-slim`: usa Python 3.12 como base
- `WORKDIR /app`: define la carpeta de trabajo
- `RUN ... make ...`: instala `make`
- `COPY requirements.txt .`: copia dependencias
- `RUN pip install ...`: instala Flask
- `COPY app.py .`: copia la app Flask
- `COPY Makefile .`: copia el Makefile
- `COPY Veterinario ./Veterinario`: copia el frontend
- `EXPOSE 5000`: indica el puerto usado
- `CMD ["make", "run"]`: arranca la aplicación

---

## Makefile

### Código

~~~makefile
APP_FILE=app.py

run:
	python $(APP_FILE)
~~~

Este archivo automatiza la ejecución del proyecto.  
Cuando Docker inicia el contenedor, ejecuta `make run`, y eso a su vez ejecuta:

~~~bash
python app.py
~~~

---

## requirements.txt

### Código

~~~txt
Flask==3.0.3
~~~

Define la dependencia principal del proyecto: **Flask**.

---

## app.py

### Código

~~~python
from flask import Flask, send_from_directory, jsonify
from datetime import datetime
import os

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
FRONTEND_DIR = os.path.join(BASE_DIR, "Veterinario")

app = Flask(__name__)

@app.route("/")
def index():
    return send_from_directory(FRONTEND_DIR, "index.html")

@app.route("/status")
def status():
    return jsonify({
        "mensaje": "Servicio funcionando correctamente",
        "lenguaje": "Python",
        "framework": "Flask",
        "autor": "Jorge",
        "fecha": datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    })

@app.route("/<path:path>")
def servir_archivos(path):
    return send_from_directory(FRONTEND_DIR, path)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
~~~

- `Flask`: crea el servidor web
- `send_from_directory`: sirve archivos como HTML, CSS y JS
- `jsonify`: devuelve respuestas JSON
- `FRONTEND_DIR`: apunta a la carpeta `Veterinario`
- `@app.route("/")`: carga `index.html`
- `@app.route("/status")`: devuelve un JSON de prueba
- `@app.route("/<path:path>")`: sirve archivos estáticos
- `app.run(host="0.0.0.0", port=5000)`: inicia el servidor en el puerto 5000

## Construcción de la imagen

~~~bash
sudo docker build -t contenedor-flask-jorge .
~~~

Este comando construye la imagen Docker a partir del `Dockerfile`.

---

## Ejecución del contenedor

~~~bash
sudo docker run -d -p 5000:5000 --name flask-jorge contenedor-flask-jorge
~~~

Este comando:

- ejecuta el contenedor en segundo plano
- conecta el puerto 5000 del host con el del contenedor
- asigna el nombre `flask-jorge`

---

## Verificación

Para comprobar que el contenedor está corriendo:

~~~bash
sudo docker ps
~~~

Para verificar la ruta de estado:

~~~bash
curl http://localhost:5000/status
~~~

---

## Acceso desde el navegador

Para abrir la aplicación en Firefox:

~~~bash
firefox http://localhost:5000
~~~

También se puede abrir escribiendo en el navegador:

~~~text
http://localhost:5000
~~~

---

## Flujo general

~~~text
Docker construye la imagen
→ Docker crea el contenedor
→ El contenedor ejecuta make run
→ make ejecuta python app.py
→ Flask levanta el servidor
→ El navegador entra a http://localhost:5000
→ Flask entrega index.html
→ El navegador carga CSS y JavaScript
→ La aplicación se muestra en pantalla
~~~
