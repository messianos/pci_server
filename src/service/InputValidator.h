
#ifndef INPUTVALIDATOR_H_
#define INPUTVALIDATOR_H_

// Includes
#include "../auxiliar/Date.h"
#include <boost/tr1/regex.hpp>
#include <string>

class InputValidator {

private:

	static bool hasValidBoundaries(std::string string, int min, int max);
	static bool isValidBoolean(std::string boolean);
	static bool isValidDate(std::string date);
	static bool isValidEmail(std::string email);
	static bool isValidGenre(std::string genre);
	static bool isValidPassword(std::string password);
	static bool isValidUserName(std::string user_name);
	static bool isValidPublicationId(std::string publication_id);
	static bool isValidProblemId(std::string problem_id);
	static bool isValidSolutionId(std::string solution_id);
	static bool isValidClarificationId(std::string clarification_id);
	static bool isValidProposalId(std::string proposal_id);

public:
	static bool isValidSignInInput(std::string password, std::string user_name);
	static bool isValidUserExistsInput(std::string user_name);
	static bool isValidSignUpInput(std::string birth_date, std::string email, std::string first_name, std::string genre, std::string last_name, std::string location, std::string password, std::string user_name);
	static bool isValidPublicateProblemInput(std::string content, std::string description);
	static bool isValidEditProblemInput(std::string content, std::string description, std::string problem_id);
	static bool isValidMakeProblemCreatorVisibleInput(std::string problem_id);
	static bool isValidVoteProblemInput(std::string is_positive, std::string problem_id);
	static bool isValidSetAcceptedSolutionInput(std::string problem_id, std::string solution_id);
	static bool isValidUnsetAcceptedSolutionInput(std::string problem_id);
	static bool isValidPublicateSolutionInput(std::string content, std::string description, std::string problem_id);
	static bool isValidEditSolutionInput(std::string content, std::string description, std::string solution_id);
	static bool isValidMakeSolutionCreatorVisibleInput(std::string solution_id);
	static bool isValidVoteSolutionInput(std::string is_positive, std::string solution_id);
	static bool isValidAskClarificationInput(std::string publication_id, std::string question);
	static bool isValidAnswerClarificationInput(std::string answer, std::string clarification_id);
	static bool isValidPublicateProposalInput(std::string content, std::string solution_id);
	static bool isValidEditProposalInput(std::string content, std::string proposal_id);
	static bool isValidMakeProposalCreatorVisibleInput(std::string proposal_id);
	static bool isValidVoteProposalInput(std::string is_positive, std::string proposal_id);
};

#endif /* INPUTVALIDATOR_H_ */
