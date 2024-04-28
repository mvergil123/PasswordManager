
#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <vector>
#include <string>

class PasswordManager {
    public:
    PasswordManager(const std::string&, const std::string&); // default constructor
    void encrypt(); // encrypts the password
    void decrypt(const int& ); // decrypts the password and stores it in the variable
    bool securityValidation(const std::string, const int, const std::vector<std::string>); // asks the security question and compares the answers to the security question
    std::string getPassword(); // returns the decryptedPassword variable
    bool passwordApproved(std::string); // checks the similarity between the passwords

    private:
    std::string decryptedPassword; // stores the decrypted password
    std::vector<std::string> encryptedPasswords; // // vector string that will store the encrypted passwords
    bool securityVerificiation; // boolean value that stores whether the user is verified
    std:: string PasswordtoEncrypt; // stores the password that is needed to be encrypted
    std:: string securityAnswer; // stores the security question answer


};

#endif
