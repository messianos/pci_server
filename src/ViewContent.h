
#ifndef VIEWCONTENT_H_
#define VIEWCONTENT_H_

// Includes
#include "Clarification.h"
#include "ErrorCode.h"
#include "Problem.h"
#include "Solution.h"
#include "User.h"
#include <cppcms/form.h>
#include <cppcms/view.h>
#include <list>
#include <sstream>
#include <string>

namespace ViewContent {

	struct NewProblemFormInfo : public cppcms::form {
		cppcms::widgets::hidden form_name;
		cppcms::widgets::textarea description;
		cppcms::widgets::textarea content;
		cppcms::widgets::checkbox is_anonymous;
		cppcms::widgets::submit submit;

		NewProblemFormInfo();
	};

	struct NewSolutionFormInfo : public cppcms::form {
		cppcms::widgets::hidden form_name;
		cppcms::widgets::textarea description;
		cppcms::widgets::textarea content;
		cppcms::widgets::checkbox is_anonymous;
		cppcms::widgets::submit submit;

		NewSolutionFormInfo();
	};

	struct SignInFormInfo : public cppcms::form {
		cppcms::widgets::hidden form_name;
		cppcms::widgets::text user_name;
		cppcms::widgets::password password;
		cppcms::widgets::submit submit;

		SignInFormInfo();
	};

	struct SignUpFormInfo : public cppcms::form {
		cppcms::widgets::hidden form_name;
		cppcms::widgets::text first_name;
		cppcms::widgets::text last_name;
		cppcms::widgets::text user_name;
		cppcms::widgets::text email;
		cppcms::widgets::password password;
		cppcms::widgets::password password_verification;
		cppcms::widgets::text birth_date;
		cppcms::widgets::select genre;
		cppcms::widgets::submit submit;

		SignUpFormInfo();
	};

	struct TemplateContent: public cppcms::base_content {
		std::string page_title;
		bool user_signed_in;
		std::string user_name;
		std::string user_first_name;
		std::string user_last_name;
		ErrorCode* error_code;
		SignInFormInfo sign_in_form_info;

		TemplateContent();
	};

	struct IdeasContent : TemplateContent {
	};

	struct IndexContent : TemplateContent {
		SignUpFormInfo sign_up_form_info;
	};

	struct ProblemContent : TemplateContent {
		Problem *problem;
		Solution *accepted_solution;
		std::list<Solution *> *solutions;
		std::list<Clarification *> *clarifications;
	};

	struct NewProblemContent : TemplateContent {
		NewProblemFormInfo new_problem_form_info;
	};

	struct ProblemsContent : TemplateContent {
		std::list<Problem *> *problems;
	};

	struct SolutionContent: TemplateContent {
		Solution *solution;
		std::list<Clarification *> *clarifications;
		std::string problem_id;
	};

	struct NewSolutionContent : TemplateContent {
		NewSolutionFormInfo new_solution_form_info;
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
typedef std::list<Problem *> *ProblemList;
typedef std::list<Solution *> *SolutionList;
typedef std::list<Clarification *> *ClarificationList;
typedef ViewContent::NewProblemFormInfo *NewProblemFormInfoPointer;
typedef ViewContent::NewSolutionFormInfo *NewSolutionFormInfoPointer;
typedef ViewContent::SignInFormInfo *SignInFormInfoPointer;
typedef ViewContent::SignUpFormInfo *SignUpFormInfoPointer;

#endif /* VIEWCONTENT_H_ */
