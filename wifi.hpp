#ifndef WIFI_HPP
#define WIFI_HPP

#include <WiFi.h>

namespace c000 {

template <const char *SSID, const char *PASSWORD> class WIFI {
public:
  void connect() {
    WiFi.begin(SSID, PASSWORD);
    while (1) {
      int result = WiFi.waitForConnectResult();
      if (result == WL_CONNECTED) {
        break;
      }
      delay(100);
    }
  }
};

} // namespace c000

#endif