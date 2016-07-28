// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef CORE_QUEUE_CLIENT_HPP
#define CORE_QUEUE_CLIENT_HPP

#include "StatusResult.hpp"
#include "IMessage.hpp"

#include <functional>

namespace Core {

class IMessageQueue;

class QueueClient {
  TYPE_PTRS(QueueClient)
  public:
    QueueClient(String clientId, IMessageQueue& messageQueue);

    String getId() { return clientId; }

    StatusResult::Unique sendMessage(Message::Shared request);

    void onResponse(const Response& response);
    void onNotification(const Notification& notification);

    void setOnResponse(std::function<void(const Response&)> onResponse) {
      onResponseHandler = onResponse;
    }

    void setOnNotification(std::function<void(const Notification&)> onNotification) {
      onNotificationHandler = onNotification;
    }

  private:
    String clientId;
    IMessageQueue& messageQueue;
    std::function<void(const Response&)> onResponseHandler;
    std::function<void(const Notification&)> onNotificationHandler;
};

}

#endif /* end of include guard: CORE_QUEUE_CLIENT_HPP */