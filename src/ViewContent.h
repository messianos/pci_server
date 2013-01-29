#ifndef VIEWCONTENT_H_
#define VIEWCONTENT_H_

// Includes
#include "Clarification.h"
#include "Problem.h"
#include "Solution.h"
#include "User.h"
#include <cppcms/form.h>
#include <cppcms/view.h>
#include <list>
#include <sstream>
#include <string>

// Type definitions
typedef Publication *PublicationPointer;
typedef Problem *ProblemPointer;
typedef Solution *SolutionPointer;
typedef std::list<Problem *> *ProblemList;
typedef std::list<Solution *> *SolutionList;
typedef std::list<Clarification *> *ClarificationList;

namespace ViewContent {


	struct NewProblemFormInfo : public cppcms::form {
		cppcms::widgets::textarea description;
		cppcms::widgets::textarea content;
		cppcms::widgets::checkbox is_anonymous;
		cppcms::widgets::submit submit;

		NewProblemFormInfo();
	};

	struct NewSolutionFormInfo : public cppcms::form {
		cppcms::widgets::textarea description;
		cppcms::widgets::textarea content;
		cppcms::widgets::checkbox is_anonymous;
		cppcms::widgets::submit submit;

		NewSolutionFormInfo();
	};

	struct SignInFormInfo : public cppcms::form {
		cppcms::widgets::text user_name;
		cppcms::widgets::password password;
		cppcms::widgets::submit submit;

		SignInFormInfo();
	};

	struct SignUpFormInfo : public cppcms::form {
		cppcms::widgets::text first_name;
		cppcms::widgets::text last_name;
		cppcms::widgets::text user_name;
		cppcms::widgets::text email;
		cppcms::widgets::password password;
		cppcms::widgets::password password_verification;
		cppcms::widgets::text date;
		cppcms::widgets::radio genre;
		cppcms::widgets::submit submit;

		SignUpFormInfo();
	};

	struct TemplateContent: public cppcms::base_content {
		std::string page_title;
		bool user_signed_in;
		std::string user_name;
		std::string user_first_name;
		std::string user_last_name;
	};

	struct FormContent : public TemplateContent {
		bool successful_submit;
		std::string error_description;
	};

	struct IdeasContent : TemplateContent {
	};

	struct IndexContent : TemplateContent {
	};

	struct ProblemContent : TemplateContent {
		Problem *problem;
		Solution *accepted_solution;
		std::list<Solution *> *solutions;
		std::list<Clarification *> *clarifications;
	};

	struct NewProblemContent : FormContent {
		NewProblemFormInfo form_info;
	};

	struct ProblemsContent : TemplateContent {
		ProblemList problems;
	};

	struct SignInContent : FormContent {
		SignInFormInfo form_info;
	};

	struct SignUpContent : FormContent{
		SignUpFormInfo form_info;
	};

	struct SolutionContent: TemplateContent {
		Solution *solution;
		std::list<Clarification *> *clarifications;
	};

	struct NewSolutionContent : FormContent {
		NewSolutionFormInfo form_info;
	};

	struct UserContent : TemplateContent {
		User* user;
	};
}

#endif /* VIEWCONTENT_H_ */
