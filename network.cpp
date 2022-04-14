#include <iostream>
#include <string>
#include "network.h"
#include "profile.h"
#include <ctype.h>

//TASK B

//private class function
int Network::findID(std::string usrn){

    for (int i = 0; i < MAX_USERS; i++){
        std::string existingUser = profiles[i].getUsername();
        if (existingUser == usrn){
            return i;
        }
        
    }

    return -1; //user not found in the profiles array
}

Network::Network() : numUsers(0) { }

bool Network::addUser(std::string usrn, std::string dspn){
    //user can only be signed up if:
        // the new usrn is a non-empty alphanumeric string MEANING no empty strings allowed
        // there are no other users with the same username
        // the arr profiles is not full

    //username must be alphanumeric meaning only LETTERS and NUMBERS == counter must always be 0 to indicate that the usrn has only letters and numbers
    int alphaNumCounter = 0;
    for (int i = 0; i < usrn.length(); i++){
        if (!isdigit(usrn[i]) && (!isalpha(usrn[i]))){
            alphaNumCounter++;
        }
    }

    if (usrn == "" || alphaNumCounter != 0 || findID(usrn) != -1 || numUsers == 20){
        return false;
    }
    else {
        //new user should be added to the profiles arr
        
        Profile newProf(usrn, dspn);
        profiles[numUsers] = newProf; // 0 numUsers--> new user in 0th index, // 1 numUsers--> new user in 1th index because that one user is in 0th index etc..            
        numUsers++;
        
        return true;

    }
}