#include "Student.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>


using namespace std;


Mark::Mark()
{
    //cout << "Error: no data to create object" << endl;
}


Mark::Mark(int testId, int mark)
{
    this->testId = testId;
    this->mark = mark;
}


/*Mark::Mark(Mark& oldMark)
{
    this->testId = oldMark.getTestId();
    this->mark = oldMark.getMark();
}*/


Mark::~Mark()
{
    // idk what to write here
}

// Mark m; fun (m.setTestId(3).setMark())
inline Mark &Mark::setTestId(int newTestId)
{
    this->testId = newTestId;
    return *this;
}


inline int Mark::getTestId() const
{
    return this->testId;
}


inline Mark &Mark::setMark(int newMark)
{
    this->mark = newMark;
    return *this;
}


inline int Mark::getMark()const
{
    return this->mark;
}


Mark &Mark::operator= (Mark &right)
{
    this->testId = right.getTestId();
    this->mark = right.getMark();
    return *this;
}


inline void Mark::printInfo()
{
    cout << "Test №"
         << this->testId
         << ": "
         << this->mark
         << endl;
}


Student::Student()
{
    //cout << "Error: no data to create object" << endl;
}


Student::Student(string login, string password, vector<Mark> marks)
{
    this->login = login;
    this->password = password;
    this->marks = marks;
    this->testsList = testsList;
}


Student::Student(const Student &oldStudent) : User(oldStudent)
{
    this->marks = oldStudent.getMarks();
    this->testsList = oldStudent.getTestsList();
}


Student::~Student()
{
    this->marks.clear();
}


inline vector<Mark> Student::getMarks() const
{
    return this->marks;
}


Student &Student::setMarks()
{
    ifstream F;
    F.open(this->login + ".txt", ifstream::app);

    string line;
    getline(F, line);
    getline(F, line);

    while (!F.eof())
    {
        int tempId, tempResult;

        getline(F, line);

        if (line == "")
            break;

        tempId = stoi(line);

        getline(F, line);

        tempResult = stoi(line);

        Mark m(tempId, tempResult);

        marks.push_back(m);
    }
    return *this;
}


Student& Student::modTestsList(const vector<Test>& newList)
{
    this->testsList = newList;
    return *this;
}


Student& Student::setTestsList()
{
    testsList.clear();

    ifstream F;
    F.open("tests.txt", ifstream::app);

    string line;
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


inline vector<Test> Student::getTestsList() const
{
    return this->testsList;
}


Mark& Student::operator[] (int index)
{
    return marks[index];
}


istream& operator>> (istream& in, Student& obj) 
{
    in >> obj.login >> obj.password;
    return in;
}


ostream& operator<< (std::ostream& out, const Student& obj) 
{
    out << "login: " << obj.login << ", password: " << obj.password;
    return out;
}


void Student::printMarks()
{
    for (int i = 0; i < this->marks.size(); i++)
    {
        this->marks.at(i).printInfo();
    }
}


bool containsStudent(string login)
{
    ifstream F;
    F.open("Students.txt", ifstream::app);


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

bool Student::signUp(string log, string pswrd1, string pswrd2)
{
    /*cout << "Sign Up Student:" << endl;
    cout << "Enter your login: ";
    getline(cin, login);

    while (containsStudent(login))
    {
        cout << "Enter another login: ";
        getline(cin, login);
    }

    cout << "Enter your password: ";
    getline(cin, password);*/

    if (containsStudent(log))
        return false;

    ifstream T;
    T.open("Teachers.txt", ifstream::app);

    string line;

    while (getline(T, line))
        if (line == login)
        {
            T.close();
            return false;
        }

    if (pswrd1 != pswrd2)
        return false;

    login = log;
    password = pswrd1;


    ofstream F;
    F.open(login + ".txt", ofstream::out | ofstream::app);

    F << login << endl << password << endl;

    F.close();


    ofstream S;
    S.open("Students.txt", ofstream::out | ofstream::app);

    S << login << endl;

    S.close();

    return true;
}


bool Student::signIn(string login, string password)
{
    string pswrd;

    if (!containsStudent(login))
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


vector<Test> Student::searchTests(string searchTitle)
{
    setTestsList();


    vector<Test> results;

    Test searchTest;
    searchTest.setTitle(searchTitle);

    for (int i = 0; i < testsList.size(); i++)
        if (testsList[i] == searchTest)
            results.push_back(testsList[i]);


    return results;
}


inline void Student::printInfo()
{
    cout << *this;
    this->printMarks();
}


/*void Student::doTest()
{
    //vector<int> testsId;
    //vector<string> testsTitle;
    map<int, string> tests;
    string line;


    ifstream F;
    F.open("tests.txt", ifstream::app);

    getline(F, line);
    while (!F.eof())
    {
        getline(F, line);
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
        tests.emplace(tmp3, tmp2);
    }


    int chooseId;
    cout << "Choose test id: ";
    cin >> chooseId;

    while (tests.find(chooseId) == tests.end())
    {
        cout << "Choose id from the list: ";
        cin >> chooseId;
    }


    string title = tests[chooseId];
    string tasksFile = title + to_string(chooseId) + ".txt";
    string resultsFile = "results" + title + to_string(chooseId) + ".txt";

    Test test(title, tasksFile, resultsFile, 0);


    int result = test.printResult(login);


    addMarks(chooseId, result);
}*/


void Student::addMarks(int testId, int result)
{
    Mark mark(testId, result);

    marks.push_back(mark);


    ofstream F;
    F.open(login + ".txt", ofstream::out | ofstream::app);

    F << testId << endl << result << endl;

    F.close();
}
