
// Includes
#include "InputValidator.h"

// Namespaces
using namespace boost;
using namespace std;

bool InputValidator::isValidBoolean(string boolean) {
	return regex_match(boolean, regex("^true$|^false$"));
}

bool InputValidator::isValidBirthDate(string birth_date) {
	if (! regex_match(birth_date, regex("^[0-9]{2,2}/[0-9]{2,2}/[0-9]{4,4}$")))
		return false;

	Date *date = new Date("%d-%m-%Y", birth_date);
	int day = date->getDay();
	int month = date->getMonth();
	int year = date->getYear();

	// TODO: validate date
	return true;
}

bool InputValidator::isValidEmail(string email) {
	if (email.length() > 255)
		return false;

	return regex_match(email, regex("^[A-Z0-9._+-]+@[A-Z0-9.]+\\.[A-Z0-9]{2,}$", regex_constants::icase));
}

bool InputValidator::isValidFirstName(string first_name) {
	return first_name.length() > 0 && first_name.length() <= 31;
}

bool InputValidator::isValidGenre(string genre) {
	return regex_match(genre, regex("^[FM]$"));
}

bool InputValidator::isValidLastName(string last_name) {
	return last_name.length() > 0 && last_name.length() <= 31;
}

bool InputValidator::isValidLocation(string location) {
	return location.length() <= 15; // TODO: to define
}

bool InputValidator::isValidPassword(string password) {
	if (password.length() < 6)
		return false;

	return regex_match(password, regex("^[\x21-\x7E]*$"));
}

bool InputValidator::isValidUserName(string user_name) {
	if (user_name.length() < 4 || user_name.length() > 31)
		return false;

	return regex_match(user_name, regex("^[A-Z][A-Z0-9_]*$", regex_constants::icase));
}

bool InputValidator::isValidProblemId(string problem_id) {
	if (problem_id.length() != 34)
		return false;

	return regex_match(problem_id, regex("^50[A-F0-9]*$", regex_constants::icase));
}

bool InputValidator::isValidSolutionId(string solution_id) {
	if (solution_id.length() != 34)
		return false;

	return regex_match(solution_id, regex("^53[A-F0-9]*$", regex_constants::icase));
}

bool InputValidator::isValidClarificationId(string clarification_id) {
	if (clarification_id.length() != 34)
		return false;

	return regex_match(clarification_id, regex("^43[A-F0-9]*$", regex_constants::icase));
}

bool InputValidator::isValidPublicationContent(string content) {
	return content.length() > 0 && content.length() <= 4194304;
}

bool InputValidator::isValidPublicationDescription(string description) {
	return description.length() > 0 && description.length() <= 400;
}

bool InputValidator::isValidClarificationAssociatedPublicationId(string associated_publication_id) {
	if (associated_publication_id.length() != 34)
		return false;

	return regex_match(associated_publication_id, regex("^5[03][A-F0-9]*$", regex_constants::icase));
}

bool InputValidator::isValidClarificationContent(string content) {
	return content.length() > 0 && content.length() <= 2000;
}

