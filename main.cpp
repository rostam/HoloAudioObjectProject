#include "Src/AudioObjectManager.h"
#include <iostream>
#include <functional>
#include <variant>
#include <vector>


using namespace std;
using namespace holoplot;
 using var_t = std::variant<std::function<void(void)>, std::function<void(int)>>;

int main() {
    holoplot::AudioObjectManager audioObjectManager;
    Position A({1,1,1}); 
    Position B({2,2,2});
    Position C({3,3,3});
    Position D({4,4,4});
    Position E({5,5,5});
    Position F({6,6,6});
    Position G({7,7,7});

    AudioObject audioObject1 ({1}, A);
    AudioObject audioObject2 ({2}, B);
    audioObjectManager.add(audioObject1);
    audioObjectManager.add(audioObject2);
    audioObjectManager.changePosition({1}, C);
    
    AudioObject audioObject3 ({3}, D);
    audioObjectManager.add(audioObject3);
    audioObjectManager.changePosition({2}, E);
    audioObjectManager.remove({1});
    audioObjectManager.changePosition({3}, F);
    audioObjectManager.changePosition({3}, G);
    audioObjectManager.undo();
    audioObjectManager.undo();

    std::function<void(int)> f1;
    std::function<void(int)> f2;    

    cout << "salam";
    return 0;
}