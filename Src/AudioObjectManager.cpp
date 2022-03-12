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
    if(history.top().action != AudioObjectAction::CHANGE_POSITION) {
      history.push(AudioObjectAction(AudioObjectAction::CHANGE_POSITION, audioObjectId, audioObjects[audioObjectId.id].position));
    }
    audioObjects[audioObjectId.id] = AudioObject(audioObjectId, audiObjectPosition);
  }

  /**
   * @brief undo()
   * 
   * Undos the last action with an exception of ignoring several CHANGE_POSITION actions
   * and gets back to the situation before the first change position. 
   * 
   * 
   * (An important point here) The reason of second history.pop() is that not inroducing 
   * new entries in the history stack by calling the actions again. 
   * 
   */
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
    history.pop();

  }

  AudioObject AudioObjectManager::get(const Id& audioObjectId) {
    return audioObjects[audioObjectId.id];
  }

};