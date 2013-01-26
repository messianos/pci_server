
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
	ErrorCode(short int code);
	virtual ~ErrorCode();
	bool isAnError();
	std::string getErrorDescription();
};

#endif /* ERRORCODE_H_ */
