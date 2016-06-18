// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef JSON_CONNECTION_SERIALIZER_H
#define JSON_CONNECTION_SERIALIZER_H

#include "Serializer.hpp"
#include "Models/Connection.hpp"

namespace Json {

class ConnectionSerializer : public Serializer<Models::Connection> {
  public:
    String getTypeId() const override {
      return Models::Connection::getStaticTypeId();
    }

  protected:
    std::shared_ptr<Core::ActionResult> serialize(
      const Models::Connection& connection,
      ISerializationContext& context) const override;

    std::shared_ptr<Core::ActionResult> deserialize(
      std::shared_ptr<Models::Connection>& connection,
      ISerializationContext& context) const override;
};

}

#endif /* end of include guard: JSON_CONNECTION_SERIALIZER_H */
