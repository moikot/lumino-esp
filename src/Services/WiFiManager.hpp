// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef SERVICES_WIFIMANAGER_H
#define SERVICES_WIFIMANAGER_H

#include "IWiFiManager.hpp"

namespace Services {

class WiFiManager : public IWiFiManager {
  public:
    WiFiManager();

    Core::Status getWiFiNetworks(Networks& networks) const override;

    String  getDeviceName() const override;
    bool    hasConnection() const override;
    String  getNetwork() const override;
    String  getPassword() const override;
    bool    isConnected() const override;

    Core::Status connect(String network, String password) override;
    Core::Status disconnect() override;

  private:
    String network;
};

}

#endif /* end of include guard: SERVICES_WIFIMANAGER_H */
