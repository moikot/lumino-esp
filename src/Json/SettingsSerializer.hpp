// Copyright Sergey Anisimov 2016-2017
// MIT License
//
// Moikot
// https://github.com/anisimovsergey/moikot

#ifndef JSON_SETTINGS_SERIALIZER_HPP
#define JSON_SETTINGS_SERIALIZER_HPP

#include "Serializer.hpp"
#include "Models/Settings.hpp"

namespace Json {

class SettingsSerializer : public Serializer<Models::Settings> {
  public:
    String getTypeId() const override {
      return Models::Settings::getStaticTypeId();
    }

  protected:
    std::unique_ptr<Core::IActionResult> serialize(
      const Models::Settings& settings,
      ISerializationContext& context) const override;

    std::unique_ptr<Core::IActionResult> deserialize(
      std::shared_ptr<Models::Settings>& settings,
      ISerializationContext& context) const override;
};

}

#endif /* end of include guard: JSON_SETTINGS_SERIALIZER_HPP */
