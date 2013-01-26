
#ifndef INPUTVALIDATOR_H_
#define INPUTVALIDATOR_H_

// Includes
#include "ErrorCode.h"
#include "ViewContent.h"
#include <string>

class InputValidator {

private:
	static bool validEmail(std::string email);
	static bool validUserName(std::string user_name);

public:
	static ErrorCode *validateSignInInput(ViewContent::SignInFormInfo* form_info);
	static ErrorCode *validateSignUpInput(ViewContent::SignUpFormInfo* form_info);
	static ErrorCode *validateNewProblemInput(ViewContent::NewProblemFormInfo* form_info);
};

#endif /* INPUTVALIDATOR_H_ */
