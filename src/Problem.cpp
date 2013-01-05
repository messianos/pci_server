/*
 * Problem.cpp
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#include "Problem.h"
Problem::Problem() {
	// TODO Auto-generated constructor stub
}

Problem::~Problem() {
	// TODO Auto-generated destructor stub
}

long Problem::getAcceptedSolutionId() {
	return accepted_solution_id;
}

void Problem::setAcceptedSolutionId(long acceptedSolutionId) {
	accepted_solution_id = acceptedSolutionId;
}

bool Problem::isIsSolved() {
	return is_solved;
}

void Problem::setIsSolved(bool isSolved) {
	is_solved = isSolved;
}
