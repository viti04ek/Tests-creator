#pragma once
#include "User.h"
#include "Test.h"
#include <vector>


using namespace std;


class Mark
{
private:
	int testId;
	int mark;

public:
	Mark();
	Mark(int, int);
	//Mark(Mark &);
	~Mark();

	inline Mark &setTestId(int);
	inline int getTestId() const;

	inline Mark &setMark(int);
	inline int getMark() const;


	Mark &operator=(Mark &);


	inline void printInfo();
};


class Student : public User
{
private:
	vector<Mark> marks;

public:
	Student();
	Student(string, string, vector<Mark>);
	Student(const Student &);
	virtual ~Student();


	inline vector<Mark> getMarks() const;
	Student& setMarks();

	inline vector<Test> getTestsList() const override;
	Student& setTestsList() override;

	Student& modTestsList(const vector<Test>&);


	Mark& operator[] (int);

	friend istream& operator>> (istream&, Student&);

	friend ostream& operator<< (ostream&, const Student&);


	bool signUp(string, string, string) override;
	bool signIn(string, string) override;
	//void signOut() override;


	vector<Test> searchTests(string);

	void addMarks(int, int);
	//void doTest();
	void printMarks();
	inline void printInfo() override;
};
