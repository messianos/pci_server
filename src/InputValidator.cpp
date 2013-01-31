// Includes
#include "InputValidator.h"
#include "ErrorCode.h"

// Namespaces
using namespace ViewContent;
using namespace std;

bool validChars(char c){
	if ((c>='a' && c<='z') || (c>='A' && c<='Z') || c == '_')
		return true;
	return false;
}

bool isCharacter(const char Character) {
	return ((Character >= 'a' && Character <= 'z')
			|| (Character >= 'A' && Character <= 'Z'));
}
bool isNumber(const char Character) {
	return (Character >= '0' && Character <= '9');
}

bool InputValidator::validUserName(string username){
	int i;
	for (i= 0; i< username.size();i++){
		if (!validChars(username.at(i)))
			return false;
	}
	return true;
}

bool InputValidator::validEmail(string email) {
	int i;
	bool arroba, cont;
	cont = false;
	arroba = false;
	for (i = 0; i < email.size(); i++) {
		if (email.at(i) == '@' && !arroba) {
			arroba = true;
			cont = true;
			if (!isCharacter(email.at(i + 1)) && !isNumber(email.at(i + 1))) {
				return false;
			}
		}
		if (cont && arroba && email.at(i) == '.') {
			if (!isCharacter(email.at(i + 1)) && !isNumber(email.at(i + 1)))
				return false;
			else
				return true;
		}
	}
	return false;
}

ErrorCode *InputValidator::validateNewProblemInput(
		NewProblemFormInfo* form_info) {
	if (form_info->description.value().size() < 2)
		return new ErrorCode(ErrorCode::CODE_SHORT_DESCRIPTION);
	//TODO consideration of short content
	if (form_info->content.value().size() < 10)
		return new ErrorCode(ErrorCode::CODE_SHORT_CONTENT);
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateNewSolutionInput(
		NewSolutionFormInfo* form_info) {
	if (form_info->description.value().size() < 2)
		return new ErrorCode(ErrorCode::CODE_SHORT_DESCRIPTION);
	//TODO consideration of short content
	if (form_info->content.value().size() < 10)
		return new ErrorCode(ErrorCode::CODE_SHORT_CONTENT);
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateSignInInput(SignInFormInfo* form_info) {
	// TODO: same username, check with the db
	if (form_info->user_name.value().size() < 1)
		return new ErrorCode(ErrorCode::CODE_VOID_USERNAME_FIELD);
	if (form_info->password.value().size() < 1)
		return new ErrorCode(ErrorCode::CODE_VOID_PASSWORD_FIELD);
	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateSignUpInput(SignUpFormInfo* form_info) {
	if (form_info->user_name.value().size() < 4)
		return new ErrorCode(ErrorCode::CODE_SHORT_USERNAME);

	if (!validUserName(form_info->user_name.value()))
		return new ErrorCode(ErrorCode::CODE_INVALID_USERNAME);

	if (form_info->password.value().size() < 6)
		return new ErrorCode(ErrorCode::CODE_SHORT_PASSWORD);

	if (!validUserName(form_info->password.value()))
			return new ErrorCode(ErrorCode::CODE_INVALID_PASSWORD);

	if (form_info->last_name.value().size() < 4)
		return new ErrorCode(ErrorCode::CODE_SHORT_LASTNAME);

	if (!validEmail(form_info->email.value()))
		return new ErrorCode(ErrorCode::CODE_EMAIL_INVALID);

	if (strcmp(form_info->password.value().c_str(),
			form_info->password_verification.value().c_str()) != 0)
		return new ErrorCode(ErrorCode::CODE_INVALID_PASSWORD_VERIFICATION);

	return new ErrorCode(ErrorCode::CODE_NONE);
}


