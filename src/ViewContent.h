#ifndef VIEWCONTENT_H_
#define VIEWCONTENT_H_

// Includes
#include "Clarification.h"
#include "Problem.h"
#include "Solution.h"
#include <cppcms/form.h>
#include <cppcms/view.h>
#include <list>
#include <string>
#include <cppcms/http_context.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>

// Type definitions
typedef Problem *ProblemPointer;
typedef Solution *SolutionPointer;
typedef std::list<Problem *> *ProblemList;
typedef std::list<Solution *> *SolutionList;
typedef std::list<Clarification *> *ClarificationList;

/********** This is the solution for the forms *********/
//TODO: IT SHOULD BE RELOCATED, MAYBE IN A CPP

using namespace cppcms;

class custom_text: public cppcms::widgets::text {
public:
	void load(http::context &http) {
		cppcms::widgets::base_text::load(http);
	}

	void render_input(form_context &context) {
		cppcms::widgets::base_html_input::render_input(context);
	}
};
class custom_password: public cppcms::widgets::password {
public:
	void load(http::context &http) {
		cppcms::widgets::base_text::load(http);
	}

	void render_input(form_context &context) {
		cppcms::widgets::base_html_input::render_input(context);
	}
};
/************************/


namespace ViewContent {

struct TemplateContent: public cppcms::base_content {
	std::string page_title;
};

struct IdeasContent: TemplateContent {
};

struct IndexContent: TemplateContent {
};

struct ProblemContent: TemplateContent {
	Problem *problem;
	Solution *accepted_solution;
	std::list<Solution *> *solutions;
	std::list<Clarification *> *clarifications;
};

struct ProblemsContent: TemplateContent {
	ProblemList problems;
};

struct SignInFormInfo: public cppcms::form {
	custom_text user_name;
	custom_password password;
	cppcms::widgets::submit submit;

	SignInFormInfo() {
		user_name.message("User name");
		password.message("Password");
		submit.value("Sign in");

		add(user_name);
		add(password);
		add(submit);

		// Restrictions
		user_name.limits(1, 31);
		password.non_empty();
	}
};

struct SignInContent: TemplateContent {
	SignInFormInfo form_info;
};

struct SolutionContent: TemplateContent {
	Solution *solution;
	std::list<Clarification *> *clarifications;
};
}

#endif /* VIEWCONTENT_H_ */
