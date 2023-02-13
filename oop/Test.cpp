#include "Test.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>



using namespace std;


int Test::amountOfTests = 0; //замість 0 буде братися id останнього елементу з файлу


Test::Test()
{
    //cout << "Error: no data to create object" << endl;
}


Date::Date()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    //localtime_s(&ltm, &now);

    this->year = 1900 + ltm->tm_year;
    this->month = 1 + ltm->tm_mon;
    this->day = ltm->tm_mday;
}


Date::Date(int newDay, int newMonth, int newYear)
{
    this->year = newYear;
    this->month = newMonth;
    this->day = newDay;
}


/*Date::Date(const Date& newDate)
{
    this->year = newDate.getYear();
    this->month = newDate.getMonth();
    this->day = newDate.getDay();
}*/


Date::~Date()
{

}


inline int Date::getYear() const
{
    return this->year;
}


inline int Date::getMonth() const
{
    return this->month;
}


inline int Date::getDay() const
{
    return this->day;
}


inline Date& Date::setYear(int newYear)
{
    this->year = newYear;
    return *this;
}


inline Date& Date::setMonth(int newMonth)
{
    this->month = newMonth;
    return *this;
}


inline Date& Date::setDay(int newDay)
{
    this->day = newDay;
    return *this;
}


Date& Date::operator++() 
{
    ++day;
    return *this;
}


Date Date::operator++(int) 
{
    Date temp(*this);
    ++day;
    return temp;
}


Date& Date::operator--()
{
    --day;
    return *this;
}


Date Date::operator--(int)
{
    Date temp(*this);
    --day;
    return temp;
}


Date& Date::operator= (Date right)
{
    this->year = right.getYear();
    this->month = right.getMonth();
    this->day = right.getDay();

    return *this;
}


istream& operator>> (istream& in, Test& obj)
{
    in >> obj.id >> obj.title;
    return in;
}


ostream& operator<< (std::ostream& out, const Test& obj) 
{
    out << "id: " << obj.id << ", title: " << obj.title;
    return out;
}


inline void Date::printDate()
{
    cout << day << ":" << month << ":" << year << endl;
}


Test::Test(int id, string title, string tasksFile, string resultsFile, int amountOfQuestions)
{
    getAmountOfTests();
    this->id = id;
    amountOfTests++;
    this->title = title;
    this->tasksFile = tasksFile;
    this->resultsFile = resultsFile;
    this->amountOfQuestions = amountOfQuestions;
}


Test::Test(string title, string tasksFile, string resultsFile, int amountOfQuestions)
{
    getAmountOfTests();
    this->id = amountOfTests;
    amountOfTests++;
    this->title = title;
    this->tasksFile = tasksFile;
    this->resultsFile = resultsFile;
    this->amountOfQuestions = amountOfQuestions;
}


/*Test::Test(const Test& oldTest)
{
    this->id = amountOfTests;
    //amountOfTests++;
    this->title = oldTest.getTitle();
    this->tasksFile = oldTest.getTasksFile();
    this->resultsFile = oldTest.getResultsFile();
    this->amountOfQuestions = oldTest.getAmountOfQuestion();
}*/


Test::~Test()
{
    //idk what to write here
}


inline int Test::getId() const
{
    return this->id;
}


inline Test &Test::setId(int newId)
{
    this->id = newId;
    return *this;
}


inline string Test::getTitle() const
{
    return this->title;
}


Test& Test::setTitle(string newTitle)
{
    this->title = newTitle;
    return *this;
}


inline string Test::getTasksFile() const
{
    return this->tasksFile;
}


inline Test &Test::setTasksFile(string newTasksFile)
{
    this->tasksFile = newTasksFile;
    return *this;
}


inline string Test::getResultsFile() const
{
    return this->resultsFile;
}


inline Test &Test::setResultsFile(string newResultsFile)
{
    this->resultsFile = newResultsFile;
    return *this;
}


inline Date Test::getCreationDate() const
{
    return this->creationDate;
}


inline Test& Test::setCreationDate(Date& newDate)
{
    this->creationDate = newDate;
    return *this;
}


