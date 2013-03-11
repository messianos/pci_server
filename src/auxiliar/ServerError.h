
#ifndef SERVERERROR_H_
#define SERVERERROR_H_

// Includes
#include <string>

class ServerError {

public:
	static const std::string INVALID_PARAMETERS;
	static const std::string NOT_SIGNED_IN;
	static const std::string EXISTING_USER;
	static const std::string UNAUTHORIZED_USER;
	static const std::string BAD_URL;
	static const std::string NONEXISTENT_CLARIFICATION;
	static const std::string NONEXISTENT_PROBLEM;
	static const std::string NONEXISTENT_PROPOSAL;
	static const std::string NONEXISTENT_SOLUTION;
	static const std::string NONEXISTENT_USER;
	static const std::string METHOD_NOT_ALLOWED;
	static const std::string UNKNOWN;
};

#endif /* SERVERERROR_H_ */
