#include "rsa.hpp"

#include <vector>
#include <fstream>
#include <iostream>
#include <numeric>

long long rsa::modularExponentiation(int base, int exponent, int mod){
    long long result = 1;
    base = base % mod;  // Update base if it's more than or equal to mod

    while (exponent > 0) {
        // If exponent is odd, multiply base with result
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        // exponent must be even now
        exponent = exponent / 2;  // Divide the exponent by 2
        base = (base * base) % mod;  // Square the base
    }
    return result;
}

int rsa::encrypt(const std::string cleartext){
    ////////// File IO //////////
    // Create and open file
    std::ofstream file;
    file.open("encrypted.txt", std::ios::out);

    // Check if file is open
    if (!file){
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }


    // Convert each letter to integer and encrypt
    for (int i = 0; i < cleartext.length(); i++){
        int ascii_val = cleartext[i];
        int encrypted_val = modularExponentiation(ascii_val, coprime, n);

        file << encrypted_val << std::endl;
    }

    file.close();

    return 0;
}

int rsa::decrypt(){
    // Open file
    std::ifstream infile;
    infile.open("encrypted.txt", std::ios::in);

    // Check if file is open
    if (!infile){
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    std::vector<int> encrypted_text;
    int text;

    while (infile >> text){
        encrypted_text.push_back(text);
    }

    infile.close();

    // Create/Open "decrypted.txt"
    std::ofstream outfile;
    outfile.open("decrypted.txt", std::ios::out);

    // Make sure file is open
    if (!outfile){
        std::cerr << "File is not open" << std::endl;
        return 1;
    }

    std::cout << "Decrypted Text: ";

    for (int i = 0; i < encrypted_text.size(); i++){
        int decrypted_val = modularExponentiation(encrypted_text[i], get_private_key(), n);

        char ascii = decrypted_val;
        outfile << ascii;
        
        // Alphabetical Value
        std::cout << ascii;
    }

    outfile.close();

    return 0;
}