inline int Test::getAmountOfQuestion() const
{
    return this->amountOfQuestions;
}


inline Test& Test::setAmountOfQuestion(int newAmountOfQuestions)
{
    this->amountOfQuestions = newAmountOfQuestions;
    return *this;
}


Test& Test::operator= (Test right)
{
    this->id = right.getId();
    this->title = right.getTitle();
    this->tasksFile = right.getTasksFile();
    this->resultsFile = right.getResultsFile();
    this->amountOfQuestions = right.getAmountOfQuestion();
    this->creationDate = right.getCreationDate();

    return *this;
}


bool Test::operator== (const Test& right)
{
    if (this->title == right.getTitle())
        return true;
    else
        return false;
}


bool Test::operator!= (const Test& right)
{
    if (*this == right)
        return false;
    else
        return true;
}


bool Test::operator< (const Test& right) const
{
    if (this->title < right.getTitle())
        return true;
    else
        return false;
}


bool Test::operator> (const Test& right) const
{
    return (right < *this);
    /*
    if (right < *this) return true;
    else return false;
    */
    /*
    if (this->title > right.getTitle())
        return true;
    else
        return false;
     */
}


void Test::printInfo()
{
    cout << *this;
}


int Test::getAmountOfTests()
{
    ifstream F;
    F.open("tests.txt", ofstream::out | ofstream::app);

    string lastLine;
    int number = 0;

    while (!F.eof())
        getline(F, lastLine);

    for (int i = 0; ; i++)
        if (lastLine[i] != ' ' && lastLine != "")
            number = number * 10 + (lastLine[i] - '0');
        else
            break;

    amountOfTests = number + 1;

    return amountOfTests;
}


bool contains(char s, vector<string> str)
{
    for (int i = 0; i < str.size(); i++)
        if (s == str[i][0])
            return true;

    return false;
}

/*int Test::printTest()
{
    system("cls");

    ifstream F;
    F.open(tasksFile, ifstream::app);


    string variant;
    vector<string> variants;
    int correct = 0;

    getline(F, variant); //берем логин создателя, для теста не нужен
    getline(F, variant); //берем заголовок, для теста не нужен

    while (variant != "")
    {
        int correct_answer = 0;
        int answer;
        string question;
        vector<string> numbers = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

        getline(F, variant);

        question = variant;

        int i = 0;
        while (getline(F, variant))
        {
            system("cls");


            if (variant[0] == '+')
            {
                correct_answer = i;
            }
            else
            {
                if (!contains(variant[0], numbers))
                    variants.push_back(variant);
                else
                    break;

                /*int ex = 0;

                try
                {
                    int temp = stoi(variant);
                }
                catch (char* e)
                {
                    ex = 1;
                }

                if (ex == 1)
                    variants.push_back(variant);
                else
                    break;

                i++;
            }
        }


        cout << question << endl;

        for (int i = 0; i < variants.size(); i++)
            cout << i + 1 << ") " << variants[i] << endl;

        cout << "Choose number of answer: ";
        cin >> answer;

        if (answer - 1 == correct_answer)
            correct++;
        amountOfQuestions++;


        variants.clear();
    }

    F.close();

    return correct;
}*/


/*int Test::printResult(string login)
{
    int correctAnswers = printTest();

    int result = (correctAnswers * 10) / amountOfQuestions;

    system("cls");

    cout << "Your result: " << result << "/10" << endl;
    cout << "Press any buttom to return";

    saveResults(login, result);

    _getch();
    system("cls");

    return result;
}*/


void Test::saveResults(string login, int result)
{
    ofstream F;
    F.open(resultsFile, ofstream::out | ofstream::app);

    F << login << " " << result << endl;

    F.close();
}

/*
void Test::printResult()
{
    cout << "Test id: " << id << endl << "Test title: " << title << endl;

    ifstream F;
    F.open(resultsFile, ofstream::app);

    string line;

    while (getline(F, line))
        cout << line << endl;

    F.close();
}*/

/*vector<string> Test::getQuestions()
{
    ifstream F;
    F.open(tasksFile, ofstream::app);

    string line;

    getline(F, line);
    getline(F, line);

}*/
