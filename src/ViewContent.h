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

// Type definitions
typedef Problem *ProblemPointer;
typedef Solution *SolutionPointer;
typedef std::list<Problem *> *ProblemList;
typedef std::list<Solution *> *SolutionList;
typedef std::list<Clarification *> *ClarificationList;

using namespace cppcms; // TODO: Is this correct?
using namespace std;

namespace ViewContent {

struct TemplateContent: public cppcms::base_content {
	string page_title;
	bool user_logged = 0;
	string user_name;
};

struct IdeasContent: TemplateContent {
};

struct IndexContent: TemplateContent {
};

struct ProblemContent: TemplateContent {
	Problem *problem;
	Solution *accepted_solution;
	list<Solution *> *solutions;
	list<Clarification *> *clarifications;
};

struct ProblemsContent: TemplateContent {
	ProblemList problems;
};

struct SignInFormInfo: public cppcms::form {
	widgets::text user_name;
	widgets::password password;
	widgets::submit submit;

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

struct SignUpFormInfo : public cppcms::form {
	widgets::text first_name;
	widgets::text last_name;
	widgets::text user_name;
	widgets::text email;
	widgets::password password;
	widgets::password password_verification;
	// Birth date
	widgets::select day;
	widgets::select month;
	widgets::select year;
	// //
	widgets::submit submit;

	SignUpFormInfo(){
		first_name.message("Nombre");
		last_name.message("Apellido");
		user_name.message("Nombre de usuario");
		email.message("E-mail");
		password.message("Nueva Contraseña");
		password_verification.message("Repita la contraseña");

		// FIXME: All months with 30 days!!!
		for (int i = 1; i < 30; ++i) {
			stringstream s;
			s << i;
			day.add(s.str());
		}
		day.message("");

		// FIXME: Add all months
		const int MONTHS_NUMBER = 3;
		string months_names []= {"Enero", "Febrero", "Marzo" };

		for (int i = 0; i < MONTHS_NUMBER; ++i) {
			month.add(months_names[i]);
		}
		month.message("");

		// FIXME: Check max year
		for (int i = 2013; i > 1905; --i) {
			stringstream s;
			s << i;
			year.add(s.str());
		}
		month.message("");

		submit.value("Registrar");


		add(first_name);
		add(last_name);
		add(user_name);
		add(email);
		add(password);
		add(password_verification);
		add(day);
		add(month);
		add(year);
		add(submit);

		// Restrictions
		// TODO: Revise
		first_name.non_empty();
		last_name.non_empty();
		user_name.non_empty();
		email.non_empty();
		password.non_empty();
		password_verification.non_empty();
		day.non_empty();
		month.non_empty();
		year.non_empty();
	}
};

struct SignUpContent : TemplateContent{
	SignUpFormInfo form_info;
};

struct SolutionContent: TemplateContent {
	Solution *solution;
	list<Clarification *> *clarifications;
};
}

#endif /* VIEWCONTENT_H_ */
