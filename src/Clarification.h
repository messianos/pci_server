#include <string>
using namespace std;

#ifndef CLARIFICATION_H_
#define CLARIFICATION_H_

class Clarification {
public:
	Clarification();
	virtual ~Clarification();

	string answer;
	long associated_publication_id;
	string creator_user_name;
	long id;
	string question;
};

#endif /* CLARIFICATION_H_ */
