#include <iostream>
#include <string>
#include "profile.h"


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

    return 0;
}