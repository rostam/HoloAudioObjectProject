//
// Created by Ali Rostami on 12.03.2022
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN - dont need to repeat this define in more than one cpp file
#include <boost/test/unit_test.hpp>
#include "../Src/AudioObjectManager.h"
#include <iostream>

using namespace holoplot;

  
  // std::ostream& operator<<(std::ostream& os, const Position& position) {
  //     os << position.x << "," << position.y << "," << position.z;
  //     return os;
  // }

  // bool operator== (Position position1, Position position2) {
  //   return position1.x == position2.x && position1.y == position2.y && position1.z == position2.z;
  // };

BOOST_AUTO_TEST_SUITE(AudioObjectTest)
    BOOST_AUTO_TEST_CASE(AddTest) {

      Position A({1,1,1}); 
      Position B({2,2,2});
      Position C({3,3,3});
      Position D({4,4,4});
      Position E({5,5,5});
      Position F({6,6,6});
      Position G({7,7,7});

      AudioObject audioObject1 ({1}, A);
      AudioObject audioObject2 ({2}, B);
      
      AudioObjectManager audioObjectManager;
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

      Position pos1 = audioObjectManager.get({1}).position;
      Position pos2 = audioObjectManager.get({2}).position;
      Position pos3 = audioObjectManager.get({3}).position;
      BOOST_ASSERT(pos1.x == C.x && pos1.y == C.y && pos1.z == C.z);
      BOOST_ASSERT(pos2.x == E.x && pos2.y == E.y && pos2.z == E.z);
      BOOST_ASSERT(pos3.x == D.x && pos3.y == D.y && pos3.z == D.z);
    }
BOOST_AUTO_TEST_SUITE_END()