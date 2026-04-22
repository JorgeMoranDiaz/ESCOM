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
