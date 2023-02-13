#include "User.h"
#include <iostream>
#include <fstream>


using namespace std;


User::User()
{
    //cout << "Error: no data to create object" << endl;
}


User::User(string username, string passwd)
{
    this->login = username;
    this->password = passwd;
}


User::User(const User &oldUser)
{
    this->login = oldUser.getLogin();
    this->password = oldUser.getPassword();
}


User::~User()
{
    // idk what to write here
}


inline string User::getLogin() const
{
    return this->login;
}


inline string User::getPassword() const
{
    return this->password;
}


inline User &User::setLogin(string newLogin)
{
    this->login = newLogin;
    return *this;
}


inline User &User::setPassword(string newPassword)
{
    this->password = newPassword;
    return *this;
}


void User::sortTestsList()
{
    int r = testsList.size() - 1, k, i;

    while (r)
    {
        for (i = 0, k = 0; i < r; i++)
        {
            if (testsList[i] > testsList[i + 1])
            {
                swap(testsList[i], testsList[i + 1]);
                k = i;
            }
        }
        r = k;
    }
}


/*User& User::setTestsList()
{
    ifstream F;
    F.open(this->login + ".txt", ifstream::app);

    string line;
    getline(F, line);
    getline(F, line);


    while (!F.eof())
    {
        getline(F, line);

        if (line == "")
            break;

        string delim(" ");
        size_t prev = 0;
        size_t next;
        size_t delta = delim.length();

        next = line.find(delim, prev);
        string tmp1 = line.substr(prev, next - prev);
        cout << tmp1 << ". ";

        prev = next + delta;
        string tmp2 = line.substr(prev);
        cout << tmp2 << endl;

        int tmp3 = stoi(tmp1);

        Test t(tmp3, tmp2, tmp2 + to_string(tmp3) + ".txt", "results" + tmp2 + to_string(tmp3) + ".txt", 0);

        testsList.push_back(t);

        //tests.emplace(tmp3, tmp2);
        //testsTitle.push_back(tmp);
    }



    //this->testsList = newTestsList;
    return *this;
}*/

//vector<Test> User::getTestsList()
//{
//    return this->testsList;
//}


//void User::printInfo()
//{
//    cout << this->login << endl;
//}