
// Includes
#include "Datetime.h"

// Namespaces
using namespace std;

Datetime::Datetime(time_t timestamp) {
	this->timestamp = timestamp;
}

Datetime::~Datetime() {}

string Datetime::toString(string format) {
	char buffer[32];
	strftime(buffer, 32, format.data(), localtime(&timestamp));
	return string(buffer);
}
