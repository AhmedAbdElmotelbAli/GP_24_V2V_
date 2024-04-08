#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define MAX_STRING_LENGTH 200 // Change this to your desired maximum string length

char receivedString[MAX_STRING_LENGTH + 1]; // +1 for null terminator
int stringIndex = 0;

const char* ssid = "Redmi";
const char* password = "bahnasy2020";
const char* mqtt_server = "0.tcp.eu.ngrok.io";
const int mqtt_port = 12203;
const char* mqtt_username = "GP_28";
const char* mqtt_password = "bahnasy";
const char* mqtt_topic = "test";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on topic: ");
  Serial.println(topic);

  // Copy payload to receivedString buffer
  stringIndex = 0;
  for (int i = 0; i < length; i++) {
    receivedString[stringIndex++] = (char)payload[i];
    if (stringIndex >= MAX_STRING_LENGTH) {
      break;
    }
  }
  receivedString[stringIndex] = '\0'; // Null terminate the string

  // Print the received message
  Serial.print("Received message: ");
  Serial.println(receivedString);

  // Send the received message to the Tiva C device via UART
  Serial.print("Sending message to Tiva C: ");
  Serial.println(receivedString); // Print the message being sent to Tiva C
  Serial1.println(receivedString); // Send the message via UART to Tiva C
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("NodeMCU_Client", mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600); // Initialize UART communication with Tiva C
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}