ErrorCode *InputValidator::validateSignInInput(string user_name, string password) {
	if (! isValidUserName(user_name))
		return new ErrorCode(ErrorCode::CODE_INVALID_USER_NAME);

	if (! isValidPassword(password))
		return new ErrorCode(ErrorCode::CODE_INVALID_PASSWORD);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateCreateUserInput(string birth_date, string email, string first_name, string genre, string last_name, string location, string password, string user_name) {
	if (! isValidBirthDate(birth_date))
		return new ErrorCode(ErrorCode::CODE_INVALID_BIRTH_DATE);

	if (! isValidEmail(email))
		return new ErrorCode(ErrorCode::CODE_INVALID_EMAIL);

	if (! isValidFirstName(first_name))
		return new ErrorCode(ErrorCode::CODE_INVALID_FIRST_NAME);

	if (! isValidGenre(genre))
		return new ErrorCode(ErrorCode::CODE_INVALID_GENRE);

	if (! isValidLastName(last_name))
		return new ErrorCode(ErrorCode::CODE_INVALID_LAST_NAME);

	if (! isValidLocation(location))
		return new ErrorCode(ErrorCode::CODE_INVALID_LOCATION);

	if (! isValidPassword(password))
		return new ErrorCode(ErrorCode::CODE_INVALID_PASSWORD);

	if (! isValidUserName(user_name))
		return new ErrorCode(ErrorCode::CODE_INVALID_USER_NAME);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateCreateProblemInput(string content, string description, string is_anonymous) {
	if (! isValidPublicationContent(content))
		return new ErrorCode(ErrorCode::CODE_INVALID_PUBLICATION_CONTENT);

	if (! isValidPublicationDescription(description))
		return new ErrorCode(ErrorCode::CODE_INVALID_PUBLICATION_DESCRIPTION);

	if (! isValidBoolean(is_anonymous))
		return new ErrorCode(ErrorCode::CODE_INVALID_IS_ANONYMOUS);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

/*ErrorCode *InputValidator::validateDeleteProblemInput(string problem_id) {
	if (! isValidProblemId(problem_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_PROBLEM_ID);

	return new ErrorCode(ErrorCode::CODE_NONE);
}*/

ErrorCode *InputValidator::validateVoteProblemInput(string is_positive, string problem_id) {
	if (! isValidBoolean(is_positive))
		return new ErrorCode(ErrorCode::CODE_INVALID_IS_POSITIVE);

	if (! isValidProblemId(problem_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_PROBLEM_ID);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateSetAcceptedSolutionInput(string problem_id, string solution_id) {
	if (! isValidProblemId(problem_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_PROBLEM_ID);

	if (! isValidSolutionId(solution_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_SOLUTION_ID);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateUnsetAcceptedSolutionInput(string problem_id) {
	if (! isValidProblemId(problem_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_PROBLEM_ID);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateCreateSolutionInput(string content, string description, string is_anonymous, string problem_id) {
	if (! isValidPublicationContent(content))
		return new ErrorCode(ErrorCode::CODE_INVALID_PUBLICATION_CONTENT);

	if (! isValidPublicationDescription(description))
		return new ErrorCode(ErrorCode::CODE_INVALID_PUBLICATION_DESCRIPTION);

	if (! isValidBoolean(is_anonymous))
		return new ErrorCode(ErrorCode::CODE_INVALID_IS_ANONYMOUS);

	if (! isValidProblemId(problem_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_PROBLEM_ID);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

/*ErrorCode* InputValidator::validateDeleteSolutionInput(string solution_id) {
	if (! isValidSolutionId(solution_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_SOLUTION_ID);

	return new ErrorCode(ErrorCode::CODE_NONE);
}*/

ErrorCode *InputValidator::validateVoteSolutionInput(string is_positive, string solution_id) {
	if (! isValidBoolean(is_positive))
		return new ErrorCode(ErrorCode::CODE_INVALID_IS_POSITIVE);

	if (! isValidSolutionId(solution_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_SOLUTION_ID);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

ErrorCode *InputValidator::validateCreateClarificationInput(string associated_publication_id, string question) {
	if (! isValidClarificationAssociatedPublicationId(associated_publication_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_CLARIFICATION_ASSOCIATED_PUBLICATION_ID);

	if (! isValidClarificationContent(question))
		return new ErrorCode(ErrorCode::CODE_INVALID_CLARIFICATION_QUESTION);

	return new ErrorCode(ErrorCode::CODE_NONE);
}

/*ErrorCode *InputValidator::validateDeleteClarificationInput(string clarification_id) {
	if (! isValidClarificationId(clarification_id))
		return new ErrorCode(ErrorCode::CODE_INVALID_CLARIFICATION_ID);

	return new ErrorCode(ErrorCode::CODE_NONE);
}*/
