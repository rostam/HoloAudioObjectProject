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
    
    AudioObjectAction(Action action, Id audioObjectId) : action (action), audioObjectId (audioObjectId) {}
    AudioObjectAction(Action action, AudioObject audioObject) : action (action), audioObject (audioObject) {}
    AudioObjectAction(Action action, Id audioObjectId, Position position) : action (action), audioObjectId (audioObjectId), position (position) {}
  };
};