#include "ListSerializer.hpp"

using namespace Json;
using namespace Core;

void
ListSerializer::serialize(const IList& list,
                          ISerializationContext& context) {
  context.setType("status");
}
