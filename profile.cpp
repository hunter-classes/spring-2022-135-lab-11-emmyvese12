#include <iostream>
#include <string>
#include "profile.h"

std::string Profile::getUsername(){
    return username;
}

std::string Profile::getFullName(){
    std::string output = displayname + "(@" + username + ")";
    return output; //prints the format of displayname and handle
}

void Profile::setDisplayName(std::string dspn){
    displayname = dspn; //changes display name
}

//member initializer list
Profile::Profile(std::string usrn, std::string dspn) : username(usrn), displayname(dspn) { } //non-default constructor w parameters

Profile::Profile() : username(""), displayname("") { } //default construct that initializes it // (username="", displayname="")
