
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
    std::stack<AudioObjectAction> history;

  public:
    void add(const AudioObject &);
    void remove(const Id &);
    void changePosition(const Id &, const Position &);
    void undo();
  };
}