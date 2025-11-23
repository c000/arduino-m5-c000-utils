#ifndef MQTT_HPP
#define MQTT_HPP

#include <PubSubClient.h>
#include <WiFiClient.h>

namespace c000 {

template <const uint8_t *MQTT_SERVER, uint16_t MQTT_PORT = 1883> class MQTT {
private:
  WiFiClient netClient;
  PubSubClient client;
  const char *clientId;

public:
  MQTT(const char *clientId) : client(netClient), clientId(clientId) {
    client.setServer(MQTT_SERVER, MQTT_PORT);
  }

  bool connect() { return client.connect(clientId); }

  void update() {
    if (!client.connected()) {
      this->connect();
    }
    client.loop();
  }

  bool publish(const char *topic, const char *payload) {
    return client.publish(topic, payload);
  }

  bool publish(const char *topic, const uint8_t *payload, size_t plength) {
    return client.publish(topic, payload, plength);
  }
};

} // namespace c000

#endif