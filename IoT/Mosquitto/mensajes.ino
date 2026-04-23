#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "192.168.1.90";   // CAMBIA esto por la IP de tu Raspberry
const int mqtt_port = 1883;
const char* topic = "practica/esp32";

WiFiClient espClient;
PubSubClient client(espClient);

void conectarWiFi() {
  Serial.println("Conectando a WiFi...");
  WiFi.begin(ssid, password, 6);  // canal 6 para conectar más rápido en Wokwi

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectado");
  Serial.print("IP de la ESP32: ");
  Serial.println(WiFi.localIP());
}

void conectarMQTT() {
  while (!client.connected()) {
    Serial.print("Conectando al broker MQTT... ");

    String clientId = "ESP32Sim-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("conectado");
    } else {
      Serial.print("fallo, estado=");
      Serial.print(client.state());
      Serial.println(" reintentando en 2 segundos");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  conectarWiFi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    conectarMQTT();
  }

  client.loop();

  String mensaje = "Hola desde ESP32";
  Serial.print("Publicando: ");
  Serial.println(mensaje);

  client.publish(topic, mensaje.c_str());

  delay(5000);
}