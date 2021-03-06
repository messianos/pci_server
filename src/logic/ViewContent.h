
#ifndef VIEWCONTENT_H_
#define VIEWCONTENT_H_

// Includes
#include "../auxiliar/ErrorCode.h"
#include "../entity/Clarification.h"
#include "../entity/Problem.h"
#include "../entity/Solution.h"
#include "../entity/User.h"
#include <cppcms/form.h>
#include <cppcms/view.h>
#include <list>
#include <sstream>
#include <string>

namespace ViewContent {

	struct TemplateContent: public cppcms::base_content {
		std::string page_title;
		bool user_signed_in;
		bool anonymous_mode;
		std::string user_name;
		std::string user_first_name;
		std::string user_last_name;

		TemplateContent();
	};

	struct ProblemContent : TemplateContent {
		Problem *problem;
		Solution *accepted_solution;
		std::list<Solution *> *solutions;
		std::list<Clarification *> *clarifications;

		int user_vote;
	};

	struct ProblemsContent : TemplateContent {
		std::list<Problem *> *random_problems;
		std::list<Problem *> *unsolved_problems;
		std::list<Problem *> *latest_problems;

		// TODO: Not implemented!
		std::list<Problem *> *nosolutions_problems;
		std::list<Problem *> *most_voted_problems;
	};

	struct SolutionContent: TemplateContent {
		Solution *solution;
		std::list<Clarification *> *clarifications;
	};

	struct NewSolutionContent : TemplateContent {
		std::string problem_id;
	};

	struct UserContent : TemplateContent {
		User* user;
		int number_of_solutions;
		int number_of_problems;
		int number_of_publications;
		int number_of_accepted_solutions;
		std::list<Publication*>* recent_activity;
	};
}

// Type definitions
typedef std::string String;
typedef Publication *PublicationPointer;
typedef Problem *ProblemPointer;
typedef Solution *SolutionPointer;
typedef Clarification *ClarificationPointer;
typedef std::list<Problem *> *ProblemList;
typedef std::list<Solution *> *SolutionList;
typedef std::list<Clarification *> *ClarificationList;

#endif /* VIEWCONTENT_H_ */
