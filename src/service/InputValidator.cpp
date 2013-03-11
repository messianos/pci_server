
// Includes
#include "InputValidator.h"

// Namespaces
using namespace boost;
using namespace std;

bool InputValidator::hasValidBoundaries(string string, int min, int max) {
	if (max < 0)
		return string.length() >= min;
	
	return string.length() >= min && string.length() <= max;
}

bool InputValidator::isValidBoolean(string boolean) {
	return regex_match(boolean, regex("^true$|^false$"));
}

bool InputValidator::isValidDate(string date) {
	if (! regex_match(date, regex("^[0-9]{2,2}/[0-9]{2,2}/[0-9]{4,4}$")))
		return false;

	Date *date_object = new Date("%d/%m/%Y", date);
	int day = date_object->getDay();
	int month = date_object->getMonth();
	int year = date_object->getYear();

	if (day < 1 || day > 31)
		return false;

	if (month < 1 || month > 12)
		return false;

	switch (month) {
		case 2 : {
			if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) {
				if (day > 29) return false;
			} else {
				if (day > 28) return false;
			}

			break;
		}
		case 4 :
		case 6 :
		case 9 :
		case 11 : if (day == 31) return false;
	}

	return true;
}

bool InputValidator::isValidEmail(string email) {
	if (email.length() > 255)
		return false;

	return regex_match(email, regex("^[A-Z0-9._+-]+@[A-Z0-9.]+\\.[A-Z0-9]{2,}$", regex_constants::icase));
}

bool InputValidator::isValidGenre(string genre) {
	return regex_match(genre, regex("^[FM]$"));
}

bool InputValidator::isValidPassword(string password) {
	return regex_match(password, regex("^[\x21-\x7E]{6,}$"));
}

bool InputValidator::isValidUserName(string user_name) {
	return regex_match(user_name, regex("^[A-Z][A-Z0-9_]{3,30}$", regex_constants::icase));
}

bool InputValidator::isValidPublicationId(string publication_id) {
	return regex_match(publication_id, regex("^5[03][A-F0-9]{32,32}$", regex_constants::icase));
}

bool InputValidator::isValidProblemId(string problem_id) {
	return regex_match(problem_id, regex("^50[A-F0-9]{32,32}$", regex_constants::icase));
}

bool InputValidator::isValidSolutionId(string solution_id) {
	return regex_match(solution_id, regex("^53[A-F0-9]{32,32}$", regex_constants::icase));
}

bool InputValidator::isValidClarificationId(string clarification_id) {
	return regex_match(clarification_id, regex("^43[A-F0-9]{32,32}$", regex_constants::icase));
}

bool InputValidator::isValidProposalId(string proposal_id) {
	return regex_match(proposal_id, regex("^52[A-F0-9]{32,32}$", regex_constants::icase));
}

bool InputValidator::isValidSignInInput(string password, string user_name) {
	if (! hasValidBoundaries(password, 1, -1))
		return false;
	
	if (! hasValidBoundaries(user_name, 1, -1))
		return false;

	return true;
}

bool InputValidator::isValidUserExistsInput(string user_name) {
	if (! hasValidBoundaries(user_name, 1, -1))
		return false;
	
	return true;
}

bool InputValidator::isValidSignUpInput(string birth_date, string email, string first_name, string genre, string last_name, string location, string password, string user_name) {
	if (! isValidDate(birth_date))
		return false;
	
	if (! isValidEmail(email))
		return false;
	
	if (! hasValidBoundaries(first_name, 1, 31))
		return false;
	
	if (! isValidGenre(genre))
		return false;
	
	if (! hasValidBoundaries(last_name, 1, 31))
		return false;
	
	if (! hasValidBoundaries(location, 0, 15)) // TODO: to define
		return false;
	
	if (! isValidPassword(password))
		return false;
	
	if (! isValidUserName(user_name))
		return false;
	
	return true;
}

bool InputValidator::isValidPublicateProblemInput(string content, string description) {
	if (! hasValidBoundaries(content, 1, 4194304))
		return false;
	
	if (! hasValidBoundaries(description, 1, 400))
		return false;
	
	return true;
}

bool InputValidator::isValidEditProblemInput(string content, string description, string problem_id) {
	if (! hasValidBoundaries(content, 1, 4194304))
		return false;
	
	if (! hasValidBoundaries(description, 1, 400))
		return false;
	
	if (! isValidProblemId(problem_id))
		return false;
	
	return true;
}

bool InputValidator::isValidMakeProblemCreatorVisibleInput(string problem_id) {
	if (! isValidProblemId(problem_id))
		return false;
	
	return true;
}

bool InputValidator::isValidVoteProblemInput(string is_positive, string problem_id) {
	if (! isValidBoolean(is_positive))
		return false;
	
	if (! isValidProblemId(problem_id))
		return false;
	
	return true;
}

bool InputValidator::isValidSetAcceptedSolutionInput(string problem_id, string solution_id) {
	if (! isValidProblemId(problem_id))
		return false;
		
	if (! isValidSolutionId(solution_id))
		return false;
	
	return true;
}

bool InputValidator::isValidUnsetAcceptedSolutionInput(string problem_id) {
	if (! isValidProblemId(problem_id))
		return false;
	
	return true;
}

bool InputValidator::isValidPublicateSolutionInput(string content, string description, string problem_id) {
	if (! hasValidBoundaries(content, 1, 4194304))
		return false;
	
	if (! hasValidBoundaries(description, 1, 400))
		return false;
	
	if (! isValidProblemId(problem_id))
		return false;
	
	return true;
}

bool InputValidator::isValidEditSolutionInput(string content, string description, string solution_id) {
	if (! hasValidBoundaries(content, 1, 4194304))
		return false;
	
	if (! hasValidBoundaries(description, 1, 400))
		return false;
	
	if (! isValidSolutionId(solution_id))
		return false;
	
	return true;
}

bool InputValidator::isValidMakeSolutionCreatorVisibleInput(string solution_id) {
	if (! isValidSolutionId(solution_id))
		return false;
	
	return true;
}

bool InputValidator::isValidVoteSolutionInput(string is_positive, string solution_id) {
	if (! isValidBoolean(is_positive))
		return false;
	
	if (! isValidSolutionId(solution_id))
		return false;
	
	return true;
}

bool InputValidator::isValidAskClarificationInput(string publication_id, string question) {
	if (! hasValidBoundaries(question, 1, 2000))
		return false;
	
	if (! isValidPublicationId(publication_id))
		return false;
	
	return true;
}

bool InputValidator::isValidAnswerClarificationInput(string answer, string clarification_id) {
	if (! hasValidBoundaries(answer, 1, 2000))
		return false;
	
	if (! isValidClarificationId(clarification_id))
		return false;
	
	return true;
}

bool InputValidator::isValidPublicateProposalInput(string content, string solution_id) {
	if (! hasValidBoundaries(content, 1, 4194304))
		return false;
	
	if (! isValidSolutionId(solution_id))
		return false;
		
	return true;
}

bool InputValidator::isValidEditProposalInput(string content, string proposal_id) {
	if (! hasValidBoundaries(content, 1, 4194304))
		return false;
	
	if (! isValidProposalId(proposal_id))
		return false;
	
	return true;
}

bool InputValidator::isValidMakeProposalCreatorVisibleInput(string proposal_id) {
	if (! isValidProposalId(proposal_id))
		return false;
	
	return true;
}

bool InputValidator::isValidVoteProposalInput(string is_positive, string proposal_id) {
	if (! isValidBoolean(is_positive))
		return false;
	
	if (! isValidProposalId(proposal_id))
		return false;
	
	return true;
}
