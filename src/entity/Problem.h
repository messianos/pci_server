
#ifndef PROBLEM_H_
#define PROBLEM_H_

// Includes
#include "Publication.h"
#include <string>

class Problem : public Publication {

public:
	short int is_solved;
	Problem();
	virtual ~Problem();
};

#endif /* PROBLEM_H_ */
