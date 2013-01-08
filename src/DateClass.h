
#ifndef DATECLASS_H_
#define DATECLASS_H_

class DateClass {

private:
	int day;
	int month;
	int year;

public:
	DateClass();
	DateClass(int day, int month, int year);
	virtual ~DateClass();
};

#endif /* DATECLASS_H_ */
