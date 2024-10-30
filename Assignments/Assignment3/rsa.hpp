#ifndef RSA.HPP
#define RSA.HPP

#include <string>

class rsa{
    private:
        int private_key;
    public:
        int encrypt(const std::string cleartext);
        int decrypt();
        long long modularExponentiation(int base, int exponent, int mod);

        int get_private_key() {
            return private_key;
        }
        void set_private_key(int pk) {
            private_key = pk;
        }

        int totient;
        int coprime;
        int p;
        int q;
        int k;
        int n;
};

#endif // RSA.HPP