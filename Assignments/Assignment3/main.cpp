#include "rsa.hpp"
#include "rsa.cpp"

int main() {
    std::string cleartext = "";

    std::cout << "Enter any Text to be Encrypted: ";
    getline(std::cin, cleartext);

    rsa object;

    // Select 2 Primes (p, q)
    object.p = 61;
    object.q = 53;

    // Calculate n = (p * q)
    object.n = object.p * object.q;

    std::cout << std::endl << "N: " << object.n << std::endl;

    // Calculate totient (lcm(p-1, q-1))
    object.totient = std::lcm(object.p-1, object.q-1);

    std::cout << "Totient: " << object.totient << std::endl;

    // Choose a coprime (e)
    object.coprime = 17;

    // d = e + k(totient(n))
    object.k = 1; // Arbitrary number, could be 1 - inf

    for (int d = 1; d <= 1000; ++d){
        if ((d * object.coprime) % object.totient == 1) {
            object.set_private_key(d);
            break;
        }
    }
    
    std::cout << "Private Key: " << object.get_private_key() << std::endl << std::endl;

    object.encrypt(cleartext);
    object.decrypt();

    return 0;
}