
#ifndef SOLUTION_H_
#define SOLUTION_H_

// Includes
#include "Problem.h"
#include "Publication.h"

class Solution: public Publication {

public:
	std::string problem_id;
	Problem *link_problem;
	Solution();
	virtual ~Solution();
};

#endif /* SOLUTION_H_ */
