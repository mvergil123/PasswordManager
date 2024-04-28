 
#include "PasswordManager.h"
#include <vector>
#include <string>
#include <iostream>

#include <iostream>
#include <string>
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"

using namespace std;

PasswordManager :: PasswordManager(const string& PASSWORD , const string& SECURITY_ANSWER){ // default constructor
    PasswordtoEncrypt = PASSWORD; // set the password
    securityAnswer = SECURITY_ANSWER; // set the security answer
    securityVerificiation = false;
}

void PasswordManager :: encrypt(){ // encrypts the password
    // encrypt password
    // append it to the encrypted passwords vector
    // encryptedPasswords.push_back(PasswordtoEncrypt);
    using namespace CryptoPP;

    AutoSeededRandomPool prng;

    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    prng.GenerateBlock(key, key.size());

    CryptoPP::byte iv[AES::BLOCKSIZE];

    prng.GenerateBlock(iv, sizeof(iv));

    std::string plaintext = "Hello, World!";
    std::string ciphertext;
    std::string decryptedtext;

    // Encrypt
    try {
        CBC_Mode<AES>::Encryption encryptor(key, key.size(), iv);
        StringSource(plaintext, true,
                     new StreamTransformationFilter(encryptor,
                                                    new StringSink(ciphertext)
                     ) // StreamTransformationFilter
        ); // StringSource
    }
    catch (const CryptoPP::Exception& e) {
        std::cerr << "Encryption Error: " << e.what() << std::endl;
    }
    
}

void PasswordManager :: decrypt(const int& PASSWORDIDX) { // decrypts the requested password
    std::cout << PASSWORDIDX << std::endl;
    // decrypts the password based on the index
    // decrypt the thing below this statement
        //encryptedPasswords[PASSWORDIDX];
    // set the decrypted password to the new decrypted password
        //decryptedPassword = 

    
}

bool PasswordManager :: securityValidation(const string answer, const int questionIDX, const vector<string> secQuestions){ // takes in the question
    std::cout << questionIDX << std::endl;
    for (auto it : secQuestions) {
        std::cout << it.c_str() << std::endl;
    }
    
    std::cout << answer << std::endl;
    // questionIDX will store the index of the question
    // secQuestions is a vector which stores all the questions
    return false;
}

string PasswordManager :: getPassword(){
    return decryptedPassword; // returns the decrypted password
}

bool PasswordManager :: passwordApproved(string){
    for (size_t i = 0; i < encryptedPasswords.size(); i++) {
        if (PasswordtoEncrypt == encryptedPasswords[i]){ // check if the password is the same as an existing one
            return false;
        }
        return true;
    }
    return false;
}

