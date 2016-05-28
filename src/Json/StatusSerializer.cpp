#include "StatusSerializer.hpp"

using namespace Json;
using namespace Core;

void
StatusSerializer::serialize(const Status& status,
                            ISerializationContext& context) {
  context.setValue("code", status.getCode());
  context.setValue("title", status.getTitle());
}
