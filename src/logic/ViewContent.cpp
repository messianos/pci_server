
// Includes
#include "ViewContent.h"

// Namespaces
using namespace boost;
using namespace std;

string ViewContent::escapeConflictingChars(string text) {
	replace_all(text, "\\", "\\\\");
	replace_all(text, "'", "\\'");
	return text;
}
