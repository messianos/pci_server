
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
	"CODE_INVALID_IS_POSITIVE",
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

short int code_index = 0;
const short int ErrorCode::CODE_NONE = code_index++;
const short int ErrorCode::CODE_INVALID_BIRTH_DATE = code_index++;
const short int ErrorCode::CODE_INVALID_EMAIL = code_index++;
const short int ErrorCode::CODE_INVALID_FIRST_NAME = code_index++;
const short int ErrorCode::CODE_INVALID_GENRE = code_index++;
const short int ErrorCode::CODE_INVALID_IS_ANONYMOUS = code_index++;
const short int ErrorCode::CODE_INVALID_IS_POSITIVE = code_index++;
const short int ErrorCode::CODE_INVALID_LAST_NAME = code_index++;
const short int ErrorCode::CODE_INVALID_LOCATION = code_index++;
const short int ErrorCode::CODE_INVALID_PASSWORD = code_index++;
const short int ErrorCode::CODE_INVALID_USER_NAME = code_index++;
const short int ErrorCode::CODE_INVALID_PROBLEM_ID = code_index++;
const short int ErrorCode::CODE_INVALID_SOLUTION_ID = code_index++;
const short int ErrorCode::CODE_INVALID_CLARIFICATION_ID = code_index++;
const short int ErrorCode::CODE_INVALID_PUBLICATION_CONTENT = code_index++;
const short int ErrorCode::CODE_INVALID_PUBLICATION_DESCRIPTION = code_index++;
const short int ErrorCode::CODE_INVALID_CLARIFICATION_ANSWER = code_index++;
const short int ErrorCode::CODE_INVALID_CLARIFICATION_ASSOCIATED_PUBLICATION_ID = code_index++;
const short int ErrorCode::CODE_INVALID_CLARIFICATION_QUESTION = code_index++;

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
