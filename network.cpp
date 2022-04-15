#include <iostream>
#include <string>
#include "network.h"
#include "profile.h"
#include <ctype.h>

//TASK B

//private class function

// Returns user ID (index in the 'profiles' array) by their username
int Network::findID(std::string usrn){

    for (int i = 0; i < MAX_USERS; i++){
        std::string existingUser = profiles[i].getUsername();
        if (existingUser == usrn){
            return i;
        }
        
    }

    return -1; //user not found in the profiles array
}

//Network::Network() : numUsers(0) { }
Network::Network(){
    numUsers = 0;
    //set all elements of the matrix following to be false --> empty network so no one is following anyone
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
    
}



// Attempts to sign up a new user with specified username and displayname
// return true if the operation was successful, otherwise return false

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

// Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
// return true if success (if both usernames exist), otherwise return false
bool Network::follow(std::string usrn1, std::string usrn2){
    if (findID(usrn1) != -1 && findID(usrn2) != -1){
        //that means both users are found in the network, continue w/ next steps
        int user1ID = findID(usrn1);
        int user2ID = findID(usrn2);

        following[user1ID][user2ID] = true;
        //user1 is following user2

        return true;
    }

    return false;
    
}

// Print Dot file (graphical representation of the network)
void Network::printDot(){
    std::cout << "digraph {" << std::endl;
    for (int i = 0; i < numUsers; i++){
        std::cout << '"' << "@" << profiles[i].getUsername() << '"' << std::endl;
    }
    std::cout << "\n";

   
    for (int i = 0; i < numUsers; i++){
        for (int j = 0; j < numUsers; j++){
            if (following[i][j] == true){
                std::string usr1 = profiles[i].getUsername();
                std::string usr2 = profiles[j].getUsername();
                std::cout << '"' << "@" << usr1 << '"' << " -> " << '"' << "@" << usr2 << '"' << std::endl;

            }
        }
    }
    std::cout << "}" << std::endl;


}