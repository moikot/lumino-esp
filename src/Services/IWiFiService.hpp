// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef SERVICES_I_WIFISERVICE_H
#define SERVICES_I_WIFISERVICE_H

#include "Core/Status.hpp"
#include "Models/Network.hpp"

#include <list>

class IWiFiService {
  typedef std::list<Models::Network> Networks;

  public:
    virtual Core::Status getWiFiNetworks(Networks& networks) const = 0;
};

#endif /* end of include guard: SERVICES_I_WIFISERVICE_H */
