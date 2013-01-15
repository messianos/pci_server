
#ifndef VIEWCONTENT_H_
#define VIEWCONTENT_H_

// Includes
#include <cppcms/view.h>
#include <string>

// Namespaces
using namespace cppcms;
using namespace std;

namespace ViewContent {

	struct testContent : public base_content {
		string text;
	};
}

#endif /* VIEWCONTENT_H_ */
