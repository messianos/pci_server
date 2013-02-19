
#ifndef SOLUTION_H_
#define SOLUTION_H_

// Includes
#include "Publication.h"

class Solution: public Publication {

public:
	std::string problem_id;
	Solution();
	virtual ~Solution();
};

#endif /* SOLUTION_H_ */
