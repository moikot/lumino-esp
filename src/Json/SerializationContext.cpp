#include "SerializationContext.hpp"

using namespace Json;
using namespace Core;

SerializationContext::SerializationContext(
  const ISerializationService& serializationService,
  std::shared_ptr<DynamicJsonBuffer> jsonBuffer,
  JsonObject& jsonObject) :
  serializationService(serializationService),
  jsonBuffer(jsonBuffer),
  jsonObject(jsonObject) {
}

String
SerializationContext::toString() const {
  String str;
  jsonObject.printTo(str);
  return str;
}

std::unique_ptr<Core::IActionResult>
SerializationContext::getStringValue(const String& key, String& value) {

  auto jsonVal = jsonObject[key];
  if (!jsonVal.success())
    return StatusResult::BadRequest("Key """ + key + """ is not defined.");

  if (!jsonVal.is<const char*>())
    return StatusResult::BadRequest("Value for key """ + key + """ should be a string.");

  value = (const char*)jsonVal;
  return StatusResult::OK();
}

std::unique_ptr<Core::IActionResult>
SerializationContext::getBoolValue(const String& key, bool& value) {

  auto jsonVal = jsonObject[key];
  if (!jsonVal.success())
    return StatusResult::BadRequest("Key """ + key + """ is not defined.");

  if (!jsonVal.is<bool>())
    return StatusResult::BadRequest("Value for key """ + key + """ should be a boolean.");

  value = (bool)jsonVal;
  return StatusResult::OK();
}

void
SerializationContext::setValue(const String& key, const String& value) {
  jsonObject[key] = value;
}

void
SerializationContext::setValue(const String& key, int value) {
  jsonObject[key] = value;
}

void
SerializationContext::setValue(const String& key, bool value) {
  jsonObject[key] = value;
}

void
SerializationContext::setValue(const String& key, const IList& list) {
  JsonArray& array = jsonObject.createNestedArray(key);
  list.forEach([&](const IEntity& element) {
    JsonObject& nestedObject = array.createNestedObject();
    SerializationContext context(serializationService, jsonBuffer, nestedObject);
    serializationService.serialize(element, context);
  });
}
