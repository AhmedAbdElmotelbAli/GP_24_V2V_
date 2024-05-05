"""
=====================================================================================
File:            [MQTT_Publish.py]
Owner:           [Hassan Bahnasy]
Brief:           [This file publishes data to the MQTT broker from the RPi]
=====================================================================================
"""

import paho.mqtt.client as mqtt
from datetime import datetime
import time
import sys

# Callback function for MQTT connection
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker")
    else:
        print("Failed to connect to MQTT broker")

# Callback function for MQTT message reception
def on_message(client, userdata, msg):
    print("Received message: Topic - {}, Message - {}".format(msg.topic, msg.payload.decode()))


def mqtt_publish(ip,port,message):
    # Create MQTT client instance
    client = mqtt.Client()

    # Set callback functions
    client.on_connect = on_connect
    client.on_message = on_message

    # Set username and password
    client.username_pw_set("GP_28", "bahnasy")

    # Connect to MQTT broker (replace 'localhost' with the IP address of the Ubuntu machine running the MQTT broker)
    client.connect(ip, port)

    # Subscribe to a topic (replace 'test/topic' with the desired topic)
    client.subscribe("test")

    # Start MQTT network loop
    client.loop_start()
    client.publish("test",message)
    # i=0
    # while i<10 :
    #     cur_time = datetime.now()
    #     cur_time_string = cur_time.strftime("%Y-%m-%d %H:%M:%S")
    #     client.publish("test", cur_time_string)
    #     i = i + 1 
    #     time.sleep(1)
        
    # Disconnect from MQTT broker
    client.disconnect()

    # Stop MQTT network loop
    client.loop_stop()
    
def main():
    if len(sys.argv) != 3:
        print("Usage: python script.py <broker_ip> <broker_port>")
        return

    # Extract MQTT broker IP and port from command-line arguments
    broker_ip = sys.argv[1]
    broker_port = int(sys.argv[2])

    # Define message to publish
    message = "Hello, Vehiclevo!"

    # Publish message to MQTT broker
    mqtt_publish(broker_ip, broker_port, message)
    print ("Sent")

if __name__ == "__main__":
    main()