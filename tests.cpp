#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "profile.h"
#include <string>

// g++ -std=c++11 -c tests.cpp

//task A
TEST_CASE("Get username for TASK A"){
    Profile prof1A("emmyvese12", "Emmy");
    Profile prof2A("lunabellzz", "Lunaaa");
    CHECK(prof1A.getUsername() == "emmyvese12");
    CHECK(prof2A.getUsername() == "lunabellzz");
}
