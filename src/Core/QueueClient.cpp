#include "QueueClient.hpp"
#include "IMessageQueue.hpp"

using namespace Core;

QueueClient::QueueClient(String clientId, IMessageQueue& messageQueue) :
  clientId(clientId), messageQueue(messageQueue) {
}

StatusResult::Unique
QueueClient::sendMessage(Message::Shared request) {
  request->addTag("sender", clientId);
  return messageQueue.sendMessage(request);
}

void
QueueClient::onResponse(const Response& response) {
  if (onResponseHandler)
    onResponseHandler(response);
}

void
QueueClient::onNotification(const Notification& notification) {
  if (onNotificationHandler)
    onNotificationHandler(notification);
}
