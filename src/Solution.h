/*
 * Solution.h
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "Publication.h"

class Solution: public Publication {
public:
	Solution();
	Solution(long id, string content, string description,
			bool is_anonymous, time_t last_edition_datetime,
			time_t creation_datetime);
	virtual ~Solution();
};

#endif /* SOLUTION_H_ */
