#include "NetworksController.hpp"

#include "Core/Status.hpp"
#include "Core/Logger.hpp"
#include "Services/IHttpServer.hpp"

#include <Arduino.h>

using namespace Core;
using namespace Services;
using namespace Controllers;

NetworksController::NetworksController(
  std::shared_ptr<const IWiFiManager> wifiManager) :
  wifiManager(wifiManager) {
}

void
NetworksController::registerOn(IHttpServer &httpServer) {
  httpServer.addGetHandler("/wifi_networks", [&](IHttpRequest& request) {
    Logger::message("/wifi_networks");
    onGetWiFiNetworks(request);
  });
}

std::shared_ptr<Core::ActionResult>
NetworksController::onGetWiFiNetworks(IHttpRequest& request) {
  std::shared_ptr<List<Models::Network>> networks;
  auto actionResult = wifiManager->getWiFiNetworks(networks);
  if (!actionResult->isOk())
    return actionResult;

  ActionResult::Success(networks);
}
