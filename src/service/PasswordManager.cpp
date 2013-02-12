
// Includes
#include "PasswordManager.h"

// Namespaces
using namespace std;

// Initializations
const string PasswordManager::HASH_FUNCTION = "sha512";

string PasswordManager::encryptPassword(string unencrypted_password) {

	unsigned char message_digest[EVP_MAX_MD_SIZE];
	unsigned int length;

	// Encrypts the password
	OpenSSL_add_all_digests();
	const EVP_MD *configuration = EVP_get_digestbyname(HASH_FUNCTION.data());
	EVP_MD_CTX *context = EVP_MD_CTX_create();
	EVP_DigestInit_ex(context, configuration, NULL);
	EVP_DigestUpdate(context, unencrypted_password.data(), unencrypted_password.size());
	EVP_DigestFinal_ex(context, message_digest, &length);
	EVP_MD_CTX_destroy(context);

	// Creates a string representing an hexadecimal number from the encrypted password
	stringstream stream;
	stream << hex << setfill('0');
	for (unsigned int i = 0; i < length; i++)
		stream << setw(2) << static_cast<unsigned int>(message_digest[i]);

	return stream.str();
}
