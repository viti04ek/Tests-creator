#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include <vector>


using namespace std;


class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date();
	Date(int, int, int);
	//Date(const Date&);
	~Date();


	inline int getYear() const;
	inline int getMonth() const;
	inline int getDay() const;


	inline Date& setYear(int);
	inline Date& setMonth(int);
	inline Date& setDay(int);


	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	Date& operator= (Date);


	inline void printDate();

};


class Test
{
private:
	static int amountOfTests;
	int id;
	string title;
	string tasksFile;
	string resultsFile;
	int amountOfQuestions;
	Date creationDate;

public:
	Test();
	Test(int, string, string, string, int);
	Test(string, string, string, int);
	//Test(const Test &);
	~Test();


	inline int getId() const;
	inline Test &setId(int);

	inline string getTitle() const;
	Test &setTitle(string);

	inline string getTasksFile() const;
	inline Test &setTasksFile(string);

	inline string getResultsFile() const;
	inline Test &setResultsFile(string);

	inline int getAmountOfQuestion() const;
	inline Test &setAmountOfQuestion(int);

	inline Date getCreationDate() const;
	inline Test &setCreationDate(Date&);


	Test& operator= (Test);

	bool operator== (const Test&);

	bool operator!= (const Test&);

	bool operator< (const Test&) const;

	bool operator> (const Test&) const;

	friend istream& operator>> (istream&, Test&);

	friend ostream& operator<< (ostream&, const Test&);


	//int printTest();
	//int printResult(string);
	void saveResults(string, int);
	//void printResult();
	void printInfo();
	//vector<string> getQuestions();
	// Test::getAmountOfTest()

	static int getAmountOfTests();
};
