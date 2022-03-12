#pragma once
#include <string>
#include "AudioObject.h"
#include <memory>
namespace holoplot{

  class AudioObjectAction {
  public:
    enum Action { ADD, REMOVE, CHANGE_POSITION };
    Action action; 
    AudioObject audioObject;
    Id audioObjectId;
    Position position;
    
    AudioObjectAction(Action action, const Id& audioObjectId) : action (action), audioObjectId (audioObjectId) {}
    AudioObjectAction(Action action, const AudioObject& audioObject) : action (action), audioObject (audioObject) {}
    AudioObjectAction(Action action, const Id& audioObjectId, const Position& position) 
      : action (action), audioObjectId (audioObjectId), position (position) {}
  };
};