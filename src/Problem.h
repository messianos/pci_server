/*
 * Problem.h
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

#include "Publication.h"

class Problem: public Publication {
public:
	long accepted_solution_id;
	bool is_solved;

	Problem();
	virtual ~Problem();

};

#endif /* PROBLEM_H_ */
