/*
 * Problem.h
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

#include "Publication.h"

class Problem : public Publication {
private:
	bool is_solved;
public:
	Problem(long id, string content, string description,
			bool is_anonymous, time_t last_edition_datetime,
			time_t creation_datetime);
	virtual ~Problem();
};

#endif /* PROBLEM_H_ */
