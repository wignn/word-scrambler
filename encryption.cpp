#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "encryption.h"

using namespace std;


string encrypt(const string& input) {
    string encrypted = "";
    srand(static_cast<unsigned int>(time(0))); 
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charactersLength = characters.length();
    int minLength = 8;
    int length = max(static_cast<int>(input.length()), minLength);
    
    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % charactersLength;
        encrypted += characters[randomIndex];
    }
    
    return encrypted;
}
