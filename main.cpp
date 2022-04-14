#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"


int main(){
    //task A
    std::cout << "===============Task A===============" << std::endl;
    Profile p1("marco", "Marco");
    std::cout << "Username-->Display Name(handle): " << std::endl;
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)
    std::cout << "\n------------------------------------" << std::endl;

    p1.setDisplayName("Marco Rossi"); 
    std::cout << "Username-->Updated Display Name(handle): " << std::endl;
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    std::cout << "\n------------------------------------" << std::endl;
    
    Profile p2("tarma1", "Tarma Roving"); 
    std::cout << "Username-->Display Name(handle): " << std::endl;  
    std::cout << p2.getUsername() << std::endl; // tarma1
    std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)


    //task B
    //new user added to the array --> true
    //new user not added to the array --> false
    std::cout << "\n===============Task B===============" << std::endl;
    Network nw;
    std::cout << "Username: mario\nDisplay Name: Mario\n" << "Is this user added? " << nw.addUser("mario", "Mario") << " == true" << std::endl;     // true (1)
    std::cout << "\n------------------------------------" << std::endl;
    std::cout << "Username: luigi\nDisplay Name: Luigi\n" << "Is this user added? " << nw.addUser("luigi", "Luigi") << " == true" << std::endl;     // true (1)
    std::cout << "\n------------------------------------" << std::endl;
    std::cout << "Username: mario\nDisplay Name: Mario2\n" << "Is this user added? " << nw.addUser("mario", "Mario2") << " == false" << std::endl;    // false (0)
    std::cout << "\n------------------------------------" << std::endl;
    std::cout << "Username: mario 2\nDisplay Name: Mario2\n" << "Is this user added? " << nw.addUser("mario 2", "Mario2") << " == false" << std::endl;  // false (0)
    std::cout << "\n------------------------------------" << std::endl;
    std::cout << "Username: mario-2\nDisplay Name: Mario2\n" << "Is this user added? " << nw.addUser("mario-2", "Mario2") << " == false" << std::endl;  // false (0)
    std::cout << "\n------------------------------------" << std::endl;

    std::cout << "Username: marioi (the last i representing a number [2,19] in the for loop)\nDisplay Name: Marioi (the last i representing a number [2,19] in the for loop)\n"; 
    for(int i = 2; i < 20; i++){
        std::cout << "Is this user added? " << nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) << " == true" << std::endl;   // true (1)
    }

    std::cout << "\n------------------------------------" << std::endl;
    std::cout << "Username: yoshi\nDisplay Name: Yoshi\n" << "Is this user added? " << nw.addUser("yoshi", "Yoshi") << " == false" << std::endl;     // false (0) b/c the array is full

    return 0;
}