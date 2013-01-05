/*
 * Dateclass.h
 *
 *  Created on: Jan 2, 2013
 *      Author: GNZ
 */

#ifndef DATECLASS_H_
#define DATECLASS_H_

class DateClass {
public:
	DateClass();
	DateClass(int day, int month, int year);
	virtual ~DateClass();

	int year;
	int month;
	int day;
};

#endif /* DATECLASS_H_ */
