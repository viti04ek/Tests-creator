#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/event.h>

#include <fstream>
#include <map>
#include <cmath>

#include "Test.h"


using namespace std;


class StartWindow : public wxFrame
{
private:
    wxTextCtrl* loginField;
    wxTextCtrl* passwordField;
    wxStaticText* warningText;
    wxRadioBox* studentOrTeacherRadioBox;
    char choice = 's';

public:
    StartWindow();

    void signIn(wxCommandEvent&);
    void signUp(wxCommandEvent&);
    void saveChoice(wxCommandEvent&);

};


class SignUpWindow : public wxFrame
{
private:
    wxTextCtrl* loginField;
    wxTextCtrl* passwordField1;
    wxTextCtrl* passwordField2;
    wxStaticText* warningText;
    wxRadioBox* studentOrTeacherRadioBox;
    char choice = 's';

public:
    SignUpWindow();

    void signUp(wxCommandEvent&);
    void goBack(wxCommandEvent&);
    void saveChoice(wxCommandEvent&);

};


class MainWindowTeacher : public wxFrame
{
private:
    int startButtonPanelCoordX = 60;
    int startButtonPanelCoordY = 60;
    int amountOfMenuButtons = 0;

    wxButton* sortButton;
    wxScrolledWindow* testsPanel;

    vector<wxButton*> testButtons;

public:
    MainWindowTeacher();
    
    void showMarks(wxCommandEvent&);
    void logOut(wxCommandEvent&);

    void onExit(wxCommandEvent&);
    void createNewTest(wxCommandEvent&);
    void sortTests(wxCommandEvent&);
};


class TestResultsWindow : public wxFrame
{
private:
    int startButtonPanelCoordX = 60;
    int startButtonPanelCoordY = 60;
    int amountOfMenuButtons = 0;
    int choice;

public:
    //TestResultsWindow();
    TestResultsWindow(int);

    void goBack(wxCommandEvent&);
};


class ShowMarksWindow : public wxFrame
{
private:
    int startButtonPanelCoordX = 60;
    int startButtonPanelCoordY = 60;
    int amountOfMenuButtons = 0;

public:
    //TestResultsWindow();
    ShowMarksWindow();

    void goBack(wxCommandEvent&);
};


class CreateTestWindow : public wxFrame
{
private:
    wxButton* goToCreation;
    wxButton* goBackButton;
    wxButton* newAnswerButton;
    wxButton* newQuestionButton;
    wxButton* finishTestButton;
    wxCheckBox* correctAnswerBox;

    wxStaticText* titleText;
    wxStaticText* questionText;
    wxStaticText* answersText;
    wxStaticText* checkboxText;
    wxStaticText* testPreview;
   
    wxTextCtrl* title;
    wxTextCtrl* question;
    wxTextCtrl* answer;
    vector<string> questions;
    multimap<int, string> answers;

    int amountOfQuestions = 1;
    int answersCounter = 0;

    int startButtonPanelCoordX = 60;
    int newButtonPanelCoordY = 125;
    int amountOfMenuButtons = 0;

public:
    CreateTestWindow();
    void finishTest(wxCommandEvent&);
    void newQuestion(wxCommandEvent&);
    void goToCreations(wxCommandEvent&);
    void newAnswer(wxCommandEvent&);

    void goBack(wxCommandEvent&);
    void onExit(wxCommandEvent&);
};


class MainWindowStudent : public wxFrame
{
private:
    int startButtonPanelCoordX = 60;
    int startButtonPanelCoordY = 60;
    int amountOfMenuButtons = 0;

    wxTextCtrl* searchBox;
    wxButton* sortButton;
    wxScrolledWindow* testsPanel;

    vector<wxButton*> testButtons;

    void sortTests(wxCommandEvent&);

public:
    MainWindowStudent();

    void startTest(wxCommandEvent&);
    void showMarks(wxCommandEvent&);
    void search(wxCommandEvent&);
    void logOut(wxCommandEvent&);
    void onExit(wxCommandEvent&);
};


class TestWindow : public wxFrame
{
private:
    int startButtonPanelCoordX = 60;
    int startButtonPanelCoordY = 60;
    int amountOfMenuButtons = 0;
    int questionCounter = 0;
    int amountOfCorrectAnswers = 0;

    string correctAnswer = "";

    Test test;
    vector<string> questions;
    multimap<int, string> variants;
    vector<string> answers;

    wxPanel* panel;
    wxStaticText* title;
    wxStaticText* creationDate;
    wxStaticText* question;
    wxStaticText* pageCount;
    wxButton* nextQuestionButton;
    wxButton* finishTestButton;
    wxRadioBox* answersRadioBox;
    wxString choices[50];

public:
    //TestWindow();
    TestWindow(int);
    void nextQuestion(wxCommandEvent&);
    void finishTest(wxCommandEvent&);
    void goToHome(wxCommandEvent&);
    //void saveChoice(wxCommandEvent&);
};


class UserInterface : public wxApp {
public:
    virtual bool OnInit();

};


wxIMPLEMENT_APP(UserInterface);
