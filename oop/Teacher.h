#pragma once
#include "User.h"
#include "Test.h"
#include <vector>
#include <map>


using namespace std;


class Teacher : public User
{
private:
	//vector<Test> testsList;

public:
	Teacher();
	Teacher(string, string, vector<Test>);
	Teacher(const Teacher &);
	virtual ~Teacher();


	inline vector<Test> getTestsList() const override;
	Teacher& setTestsList() override;


	Test& operator[] (int);

	friend istream& operator>> (istream&, Teacher&);

	friend ostream& operator<< (ostream&, const Teacher&);


	bool signUp(string, string, string) override;
	bool signIn(string, string) override;
	//void signOut() override;


	void createTest(string, vector<string>, multimap<int, string>);
	//void printTestList();
	//void printTestResults();
	inline void printInfo() override;
};
