#include <cppcms/view.h>  
#include <string>
#include "Problem.h"
#include "Solution.h"
#include <list>
using namespace std;

namespace main_screen_content{
	struct content: public cppcms::base_content{
		string user_id;
	};
	struct problemsHome : public cppcms::base_content{
		list<Problem*> problems;
	};
	struct problemInfo : public cppcms::base_content{
		Problem* problem;
		Solution* accepted_solution;
		list<Solution*> solutions;
	};
}
