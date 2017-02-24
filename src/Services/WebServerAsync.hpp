// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef SERVICES_WEB_SERVER_ASYNC_HPP
#define SERVICES_WEB_SERVER_ASYNC_HPP

#include "Settings.hpp"
#include "Core/ILogger.hpp"
#include "Messaging/IMessageQueue.hpp"
#include "Serialization/ISerializationService.hpp"

#include <memory>
#include <list>
#include <algorithm>

#include <WString.h>
#include <Hash.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncWebServer.h>

namespace Services {

class WebServerAsync : public Core::IService {
  public:
    WebServerAsync(
      std::shared_ptr<const Settings> settings,
      Messaging::IMessageQueue& messageQueue,
      Serialization::ISerializationService& serializer,
      Core::ILogger& logger);

    void start();

  private:
    std::shared_ptr<const Settings>       settings;
    std::unique_ptr<AsyncWebServer>       httpServer;
    std::unique_ptr<AsyncWebSocket>       wsServer;
    Messaging::IMessageQueue&                  messageQueue;
    Serialization::ISerializationService&      serializer;
    Core::ILogger&                             logger;
    std::list<std::unique_ptr<Messaging::QueueGenericClient>>  queueClients;

    bool    isIntercepted(AsyncWebServerRequest* request);
    void    redirectToSelf(AsyncWebServerRequest* request);

    void onSocketEvent(AsyncWebSocket* server, AsyncWebSocketClient* client,
      AwsEventType type, void* arg, uint8_t *data, size_t len);

    std::string getClientId(AsyncWebSocketClient* client);
    Messaging::QueueGenericClient* findQueueClient(AsyncWebSocketClient* client);
    void sendToClinet(AsyncWebSocketClient* client, const Core::IEntity& entity);

    // Events
    void onClientConnected(AsyncWebSocketClient* client);
    void onClientDisconnected(AsyncWebSocketClient* client);
    void onTextReceived(AsyncWebSocketClient* client, const std::string& text);
    void onResponse(AsyncWebSocketClient* client, const Messaging::Response& response);
    void onNotification(AsyncWebSocketClient* client, const Messaging::Event& event);
};

}

#endif /* end of include guard: SERVICES_WEB_SERVER_ASYNC_HPP */
