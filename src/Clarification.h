using namespace std;

#ifndef CLARIFICATION_H_
#define CLARIFICATION_H_

class Clarification {
private:
	string answer;
	string question;
	long id;

public:
	Clarification();
	virtual ~Clarification();

	const string& getAnswer() const {
		return answer;
	}

	void setAnswer(const string& answer) {
		this->answer = answer;
	}

	long getId() const {
		return id;
	}

	void setId(long id) {
		this->id = id;
	}

	const string& getQuestion() const {
		return question;
	}

	void setQuestion(const string& question) {
		this->question = question;
	}
};

#endif /* CLARIFICATION_H_ */
