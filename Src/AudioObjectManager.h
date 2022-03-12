
#pragma once
#include "IAudioObjectManager.h"
#include <map>
#include <stack>
#include <variant>
#include <functional>
#include "AudioObjectAction.h"
namespace holoplot {
  struct Id;
  struct Position;
  class AudioObject;
  class AudioObjectManager : public IAudioObjectManager
  {
    std::map<int, AudioObject> audioObjects;
  public:
      std::stack<AudioObjectAction> history;

    void add(const AudioObject &);
    void remove(const Id &);
    void changePosition(const Id &, const Position &);
    AudioObject get(const Id &);
    void undo();
  };
}