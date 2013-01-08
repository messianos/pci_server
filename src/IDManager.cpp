
// Includes
#include "IDManager.h"

// Namespaces
using namespace boost::uuids;
using namespace std;

// Initializations
const char IDManager::PROBLEM_ID_PREFIX = 'P';
const char IDManager::SOLUTION_ID_PREFIX = 'S';
const char IDManager::CLARIFICATION_ID_PREFIX = 'C';
random_generator IDManager::uuid_generator = random_generator();

string IDManager::generateID(const char prefix) {
	stringstream stream;
	uuid uuid;
	unsigned int uuid_size;

	// Generates the UUID
	uuid = uuid_generator();
	uuid_size = uuid.size();

	// Creates a string representing an hexadecimal number from a prefix and the UUID
	stream << hex << setfill('0');
	stream << setw(2) << static_cast<unsigned int>(prefix);
	for (unsigned int i = 0; i < uuid_size; i++)
		stream << setw(2) << static_cast<unsigned int>(uuid.data[i]);

	return stream.str();
}

string IDManager::generateProblemID() {
	return generateID(PROBLEM_ID_PREFIX);
}

string IDManager::generateSolutionID() {
	return generateID(SOLUTION_ID_PREFIX);
}

string IDManager::generateClarificationID() {
	return generateID(CLARIFICATION_ID_PREFIX);
}
