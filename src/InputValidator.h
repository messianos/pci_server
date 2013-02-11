
#ifndef INPUTVALIDATOR_H_
#define INPUTVALIDATOR_H_

// Includes
#include "Date.h"
#include "ErrorCode.h"
#include <boost/tr1/regex.hpp>
#include <string>

class InputValidator {

private:
	static bool isValidBirthDate(std::string birth_date);
	static bool isValidEmail(std::string email);
	static bool isValidFirstName(std::string first_name);
	static bool isValidGenre(std::string genre);
	static bool isValidIsAnonymous(std::string is_anonymous);
	static bool isValidLastName(std::string last_name);
	static bool isValidLocation(std::string location);
	static bool isValidPassword(std::string password);
	static bool isValidUserName(std::string user_name);
	static bool isValidProblemId(std::string problem_id);
	static bool isValidSolutionId(std::string solution_id);
	static bool isValidClarificationId(std::string clarification_id);
	static bool isValidPublicationContent(std::string content);
	static bool isValidPublicationDescription(std::string description);
	static bool isValidClarificationAssociatedPublicationId(std::string associated_publication_id);
	static bool isValidClarificationContent(std::string content);

public:
	static ErrorCode *validateSignInInput(std::string user_name, std::string password);
	static ErrorCode *validateCreateUserInput(std::string birth_date, std::string email, std::string first_name, std::string genre, std::string last_name, std::string location, std::string password, std::string user_name);
	static ErrorCode *validateCreateProblemInput(std::string content, std::string description, std::string is_anonymous);
	static ErrorCode *validateDeleteProblemInput(std::string problem_id);
	static ErrorCode* validateCreateSolutionInput(std::string content, std::string description, std::string is_anonymous, std::string problem_id);
	static ErrorCode* validateDeleteSolutionInput(std::string solution_id);
	static ErrorCode *validateCreateClarificationInput(std::string associated_publication_id, std::string question);
	static ErrorCode *validateDeleteClarificationInput(std::string clarification_id);
};

#endif /* INPUTVALIDATOR_H_ */
