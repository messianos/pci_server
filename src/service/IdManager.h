#ifndef IDMANAGER_H_
#define IDMANAGER_H_

// Includes
#include <boost/uuid/uuid_generators.hpp>
#include <iomanip>
#include <sstream>
#include <string>

class IdManager {

private:
	static const char PROBLEM_ID_PREFIX;
	static const char SOLUTION_ID_PREFIX;
	static const char CLARIFICATION_ID_PREFIX;
	static boost::uuids::random_generator uuid_generator;
	static std::string generateID(const char prefix);

public:
	static std::string generateProblemID();
	static std::string generateSolutionID();
	static std::string generateClarificationID();
	static std::string generateProposalID();
};

#endif /* IDMANAGER_H_ */
