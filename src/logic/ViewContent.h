
#ifndef VIEWCONTENT_H_
#define VIEWCONTENT_H_

// Includes
#include "../entity/Clarification.h"
#include "../entity/Problem.h"
#include "../entity/Solution.h"
#include "../entity/User.h"
#include <boost/algorithm/string.hpp>
#include <cppcms/view.h>
#include <list>
#include <string>

namespace ViewContent {

	std::string escapeConflictingChars(std::string text);

	struct SessionContent : public cppcms::base_content {
		bool signed_in;
		std::string user_name;
		bool anonymous_mode;
		std::string first_name;
		std::string last_name;
	};

	struct ErrorPageContent : SessionContent {
		int http_error_code;
		std::string server_error_code;
	};

	struct UserPageContent : SessionContent {
		User* user;
		int publication_count;
		int problem_count;
		int solution_count;
		int accepted_solution_count;
		std::list<Publication *> *recent_publications;
	};
	
	struct ProblemsPageContent : SessionContent {
		std::list<Problem *> *random_problems;
		std::list<Problem *> *latest_problems;
		std::list<Problem *> *unsolved_problems;

		// TODO: Not implemented!
		//std::list<Problem *> *nosolutions_problems;
		//std::list<Problem *> *most_voted_problems;
	};

	struct ProblemPageContent : SessionContent {
		Problem *problem;
		Solution *accepted_solution;
		std::list<Solution *> *solutions;
		std::list<Clarification *> *clarifications;
		int user_vote;
	};

	struct SolutionPageContent: SessionContent {
		Solution *solution;
		std::list<Clarification *> *clarifications;
	};

	struct NewSolutionPageContent : SessionContent {
		std::string problem_id;
	};
}

// Type definitions
typedef std::string String;
typedef Problem *ProblemPointer;
typedef Solution *SolutionPointer;

#endif /* VIEWCONTENT_H_ */
