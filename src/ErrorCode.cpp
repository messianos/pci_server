
// Includes
#include "ErrorCode.h"

// Namespaces
using namespace std;

// Initializations
const string ErrorCode::ERROR_DESCRIPTIONS[] = {
	"CODE_NONE",
	"CODE_INVALID_BIRTH_DATE",
	"CODE_INVALID_EMAIL",
	"CODE_INVALID_FIRST_NAME",
	"CODE_INVALID_GENRE",
	"CODE_INVALID_IS_ANONYMOUS",
	"CODE_INVALID_LAST_NAME",
	"CODE_INVALID_LOCATION",
	"CODE_INVALID_PASSWORD",
	"CODE_INVALID_USER_NAMEeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaeee",
	"CODE_INVALID_PROBLEM_ID",
	"CODE_INVALID_SOLUTION_ID",
	"CODE_INVALID_CLARIFICATION_ID",
	"CODE_INVALID_PUBLICATION_CONTENT",
	"CODE_INVALID_PUBLICATION_DESCRIPTION",
	"CODE_INVALID_CLARIFICATION_ANSWER",
	"CODE_INVALID_CLARIFICATION_ASSOCIATED_PUBLICATION_ID",
	"CODE_INVALID_CLARIFICATION_QUESTION"
	// TODO: cambiar descripciones
};

const short int ErrorCode::CODE_NONE = 0;
const short int ErrorCode::CODE_INVALID_BIRTH_DATE = 1;
const short int ErrorCode::CODE_INVALID_EMAIL = 2;
const short int ErrorCode::CODE_INVALID_FIRST_NAME = 3;
const short int ErrorCode::CODE_INVALID_GENRE = 4;
const short int ErrorCode::CODE_INVALID_IS_ANONYMOUS = 5;
const short int ErrorCode::CODE_INVALID_LAST_NAME = 6;
const short int ErrorCode::CODE_INVALID_LOCATION = 7;
const short int ErrorCode::CODE_INVALID_PASSWORD = 8;
const short int ErrorCode::CODE_INVALID_USER_NAME = 9;
const short int ErrorCode::CODE_INVALID_PROBLEM_ID = 10;
const short int ErrorCode::CODE_INVALID_SOLUTION_ID = 11;
const short int ErrorCode::CODE_INVALID_CLARIFICATION_ID = 12;
const short int ErrorCode::CODE_INVALID_PUBLICATION_CONTENT = 13;
const short int ErrorCode::CODE_INVALID_PUBLICATION_DESCRIPTION = 14;
const short int ErrorCode::CODE_INVALID_CLARIFICATION_ANSWER = 15;
const short int ErrorCode::CODE_INVALID_CLARIFICATION_ASSOCIATED_PUBLICATION_ID = 16;
const short int ErrorCode::CODE_INVALID_CLARIFICATION_QUESTION = 17;

ErrorCode::ErrorCode(short int code) {
	this->code = code;
}

ErrorCode::~ErrorCode() {}

bool ErrorCode::isAnError() {
	return code != CODE_NONE;
}

string ErrorCode::getErrorDescription() {
	return ERROR_DESCRIPTIONS[code];
}
