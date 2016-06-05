// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef SERVICES_HTTPSERVER_H
#define SERVICES_HTTPSERVER_H

#include "IHttpServer.hpp"

#include "IStatusCodeRegistry.hpp"
#include "ILoopedService.hpp"
#include "Controllers/IApiController.hpp"
#include "Json/ISerializationService.hpp"

#include <WString.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <memory>
#include <list>

namespace Services {

class HttpServer : public IHttpServer, public ILoopedService {
  public:
    HttpServer(int port,
      std::shared_ptr<const IStatusCodeRegistry> registry,
      std::shared_ptr<const Json::ISerializationService> serializationService);

    void start();
    void loop() override;

    virtual void addGetHandler(
      const String& uri,
      THandlerFunction fn) override;
    virtual void addPutHandler(
      const String& uri,
      THandlerFunction fn) override;
    virtual void addPostHandler(
      const String& uri,
      THandlerFunction fn) override;
    virtual void addDeleteHandler(
      const String& uri,
      THandlerFunction fn) override;

    virtual void addApiController(
      std::shared_ptr<Controllers::IApiController> controller) override;

    virtual void setLocation(const String& location) override;

    virtual Core::Status getJson(
      std::shared_ptr<Core::IEntity>& entity) override;

    virtual void sendJson(
      const Core::Status& status) override;
    virtual void sendJson(
      const Core::IEntity& entity) override;

  private:
    std::unique_ptr<ESP8266WebServer> server;
    std::list<std::shared_ptr<Controllers::IApiController>> controllers;

    std::shared_ptr<const IStatusCodeRegistry>          registry;
    std::shared_ptr<const Json::ISerializationService>  serializationService;

    String  getContentType(String filename);
    bool    handleFileRead(String path);
};

}

#endif /* end of include guard: SERVICES_HTTPSERVER_H */
