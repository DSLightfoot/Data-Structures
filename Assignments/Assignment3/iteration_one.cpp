#include <iostream>
#include <iomanip>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

using std::string, std::vector, std::cout, std::cin, std::endl, std::lcm, std::pow, std::stoi;

int encrypt(const string cleartext);
int decrypt(int pk, int n);
long long modularExponentiation(int b, int e, int m);

int main(){
    // Updates:
    // Ask user for string
    // Store in file 
    string cleartext;

    cout << "Enter Text to be Encrypted: ";
    getline(cin, cleartext);

    encrypt(cleartext);

    return 0;
}

int encrypt(const string cleartext){
    // Select 2 Primes (p, q)
    int p = 41;
    int q = 43;

    // Calculate n = (p * q)
    int n = p * q;

    cout << "N: " << n << endl;

    // Calculate totient (lcm(p-1, q-1))
    int totient = lcm(p-1, q-1);

    cout << "Totient: " << totient << endl;

    // Choose a coprime (e)
    int e = 29;

    // d = e + k(totient(n))
    int k = 1; // Arbitrary number, could be 1 - inf
    int private_key = e + (k * totient);
    
    cout << "Private Key: " << private_key << endl;

    ////////// File IO //////////

    // Name File
    string filename = "encrypted.txt";

    // Create and open file
    std::ofstream file;
    file.open(filename, std::ios::out);

    // Check if file is open
    if (!file){
        std::cerr << "Unable to open file." << endl;
        return 1;
    }



    // Convert each letter to integer and encrypt
    for (int i = 0; i < cleartext.length(); i++){
        int ascii_val = cleartext[i];

        cout << "Ascii Value: " << ascii_val << endl;

        int encrypted_val = modularExponentiation(ascii_val, e, n);

        file << encrypted_val << endl;

        cout << "Encypted Value: " << encrypted_val << endl;

        int decrypted_val = modularExponentiation(encrypted_val, private_key, n);

        cout << "Decrypted Value: " << decrypted_val << endl << endl;
    }

    file.close();

    decrypt(private_key, n);

    return 0;
}

int decrypt(int private_key, int n) {
    // Open file
    std::ifstream infile;
    infile.open("encrypted.txt", std::ios::in);

    // Check if file is open
    if (!infile){
        std::cerr << "Unable to open file." << endl;
        return 1;
    }

    vector<int> encrypted_text;
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
        std::cerr << "File is not open" << endl;
        return 1;
    }

    for (int i = 0; i < encrypted_text.size(); i++){
        int decrypted_val = modularExponentiation(encrypted_text[i], private_key, n);
        char ascii = decrypted_val;
        outfile << ascii;
    }

    outfile.close();

    return 0;

}

long long modularExponentiation(int base, int exponent, int mod) {
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