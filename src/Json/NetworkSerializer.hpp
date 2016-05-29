// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef JSON_NETWORK_SERIALIZER_H
#define JSON_NETWORK_SERIALIZER_H

#include "Models/Network.hpp"
#include "Serializer.hpp"

namespace Json {

class NetworkSerializer : public Serializer<Models::Network> {
  protected:
    void serialize(const Models::Network& network,
                   ISerializationContext& context) override;
};

}

#endif /* end of include guard: JSON_NETWORK_SERIALIZER_H */
