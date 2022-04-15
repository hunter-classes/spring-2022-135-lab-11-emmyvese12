#pragma once
#include "profile.h"
#include <string>

class Network {
    private:
        static const int MAX_USERS = 20; // max number of user profiles
        int numUsers;                    // number of registered users
        Profile profiles[MAX_USERS];     // user profiles array:
                                        // mapping integer ID -> Profile

        
        int findID (std::string usrn);

        bool following[MAX_USERS][MAX_USERS];  // friendship matrix:

    public:
        // Constructor, makes an empty network (numUsers = 0)
        Network();

    
        bool addUser(std::string usrn, std::string dspn);
        
        bool follow(std::string usrn1, std::string usrn2);

        void printDot();
};
