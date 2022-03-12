#include "AudioObjectManager.h"

namespace holoplot {

  void AudioObjectManager::add(const AudioObject &audioObject) {    
    history.push(AudioObjectAction(AudioObjectAction::ADD, audioObject.id));
    audioObjects[audioObject.id.id] = audioObject;
  }

  void AudioObjectManager::remove(const Id &audioObjectId) {
    history.push(AudioObjectAction(AudioObjectAction::REMOVE, audioObjects[audioObjectId.id]));
    audioObjects.erase(audioObjectId.id);
  }

  void AudioObjectManager::changePosition(const Id &audioObjectId, const Position &audiObjectPosition) {
    history.push(AudioObjectAction(AudioObjectAction::CHANGE_POSITION, audioObjects[audioObjectId.id]));
    audioObjects[audioObjectId.id] = AudioObject(audioObjectId, audiObjectPosition);
  }

  void AudioObjectManager::undo() {
    AudioObjectAction audioObjectAction = history.top();
    history.pop();
    switch (audioObjectAction.action)
    {
    case AudioObjectAction::ADD:
      this->remove(audioObjectAction.audioObjectId);
      break;

    case AudioObjectAction::REMOVE:
      this->add(audioObjectAction.audioObject);
      break;
    
    case AudioObjectAction::CHANGE_POSITION:
      this->changePosition(audioObjectAction.audioObjectId,audioObjectAction.position);
      break;
    
    
    default:
      break;
    }
  }

};