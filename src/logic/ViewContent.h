
#ifndef VIEWCONTENT_H_
#define VIEWCONTENT_H_

// Includes
#include "../entity/Clarification.h"
#include "../entity/Problem.h"
#include "../entity/Solution.h"
#include "../entity/User.h"
#include <cppcms/base_content.h>
#include <list>
#include <string>

namespace ViewContent {

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

	struct UserContent : SessionContent {
		User* user;
		int publication_count;
		int problem_count;
		int solution_count;
		int accepted_solution_count;
		std::list<Publication *> *recent_publications;
	};
	
	struct ProblemsContent : SessionContent {
		std::list<Problem *> *random_problems;
		std::list<Problem *> *latest_problems;
		std::list<Problem *> *unsolved_problems;

		// TODO: Not implemented!
		/*std::list<Problem *> *nosolutions_problems;
		std::list<Problem *> *most_voted_problems;*/
	};

	struct ProblemContent : SessionContent {
		Problem *problem;
		Solution *accepted_solution;
		std::list<Solution *> *solutions;
		std::list<Clarification *> *clarifications;
		int user_vote;
	};

	struct SolutionContent: SessionContent {
		Solution *solution;
		std::list<Clarification *> *clarifications;
	};

	struct NewSolutionContent : SessionContent {
		std::string problem_id;
	};
}

#endif /* VIEWCONTENT_H_ */
