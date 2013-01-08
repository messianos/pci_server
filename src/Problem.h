
#ifndef PROBLEM_H_
#define PROBLEM_H_

// Includes
#include "Publication.h"
#include <string>

class Problem : public Publication {

public:
	std::string accepted_solution_id;
	bool is_solved;
	Problem();
	virtual ~Problem();
};

#endif /* PROBLEM_H_ */
