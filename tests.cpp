#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "profile.h"
#include "network.h"
#include "doctest.h"

// g++ -std=c++11 -c tests.cpp

//task A
TEST_CASE("Get Username and Display Name for TASK A"){
    Profile prof1("emmyvese12", "Emmy");
    Profile prof2("lunabellzz", "Lunaaa");
    Profile prof3;
    Profile prof4("thelori", "Lori");
    CHECK(prof1.getUsername() == "emmyvese12");
    CHECK(prof2.getUsername() == "lunabellzz");
    CHECK(prof3.getUsername() == "");
    CHECK(prof1.getFullName() == "Emmy (@emmyvese12)");
    CHECK(prof2.getFullName() == "Lunaaa (@lunabellzz)");
    CHECK(prof3.getFullName() == " (@)");
    CHECK(prof4.getUsername() == "thelori");
    CHECK(prof4.getFullName() == "Lori (@thelori)");
}

//task B
TEST_CASE("Adding User to the Network for TASK B"){
    Network nw1, nw2, nw3, nw4, nw5;
    CHECK(nw1.addUser("emmy", "Emmy") == 1);
    CHECK(nw2.addUser("kris7", "Kris") == 1);
    CHECK(nw3.addUser("luna!", "Luna") == 0);
    CHECK(nw4.addUser("ash-2", "Ash") == 0);
    CHECK(nw5.addUser("liz zy", "Liz") == 0);
    CHECK(nw5.addUser("drewdrew", "D") == 1);
}