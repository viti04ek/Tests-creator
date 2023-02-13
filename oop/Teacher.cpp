#include "Teacher.h"
#include "Test.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <map>


using namespace std;


Teacher::Teacher()
{
    //this->testsList = testsList;
    //cout << "Error: no data to create object" << endl;
}


Teacher::Teacher(string login, string password, vector<Test> testsList)
{
    this->login = login;
    this->password = password;
    this->testsList = testsList;
}


Teacher::Teacher(const Teacher &oldTeacher) : User(oldTeacher)
{
    
}


Teacher::~Teacher()
{
    this->testsList.clear();
}


inline vector<Test> Teacher::getTestsList() const
{
    return this->testsList;
}


Teacher &Teacher::setTestsList()
{
    testsList.clear();

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
        //cout << tmp1 << ". ";

        prev = next + delta;
        string tmp2 = line.substr(prev);
        //cout << tmp2 << endl;

        int tmp3 = stoi(tmp1);

        Test t(tmp3, tmp2, tmp2 + to_string(tmp3) + ".txt", "results" + tmp2 + to_string(tmp3) + ".txt", 0);

        testsList.push_back(t);

        //tests.emplace(tmp3, tmp2);
        //testsTitle.push_back(tmp);
    }



    //this->testsList = newTestsList;
    return *this;
}


Test& Teacher::operator[] (int index)
{
    return testsList[index];
}


istream& operator>> (istream& in, Teacher& obj)
{
    in >> obj.login >> obj.password;
    return in;
}


ostream& operator<< (std::ostream& out, const Teacher& obj) 
{
    out << "login: " << obj.login << ", password: " << obj.password;
    return out;
}


bool containsTeacher(string login)
{
    ifstream F;
    F.open("Teachers.txt", ifstream::app);


    string line;

    while (getline(F, line))
        if (line == login)
        {
            F.close();
            return true;
        }

    F.close();
    return false;
}

bool Teacher::signUp(string log, string pswrd1, string pswrd2)
{
    /*cout << "Sign Up Teacher:" << endl;
    cout << "Enter your login: ";
    getline(cin, login);

    while (containsTeacher(login))
    {
        cout << "Enter another login: ";
        getline(cin, login);
    }

    cout << "Enter your password: ";
    getline(cin, password);*/

    if (pswrd1 != pswrd2)
        return false;

    ifstream S;
    S.open("Students.txt", ifstream::app);

    string line;

    while (getline(S, line))
        if (line == login)
        {
            S.close();
            return false;
        }

    if (containsTeacher(log))
        return false;

    login = log;
    password = pswrd1;

    ofstream F;
    F.open(login + ".txt", ofstream::out | ofstream::app);

    F << login << endl << password << endl;

    F.close();


    ofstream T;
    T.open("Teachers.txt", ofstream::out | ofstream::app);

    T << login << endl;

    T.close();

    return true;
}


bool Teacher::signIn(string login, string password)
{
    /*cout << "Sign In Teacher:" << endl;

    cout << "Enter your login: ";
    getline(cin, login);

    while (!containsTeacher(login))
    {
        cout << "Entered non-existent login" << endl;
        cout << "Enter another login: ";
        getline(cin, login);
    }

    cout << "Enter your password: ";
    getline(cin, password);*/


    string pswrd;

    if (!containsTeacher(login))
        return false;

    ifstream F;
    F.open(login + ".txt", ifstream::app);

    /*if (F.peek() == EOF)
        return false;*/

    getline(F, pswrd);
    getline(F, pswrd);

    F.close();


    if (pswrd != password)
        return false;

    //cout << "Wrong password! Try again" << endl;

    this->login = login;
    this->password = password;

    return true;
}


inline void Teacher::printInfo()
{
    cout << "Teacher " << *this;
    if (this->testsList.size() == 0)
    {
        cout << " has not created any tests.";
    }
    else
    {
        cout << " created tests:" << endl;
        for (int i = 0; i < this->testsList.size(); i++)
        {
            cout << " " << testsList.at(i).getTitle();
        }
        cout << endl;
    }
}


void Teacher::createTest(string title, vector<string> questions, multimap<int, string> answers)
{
    //Date creationDate;
    string tasksFile, resultsFile;
    int amountOfQuestions = questions.size();
    //cout << "Enter title: ";
    ////cin >> title;
    //getline(cin, title);

    tasksFile = title + to_string(Test::getAmountOfTests()) + ".txt";
    resultsFile = "results" + title + to_string(Test::getAmountOfTests()) + ".txt";

    ofstream F;
    F.open(tasksFile, ofstream::out | ofstream::app);

    F << login << endl << title;


    //while
    /*while (true)
    {
        string question;
        vector<string> answers;
        int correctAnswerNumber;

        cout << "Question (press ESC to stop entering answers): ";
        int prssdKey = _getch();
        if (prssdKey == 27)
        {
            break;
        }
        else
        {
            //string question;
            //vector<string> answers;
            //cin >> question;
            do {
                getline(cin, question);
            } while (question == "");
            cout << "Anwsers (press ESC to stop entering answers):" << endl;
            for (int j = 1; ; j++)
            {
                int pressedKey = _getch();
                if (pressedKey == 27)
                {
                    break;
                }
                else
                {
                    cout << j << ")";
                    string answer;
                    //cin >> answer;
                    getline(cin, answer);
                    answers.push_back(answer);
                }    
            }
            //int correctAnswerNumber;
            cout << "Enter the number of correct answer: ";
            cin >> correctAnswerNumber;
            amountOfQuestions++;
        }

        ofstream F;
        F.open(tasksFile, ofstream::out | ofstream::app);

        F << amountOfQuestions << endl << question << endl;
        for (int i = 0; i < answers.size(); i++)
            if (i + 1 == correctAnswerNumber)
                F << "+" << endl << answers[i] << endl;
            else
                F << answers[i] << endl;

        F.close();
    }*/


    multimap<int, string>::iterator itr;
    itr = answers.begin();

    //itr = find(answers.begin(), answers.end(), "перший");

    for (int i = 0; i < questions.size(); i++)
    {
        F << endl << i;
        F << endl << questions.at(i);
        for (itr; itr != answers.end(); itr++)
        {
            if (itr->first == i + 1)
                break;
            F << endl << itr->second;
        }
    }

    F.close();

    Test T(title, tasksFile, resultsFile, amountOfQuestions);

    ofstream H;
    H.open("tests.txt", ofstream::out | ofstream::app);

    H << endl << T.getId() << " " << T.getTitle();

    H.close();


    testsList.push_back(T);


    ofstream FT;
    FT.open(login + ".txt", ofstream::out | ofstream::app);

    FT << T.getId() << " " << T.getTitle() << endl;

    FT.close();
}


//void Teacher::printTestList()
//{
//    for (int i = 0; i < testsList.size(); i++)
//        cout << testsList[i].getId() << " - " << testsList[i].getTitle() << endl;
//}


//void Teacher::printTestResults()
//{
//    if (testsList.size() == 0)
//        cout << "You didnt create any tests" << endl;
//    else
//        for (int i = 0; i < testsList.size(); i++)
//            testsList[i].printResult();
//}
