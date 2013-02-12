
// Includes
#include "IdManager.h"

// Namespaces
using namespace boost::uuids;
using namespace std;

// Initializations
const char IdManager::PROBLEM_ID_PREFIX = 'P';
const char IdManager::SOLUTION_ID_PREFIX = 'S';
const char IdManager::CLARIFICATION_ID_PREFIX = 'C';
random_generator IdManager::uuid_generator = random_generator();

string IdManager::generateID(const char prefix) {

	// Generates the UUID
	uuid uuid = uuid_generator();
	unsigned int uuid_size = uuid.size();

	// Creates a string representing an hexadecimal number from a prefix and the UUID
	stringstream stream;
	stream << hex << setfill('0');
	stream << setw(2) << static_cast<unsigned int>(prefix);
	for (unsigned int i = 0; i < uuid_size; i++)
		stream << setw(2) << static_cast<unsigned int>(uuid.data[i]);

	return stream.str();
}

string IdManager::generateProblemID() {
	return generateID(PROBLEM_ID_PREFIX);
}

string IdManager::generateSolutionID() {
	return generateID(SOLUTION_ID_PREFIX);
}

string IdManager::generateClarificationID() {
	return generateID(CLARIFICATION_ID_PREFIX);
}
