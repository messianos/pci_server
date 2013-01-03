#include <cppcms/view.h>  
#include <string>
#include "Problem.h"
using namespace std;

namespace main_screen_content{
	struct content: public cppcms::base_content{
		string user_id;
	};
	struct problemsHome : public cppcms::base_content{
		list<Problem> problems;
	};
}
