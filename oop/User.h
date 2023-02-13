#pragma once
#include <vector>
#include <map>
#include <string>
#include "Test.h"


using namespace std;


class User
{
protected:
	string login;
	string password;
	vector<Test> testsList;

public:
	User();
	User(string, string);
	User(const User &);
	virtual ~User();


	virtual bool signUp(string, string, string) = 0;
	virtual bool signIn(string, string) = 0;
	//virtual void signOut() = 0;


	inline string getLogin() const;
	inline string getPassword() const;

	inline User& setLogin(string);
	inline User& setPassword(string);

	inline virtual vector<Test> getTestsList() const = 0;
	virtual User& setTestsList() = 0;


	void sortTestsList();


	inline virtual void printInfo() = 0;
};
