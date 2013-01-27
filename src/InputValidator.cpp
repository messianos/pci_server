
// Includes
#include "InputValidator.h"

// Namespaces
using namespace ViewContent;
using namespace std;

bool InputValidator::validEmail(string email) {
	// TODO
	return true;
}

bool InputValidator::validUserName(string user_name) {
	// TODO
	return true;
}

ErrorCode *InputValidator::validateNewProblemInput(NewProblemFormInfo* form_info) {
	// TODO: chequea los campos
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateNewSolutionInput(NewSolutionFormInfo* form_info) {
	// TODO: chequea los campos
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateSignInInput(SignInFormInfo* form_info) {
	// TODO: chequea los campos
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateSignUpInput(SignUpFormInfo* form_info) {
	// TODO: chequea los campos
	return new ErrorCode(ErrorCode::CODE_NONE);
}
