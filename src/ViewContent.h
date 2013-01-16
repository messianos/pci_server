
#ifndef VIEWCONTENT_H_
#define VIEWCONTENT_H_

// Includes
#include "Clarification.h"
#include "Problem.h"
#include "Solution.h"
#include <cppcms/view.h>
#include <list>
#include <string>

namespace ViewContent {

	struct TemplateContent : public cppcms::base_content {
		std::string page_title;
	};

	struct WelcomeContent : TemplateContent {
	};

	struct SignInContent : TemplateContent {
	};

	struct ProblemsContent : TemplateContent {
		std::list<Problem *> *problems;
	};

	struct ProblemContent : TemplateContent {
		Problem *problem;
		Solution *accepted_solution;
		std::list<Solution *> *solutions;
		std::list<Clarification *> *clarifications;
	};

	struct SolutionContent : TemplateContent {
		Solution *solution;
		std::list<Clarification *> *clarifications;
	};

	struct IdeasContent : TemplateContent {
	};
}

#endif /* VIEWCONTENT_H_ */
