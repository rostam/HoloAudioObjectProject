#pragma once
#include "Position.h"
#include "Id.h"

namespace holoplot {

  class AudioObject {
  public:
    Id id;
    Position position;
    AudioObject() : id({0}), position({0,0,0}) {}
    AudioObject(const Id& id, const Position& position) : id(id), position(position) {}
    AudioObject(const AudioObject& audioObject) : id(audioObject.id), position(audioObject.position) {}
  };

}