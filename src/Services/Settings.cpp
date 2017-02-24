#include "Settings.hpp"
#include "Core/Format.hpp"

#include <ESP8266WiFi.h>

using namespace Core;
using namespace Models;
using namespace Services;

std::string
Settings::getUniqueName() const {
  return "esp8266fs";
}

/** IP to String? */
String toStringIp(IPAddress ip) {
  String res = "";
  for (int i = 0; i < 3; i++) {
    res += String((ip >> (8 * i)) & 0xFF) + ".";
  }
  res += String(((ip >> 8 * 3)) & 0xFF);
  return res;
}

std::string
Settings::getLocalDomain() const {
  return toStringIp(WiFi.softAPIP()).c_str();
}