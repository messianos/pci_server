
// Includes
#include "ViewContent.h"

// Namespaces
using namespace boost;
using namespace std;

string ViewContent::javascriptSafeText(string text) {
	// TODO: is this okay??? is this really safe???
	// Careful: the order of the replacements affects the outcome
	replace_all(text, "\\", "\\\\");
	replace_all(text, "\n", "\\n");
	replace_all(text, "'", "\\'");
	return text;
}
