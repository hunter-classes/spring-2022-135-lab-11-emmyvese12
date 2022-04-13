#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "profile.h"
#include "doctest.h"

// g++ -std=c++11 -c tests.cpp

//task A
TEST_CASE("Get Username for TASK A"){
    Profile prof1A("emmyvese12", "Emmy");
    Profile prof2A("lunabellzz", "Lunaaa");
    Profile prof3A;
    CHECK(prof1A.getUsername() == "emmyvese12");
    CHECK(prof2A.getUsername() == "lunabellzz");
    CHECK(prof3A.getUsername() == "");
    CHECK(prof1A.getFullName() == "Emmy (@emmyvese12)");
    CHECK(prof2A.getFullName() == "Lunaaa (@lunabellzz)");
    CHECK(prof3A.getFullName() == " (@)");
}
