
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
	static const short int CODE_INVALID_BIRTH_DATE;
	static const short int CODE_INVALID_EMAIL;
	static const short int CODE_INVALID_FIRST_NAME;
	static const short int CODE_INVALID_GENRE;
	static const short int CODE_INVALID_IS_POSITIVE;
	static const short int CODE_INVALID_LAST_NAME;
	static const short int CODE_INVALID_LOCATION;
	static const short int CODE_INVALID_PASSWORD;
	static const short int CODE_INVALID_USER_NAME;
	static const short int CODE_INVALID_PROBLEM_ID;
	static const short int CODE_INVALID_SOLUTION_ID;
	static const short int CODE_INVALID_CLARIFICATION_ID;
	static const short int CODE_INVALID_PUBLICATION_CONTENT;
	static const short int CODE_INVALID_PUBLICATION_DESCRIPTION;
	static const short int CODE_INVALID_CLARIFICATION_ANSWER;
	static const short int CODE_INVALID_CLARIFICATION_ASSOCIATED_PUBLICATION_ID;
	static const short int CODE_INVALID_CLARIFICATION_QUESTION;

	ErrorCode(short int code);
	virtual ~ErrorCode();
	bool isAnError();
	std::string getErrorDescription();
};

#endif /* ERRORCODE_H_ */
