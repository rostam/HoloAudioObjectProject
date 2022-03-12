//
// Created by Ali Rostami on 12.03.2022
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN - dont need to repeat this define in more than one cpp file
#include <boost/test/unit_test.hpp>
#include "../Src/AudioObjectManager.h"

BOOST_AUTO_TEST_SUITE(AudioObjectTest)
    BOOST_AUTO_TEST_CASE(AddTest) {
        holoplot::AudioObjectManager audioObhectManager;
    }
BOOST_AUTO_TEST_SUITE_END()