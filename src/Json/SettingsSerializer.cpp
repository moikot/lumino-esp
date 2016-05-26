#include "SettingsSerializer.hpp"
#include "ISerializationContext.hpp"
#include "Models/Settings.hpp"

using namespace Json;
using namespace Models;

Settings
SettingsSerializer::deserialie(const ISerializationContext& context) {
  String deviceName = context.getString("name");
  String networkSsid = context.getString("wifi_network");
  String networkPassword = context.getString("wifi_password");
  Settings settings(deviceName, networkSsid, networkPassword);
  settings.setIsConnected(context.getBool("connected"));
  return settings;
}

void
SettingsSerializer::serialie(const Settings& settings, ISerializationContext& context) {
  context.setType("settings");
  context.setValue("name", settings.getDeviceName());
  context.setValue("wifi_network", settings.getNetworkSsid());
  context.setValue("wifi_password", settings.getNetworkPassword());
  context.setValue("connected", settings.getIsConnected());
}
