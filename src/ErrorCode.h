
#ifndef ERRORCODE_H_
#define ERRORCODE_H_

// Includes
#include <string>

class ErrorCode {

private:
	static const std::string ERROR_DESCRIPTIONS[];
	short int code;

public:
	static const short int CODE_NONE;
	static const short int CODE_INVALID_SIGN_IN;
	static const short int CODE_SHORT_DESCRIPTION;
	static const short int CODE_SHORT_CONTENT;
	static const short int CODE_VOID_USERNAME_FIELD;
	static const short int CODE_VOID_PASSWORD_FIELD;
	static const short int CODE_SHORT_USERNAME;
	static const short int CODE_SHORT_PASSWORD;
	static const short int CODE_SHORT_LASTNAME;
	static const short int CODE_EMAIL_INVALID;
	static const short int CODE_INVALID_PASSWORD_VERIFICATION;
	static const short int CODE_INVALID_USERNAME;
	static const short int CODE_INVALID_PASSWORD;
	ErrorCode(short int code);
	virtual ~ErrorCode();
	bool isAnError();
	std::string getErrorDescription();
};

#endif /* ERRORCODE_H_ */
