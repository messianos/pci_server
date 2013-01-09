
#ifndef PASSWORDMANAGER_H_
#define PASSWORDMANAGER_H_

// Includes
#include <openssl/evp.h>
#include <iomanip>
#include <sstream>
#include <string>

class PasswordManager {

private:
	static const std::string HASH_FUNCTION;

public:
	static std::string encryptPassword(std::string unencrypted_password);
};

#endif /* PASSWORDMANAGER_H_ */
