
#pragma once
#include "IAudioObjectManager.h"
namespace holoplot {
  struct Id;
  struct Position;
  class AudioObject;
  class AudioObjectManager : public IAudioObjectManager
  {
  public:
    void add(const AudioObject &);
    void remove(const Id &);
    void changePosition(const Id &, const Position &);
    void undo();
  };
}