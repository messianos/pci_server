#include <cppcms/view.h>  
#include <string>
#include "Problem.h"
#include "Solution.h"
#include "Clarification.h"
#include <list>
using namespace std;

namespace main_screen_content {
struct content: public cppcms::base_content {
	string user_id;
};
struct problemsHome: public cppcms::base_content {
	list<Problem*>* problems;
};
struct problemInfo: public cppcms::base_content {
	Problem* problem;
	bool is_solved;
	Solution* accepted_solution;
	list<Solution*>* solutions;
	list<Clarification*>* clarifications;
};
/*
struct solutionInfo: public cppcms::base_content {
	Problem* problem;
	Solution* solution;
	list<Clarification*>* kk;
};*/
}
