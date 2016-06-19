// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef SERVICES_HTTP_SERVER_ASYNC_H
#define SERVICES_HTTP_SERVER_ASYNC_H

#include "IHttpServer.hpp"
#include "ILoopedService.hpp"

#include "Json/ISerializationService.hpp"
#include "Controllers/IApiController.hpp"

#include <memory>
#include <list>
#include <algorithm>

#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

namespace Services {

class HttpServerAsync : public IHttpServer, public ILoopedService {
  public:
    HttpServerAsync(int port,
      std::shared_ptr<const Json::ISerializationService> serializationService);
    virtual ~HttpServerAsync();

    void start();

    virtual void addGetHandler(
      const String& uri,
      TRequestHandler requestHandler) override;
    virtual void addDeleteHandler(
      const String& uri,
      TRequestHandler requestHandler) override;

    virtual void addPostHandler(
      const String& uri,
      TRequestWithEntityHandler requestHandler) override;
    virtual void addPutHandler(
      const String& uri,
      TRequestWithEntityHandler requestHandler) override;

    virtual void addApiController(
      std::shared_ptr<Controllers::IApiController> controller) override;
    virtual void addHttpSender(
      std::shared_ptr<IHttpSender> httpSender) override;

    void loop() override {};

  private:
    std::unique_ptr<AsyncWebServer> server;
    std::list<std::shared_ptr<Controllers::IApiController>> controllers;
    std::list<std::shared_ptr<IHttpSender>> senders;
    std::shared_ptr<const Json::ISerializationService>  serializationService;

    void addHandler(
      const String& uri,
      WebRequestMethod method,
      TRequestHandler requestHandler);

    void addHandler(
      const String& uri,
      WebRequestMethod method,
      TRequestWithEntityHandler requestHandler);

    void sendResponse(
      IHttpRequest& request,
      std::shared_ptr<Core::IActionResult> result);

    std::shared_ptr<IHttpSender> getSender(String typeId) const;

    bool    isIntercepted(AsyncWebServerRequest* request);
    void    redirectToSelf(AsyncWebServerRequest* request);
};

}

#endif /* end of include guard: SERVICES_HTTP_SERVER_ASYNC_H */
