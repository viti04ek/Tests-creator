#include "UserInterface.h"
#include "Test.h"
#include "Teacher.h"
#include "Student.h"


using namespace std;


Student S;
Teacher T;


bool UserInterface::OnInit()
{
    StartWindow* startWin = new StartWindow;
    startWin->Show(true);

    return true;
}


StartWindow::StartWindow() : wxFrame(NULL, wxID_ANY, "Вхід у систему", wxPoint(100, 100), wxSize(1280, 720))
{
    this->SetBackgroundColour(*wxWHITE);

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxStaticText* loginText = new wxStaticText(panel, wxID_ANY, "Логін", wxPoint(100, 75));
    wxStaticText* passwordText = new wxStaticText(panel, wxID_ANY, "Пароль", wxPoint(300, 75));

    this->loginField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 100));
    this->passwordField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 100), wxDefaultSize, wxTE_PASSWORD);

    warningText = new wxStaticText(panel, wxID_ANY, "Неправильний логін або пароль", wxPoint(150, 125));
    warningText->Hide();

    wxString choices[] = { "Студент", "Викладач" };
    studentOrTeacherRadioBox = new wxRadioBox(panel, 4, "", wxPoint(450, 85), wxDefaultSize, 2, choices);

    wxButton* signInButton = new wxButton(panel, wxID_ANY, wxT("Увійти в систему"), wxPoint(200, 150));
    wxButton* signUpButton = new wxButton(panel, wxID_ANY, wxT("Зареєструватися в системі"), wxPoint(180, 200));

    signInButton->Bind(wxEVT_BUTTON, &StartWindow::signIn, this);
    signUpButton->Bind(wxEVT_BUTTON, &StartWindow::signUp, this);
    studentOrTeacherRadioBox->Bind(wxEVT_RADIOBOX, &StartWindow::saveChoice, this);

}


void StartWindow::saveChoice(wxCommandEvent& event)
{
    if (wxString("Студент") == studentOrTeacherRadioBox->GetString(event.GetSelection()))        choice = 's';
    else if (wxString("Викладач") == studentOrTeacherRadioBox->GetString(event.GetSelection()))  choice = 't';
}


void StartWindow::signIn(wxCommandEvent& event)
{
    /*MainWindowTeacher* mainWinTeach = new MainWindowTeacher;
    mainWinTeach->Show(true);
    Close(true);*/

    bool result = false;

    if (choice == 's')
    {
        //Student S;
        result = S.signIn(loginField->GetValue().ToStdString(), passwordField->GetValue().ToStdString());
        S.setTestsList();
    }
    else
    {
        //Teacher T;
        result = T.signIn(loginField->GetValue().ToStdString(), passwordField->GetValue().ToStdString());
        T.setTestsList();
    }


    if (result && choice == 't')
    {
        MainWindowTeacher* mainWindowTeacher = new MainWindowTeacher;
        mainWindowTeacher->Show(true);
        Close(true);
    }
    else if (result && choice == 's')
    {
        MainWindowStudent* mainWindowStudent = new MainWindowStudent;
        mainWindowStudent->Show(true);
        Close(true);
    }
    else
    {
        if (choice == 's')
            S.~Student();
        else
            T.~Teacher();
        warningText->Show();
    }

    //char a = this->choice;
    //loginField->GetValue().ToStdString();
    //ADD LOG IN PROCEDURE HERE
    
}


void StartWindow::signUp(wxCommandEvent& event)
{
    SignUpWindow* signUpWin = new SignUpWindow;
    signUpWin->Show(true);

    Close(true);
}


SignUpWindow::SignUpWindow() : wxFrame(NULL, wxID_ANY, "Реєстрація", wxPoint(100, 100), wxSize(1280, 720))
{
    this->SetBackgroundColour(*wxWHITE);

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxStaticText* loginText = new wxStaticText(panel, wxID_ANY, "Логін", wxPoint(100, 75));
    wxStaticText* passwordText1 = new wxStaticText(panel, wxID_ANY, "Пароль", wxPoint(300, 75));
    wxStaticText* passwordText2 = new wxStaticText(panel, wxID_ANY, "Підтвердіть пароль", wxPoint(500, 75));

    loginField = new wxTextCtrl(panel, 1, "", wxPoint(100, 100));
    passwordField1 = new wxTextCtrl(panel, 2, "", wxPoint(300, 100), wxDefaultSize, wxTE_PASSWORD);
    passwordField2 = new wxTextCtrl(panel, 3, "", wxPoint(500, 100), wxDefaultSize, wxTE_PASSWORD);

    wxString choices[] = {"Студент", "Викладач"};
    studentOrTeacherRadioBox = new wxRadioBox(panel, 4, "", wxPoint(400, 150), wxDefaultSize, 2, choices);

    warningText = new wxStaticText(panel, wxID_ANY, "Помилка при реєстрації!", wxPoint(150, 125));
    warningText->Hide();

    wxButton* signUpButton = new wxButton(panel, wxID_ANY, wxT("Зареєструватися в системі"), wxPoint(180, 150));
    wxButton* goBackButton = new wxButton(panel, wxID_ANY, wxT("Повернутися назад"), wxPoint(200, 200));

    signUpButton->Bind(wxEVT_BUTTON, &SignUpWindow::signUp, this);
    goBackButton->Bind(wxEVT_BUTTON, &SignUpWindow::goBack, this);
    studentOrTeacherRadioBox->Bind(wxEVT_RADIOBOX, &SignUpWindow::saveChoice, this);
    
}


void SignUpWindow::saveChoice(wxCommandEvent& event)
{
    if (wxString("Студент") == studentOrTeacherRadioBox->GetString(event.GetSelection()))        choice = 's';
    else if (wxString("Викладач") == studentOrTeacherRadioBox->GetString(event.GetSelection()))  choice = 't';
}


void SignUpWindow::signUp(wxCommandEvent& event)
{
    //StartWindow* startWindow = new StartWindow;
    //startWindow->Show(true);
    //this->choice;
  

    bool result = false;

    if (choice == 's')
    {
        //Student S;
        result = S.signUp(loginField->GetValue().ToStdString(), passwordField1->GetValue().ToStdString(), passwordField2->GetValue().ToStdString());
        S.setTestsList();
    }
    else
    {
        //Teacher T;
        result = T.signUp(loginField->GetValue().ToStdString(), passwordField1->GetValue().ToStdString(), passwordField2->GetValue().ToStdString());
        T.setTestsList();
    }


    if (result && choice == 't')
    {
        MainWindowTeacher* mainWindowTeacher = new MainWindowTeacher;
        mainWindowTeacher->Show(true);
        Close(true);
    }
    else if (result && choice == 's')
    {
        MainWindowStudent* mainWindowStudent = new MainWindowStudent;
        mainWindowStudent->Show(true);
        Close(true);
    }
    else
    {
        warningText->Show();
    }

    //ADD SIGN UP PROCEDURE HERE
    //Close(true);
}


void SignUpWindow::goBack(wxCommandEvent& event)
{
    StartWindow* startWindow = new StartWindow;
    startWindow->Show(true);

    Close(true);
}



MainWindowTeacher::MainWindowTeacher() : wxFrame(NULL, wxID_ANY, "Тести", wxPoint(100, 100), wxSize(1280, 720))
{
    this->SetBackgroundColour(*wxWHITE);

    //СТВОРЮЄМО ПАНЕЛЬ ДЛЯ КНОПОК МЕНЮ
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    testsPanel = new wxScrolledWindow(panel, wxID_ANY,
        wxPoint(startButtonPanelCoordX - 10, startButtonPanelCoordY - 10),
        wxSize(415, 550));
    testsPanel->SetBackgroundColour(wxColour(211, 211, 211));
    testsPanel->EnableScrolling(false, true);
    //map<int, string> tests;


    /*ifstream F;
    F.open(T.getLogin() + ".txt", ifstream::app);

    getline(F, line);
    while (!F.eof())
    {
        getline(F, line);
        string delim(" ");
        size_t prev = 0;
        size_t next;
        size_t delta = delim.length();
        vector<string> arr;

        next = line.find(delim, prev);
        string tmp1 = line.substr(prev, next - prev);
        cout << tmp1 << ". ";
        //testsId.push_back(stoi(tmp));

        arr.push_back(line.substr(prev, next - prev));
        prev = next + delta;
        string tmp2 = line.substr(prev);
        cout << tmp2 << endl;

        int tmp3 = stoi(tmp1);
        tests.emplace(tmp3, tmp2);
        //testsTitle.push_back(tmp);
    }
    F.close();*/

    
    

    for (int i = 0; i < T.getTestsList().size(); i++)
    {
        wxButton* testButton = new wxButton(testsPanel, wxID_ANY, T.getTestsList().at(i).getTitle(),
            wxPoint(10, 10 + this->amountOfMenuButtons * 35), wxSize(375, 30));
        testButtons.push_back(testButton);
        testButton->SetId(i);
        testButton->Bind(wxEVT_BUTTON, &MainWindowTeacher::showMarks, this);
        this->amountOfMenuButtons++;
    }
    if (amountOfMenuButtons < 16)
    {
        testsPanel->SetSize(wxSize(395, 550));
    }
    testsPanel->SetScrollbars(0, 20, 0, (35 * amountOfMenuButtons + 10) / 20);

    sortButton = new wxButton(panel, wxID_ANY, "Сортувати за алфавітом",
        wxPoint(450, 60), wxSize(140, 30));

    sortButton->Bind(wxEVT_BUTTON, &MainWindowTeacher::sortTests, this);
    
    /*for (int i = 0; i < testButtons.size(); i++)
    {
        testButtons.at(i)->SetId(i);
        testButtons.at(i)->Bind(wxEVT_BUTTON, &MainWindowTeacher::showMarks, this);
    }*/
    
    wxStaticText* username = new wxStaticText(panel, wxID_ANY, T.getLogin(), wxPoint(770, 60));

    wxButton* createNewTestButton = new wxButton(panel, wxID_ANY, "Створити тест",
        wxPoint(600, 95), wxSize(375, 30));
    wxButton* logOutButton = new wxButton(panel, wxID_ANY, "Вийти",
        wxPoint(600, 130), wxSize(375, 30));

    createNewTestButton->Bind(wxEVT_BUTTON, &MainWindowTeacher::createNewTest, this);
    logOutButton->Bind(wxEVT_BUTTON, &MainWindowTeacher::logOut, this);
    //СТВОРЮЄМО КНОПКИ
    /*wxButton* seeAllTestsButton = new wxButton(panel, wxID_EXIT, wxT("Переглянути усі тести"),
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY + this->amountOfMenuButtons * 50));
    this->amountOfMenuButtons++;
    wxButton* seeAllYourResultsButton = new wxButton(panel, wxID_EXIT, wxT("Переглянути свої результати"),
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY + this->amountOfMenuButtons * 50));
    this->amountOfMenuButtons++;
    wxButton* seeAllTestResultsButton = new wxButton(panel, wxID_EXIT, wxT("Переглянути результати учнів"),
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY + this->amountOfMenuButtons * 50));
    this->amountOfMenuButtons++;
    wxButton* exitButton = new wxButton(panel, wxID_EXIT, wxT("Вийти"),
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY + this->amountOfMenuButtons * 50));;
    this->amountOfMenuButtons++;

    //ПРИВ'ЯЗУЄМО ФУНКЦІЇ ДО КНОПОК
    exitButton->Bind(wxEVT_BUTTON, &MainWindowTeacher::onExit, this);*/
}


void MainWindowTeacher::sortTests(wxCommandEvent& event)
{
    sortButton->Hide();
    T.sortTestsList();

    for (int i = 0; i < testButtons.size(); i++)
    {
        testButtons.at(i)->Destroy();
    }

    amountOfMenuButtons = 0;
    testButtons.clear();

    for (int i = 0; i < T.getTestsList().size(); i++)
    {
        wxButton* testButton = new wxButton(testsPanel, wxID_ANY, T.getTestsList().at(i).getTitle(),
            wxPoint(10, 10 + this->amountOfMenuButtons * 35), wxSize(375, 30));
        testButtons.push_back(testButton);
        testButton->SetId(i);
        testButton->Bind(wxEVT_BUTTON, &MainWindowTeacher::showMarks, this);
        this->amountOfMenuButtons++;
    }
}


void MainWindowTeacher::showMarks(wxCommandEvent& event)
{
    TestResultsWindow* testResultsWindow = new TestResultsWindow(event.GetId());
    testResultsWindow->Show(true);
    Close(true);
}


void MainWindowTeacher::logOut(wxCommandEvent& event)
{
    T.~Teacher();
    StartWindow* startWindow = new StartWindow;
    startWindow->Show(true);
    Close(true);
}


void MainWindowTeacher::createNewTest(wxCommandEvent& event)
{
    CreateTestWindow* createTestWindow = new CreateTestWindow;
    createTestWindow->Show(true);
    Close(true);
}


ShowMarksWindow::ShowMarksWindow() : wxFrame(NULL, wxID_ANY, "", wxPoint(100, 100), wxSize(1280, 720))
{
    this->SetBackgroundColour(*wxWHITE);
    this->SetTitle("Оцінки користувача " + S.getLogin());
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxScrolledWindow* resultsPanel = new wxScrolledWindow(panel, wxID_ANY,
        wxPoint(startButtonPanelCoordX - 10, startButtonPanelCoordY - 10),
        wxSize(350, 550));
    resultsPanel->SetBackgroundColour(wxColour(211, 211, 211));
    resultsPanel->EnableScrolling(false, true);

    wxStaticText* titleHeader = new wxStaticText(panel, wxID_ANY, "Тест", wxPoint(125, startButtonPanelCoordY - 30));
    wxStaticText* markHeader = new wxStaticText(panel, wxID_ANY, "Оцінка", wxPoint(250, startButtonPanelCoordY - 30));

    int j = 0;

    for (int i = 0; i < S.getTestsList().size(); i++)
    {
        ifstream F;

        string a = S.getTestsList().at(i).getResultsFile();
        F.open(S.getTestsList().at(i).getResultsFile(), ifstream::app);

        string line = "";

        while (getline(F, line))
        {
            string delim(" ");
            size_t prev = 0;
            size_t next;
            size_t delta = delim.length();

            next = line.find(delim, prev);
            if (line.substr(prev, next - prev) == S.getLogin())
            {
                wxStaticText* testTitleText = new wxStaticText(resultsPanel, wxID_ANY,
                    S.getTestsList().at(i).getTitle(), wxPoint(75, 10 + j * 25));

                prev = next + delta;

                wxStaticText* markText = new wxStaticText(resultsPanel, wxID_ANY, line.substr(prev), wxPoint(200, 10 + j * 25));

                j++;
            }
        }

        F.close();
    }

    resultsPanel->SetScrollbars(0, 20, 0, (25 * j + 10) / 20);

    wxButton* goBack = new wxButton(panel, wxID_ANY, "Назад", wxPoint(550, 50), wxSize(75, 30));
    goBack->Bind(wxEVT_BUTTON, &ShowMarksWindow::goBack, this);

}


void ShowMarksWindow::goBack(wxCommandEvent& event)
{
    MainWindowStudent* mainWindowStudent = new MainWindowStudent;
    mainWindowStudent->Show(true);

    Close(true);
}



TestResultsWindow::TestResultsWindow(int i) : wxFrame(NULL, wxID_ANY, "Журнал оцінок", wxPoint(100, 100), wxSize(1280, 720))
{
    this->SetBackgroundColour(*wxWHITE);

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxScrolledWindow* resultsPanel = new wxScrolledWindow(panel, wxID_ANY,
        wxPoint(startButtonPanelCoordX - 10, startButtonPanelCoordY - 10),
        wxSize(350, 550));
    resultsPanel->SetBackgroundColour(wxColour(211, 211, 211));
    resultsPanel->EnableScrolling(false, true);
    

    wxStaticText* loginHeader = new wxStaticText(panel, wxID_ANY, "Логін", wxPoint(125, startButtonPanelCoordY - 30));
    wxStaticText* resultHeader = new wxStaticText(panel, wxID_ANY, "Результат", wxPoint(250, startButtonPanelCoordY - 30));

    ifstream F;
    F.open(T.getTestsList()[i].getResultsFile(), ifstream::app);

    int j = 0;
    string line;
    while (getline(F, line))
    {
        string delim(" ");
        size_t prev = 0;
        size_t next;
        size_t delta = delim.length();

        next = line.find(delim, prev);

        wxStaticText* loginText = new wxStaticText(resultsPanel, wxID_ANY, line.substr(prev, next - prev), wxPoint(75, 10 + j * 25));

        prev = next + delta;

        wxStaticText* resultText = new wxStaticText(resultsPanel, wxID_ANY, line.substr(prev), wxPoint(200, 10 + j * 25));

        j++;
    }

    resultsPanel->SetScrollbars(0, 20, 0, (25 * j + 10) / 20);

    wxButton* goBack = new wxButton(panel, wxID_ANY, "Назад", wxPoint(550, 50), wxSize(75, 30));
    goBack->Bind(wxEVT_BUTTON, &TestResultsWindow::goBack, this);

    //wxStaticText* titleText = new wxStaticText(panel, wxID_ANY, to_string(choice), wxPoint(75, 75));
}


void TestResultsWindow::goBack(wxCommandEvent& event)
{
    MainWindowTeacher* mainWindowTeacher = new MainWindowTeacher;
    mainWindowTeacher->Show(true);

    Close(true);
}


CreateTestWindow::CreateTestWindow() : wxFrame(NULL, wxID_ANY, "Створити тест", wxPoint(100, 100), wxSize(1280, 720))
{
    this->SetBackgroundColour(*wxWHITE);

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    titleText = new wxStaticText(panel, wxID_ANY, "Введіть тему тесту: ", wxPoint(75, 75));
    title = new wxTextCtrl(panel, 1, "", wxPoint(200, 75), wxSize(250, 25));

    goToCreation = new wxButton(panel, wxID_ANY, "Далі", wxPoint(500, 75), wxSize(150, 30));
    goBackButton = new wxButton(panel, wxID_ANY, "Назад", wxPoint(675, 75), wxSize(75, 30));

    goToCreation->Bind(wxEVT_BUTTON, &CreateTestWindow::goToCreations, this);
    goBackButton->Bind(wxEVT_BUTTON, &CreateTestWindow::goBack, this);

    questionText = new wxStaticText(panel, wxID_ANY, "Введіть питання: ", wxPoint(75, 100));
    question = new wxTextCtrl(panel, 1, "", wxPoint(250, 100), wxSize(250, 25));

    questionText->Hide();
    question->Hide();

    newQuestionButton = new wxButton(panel, wxID_ANY, "Далі",
        wxPoint(520, 100), wxSize(50, 28));
    newQuestionButton->Hide();
    newQuestionButton->Bind(wxEVT_BUTTON, &CreateTestWindow::newQuestion, this);

    answersText = new wxStaticText(panel, wxID_ANY, "Введіть варіанти відповідей: ", wxPoint(75, 125));
    answer = new wxTextCtrl(panel, 1, "", wxPoint(250, 125), wxSize(250, 25));

    answersText->Hide();
    answer->Hide();

    newAnswerButton = new wxButton(panel, wxID_ANY, "+", wxPoint(520, 125), wxSize(50, 28));
    newAnswerButton->Hide();


    checkboxText = new wxStaticText(panel, wxID_ANY, "Оберіть якщо відповідь правильна (тільки один раз): ", wxPoint(75, 150));
    correctAnswerBox = new wxCheckBox(panel, wxID_ANY, "", wxPoint(370, 152));

    checkboxText->Hide();
    correctAnswerBox->Hide();


    newAnswerButton->Bind(wxEVT_BUTTON, &CreateTestWindow::newAnswer, this);


    finishTestButton = new wxButton(panel, wxID_ANY, "Завершити створення тесту", wxPoint(75, 170), wxSize(200, 28));
    finishTestButton->Hide();

    finishTestButton->Bind(wxEVT_BUTTON, &CreateTestWindow::finishTest, this);


    testPreview = new wxStaticText(panel, wxID_ANY, "", wxPoint(75, 200));
    testPreview->Hide();
    /*wxStaticText* loginText = new wxStaticText(panel, wxID_ANY, "Логін", wxPoint(100, 75));
    wxStaticText* passwordText1 = new wxStaticText(panel, wxID_ANY, "Пароль", wxPoint(300, 75));
    wxStaticText* passwordText2 = new wxStaticText(panel, wxID_ANY, "Підтвердіть пароль", wxPoint(500, 75));

    loginField = new wxTextCtrl(panel, 1, "", wxPoint(100, 100));
    passwordField1 = new wxTextCtrl(panel, 2, "", wxPoint(300, 100), wxDefaultSize, wxTE_PASSWORD);
    passwordField2 = new wxTextCtrl(panel, 3, "", wxPoint(500, 100), wxDefaultSize, wxTE_PASSWORD);

    wxString choices[] = { "Студент", "Викладач" };
    studentOrTeacherRadioBox = new wxRadioBox(panel, 4, "", wxPoint(400, 150), wxDefaultSize, 2, choices);

    warningText = new wxStaticText(panel, wxID_ANY, "Помилка при реєстрації!", wxPoint(150, 125));
    warningText->Hide();

    wxButton* signUpButton = new wxButton(panel, wxID_ANY, wxT("Зареєструватися в системі"), wxPoint(180, 150));
    wxButton* goBackButton = new wxButton(panel, wxID_ANY, wxT("Повернутися назад"), wxPoint(200, 200));

    signUpButton->Bind(wxEVT_BUTTON, &SignUpWindow::signUp, this);
    goBackButton->Bind(wxEVT_BUTTON, &SignUpWindow::goBack, this);
    studentOrTeacherRadioBox->Bind(wxEVT_RADIOBOX, &SignUpWindow::saveChoice, this);*/

}


void CreateTestWindow::goBack(wxCommandEvent& event)
{
    MainWindowTeacher* mainWindowTeacher = new MainWindowTeacher;
    mainWindowTeacher->Show(true);

    Close(true);
}


void CreateTestWindow::newQuestion(wxCommandEvent&)
{
    finishTestButton->Show();
    question->SetValue("");
    newQuestionButton->Hide();
    correctAnswerBox->Show();
    checkboxText->Show();

    amountOfQuestions++;
    answersCounter = 0;

    testPreview->SetLabel("Попередній перегляд питання:\n");
}


void CreateTestWindow::newAnswer(wxCommandEvent&)
{
    if (correctAnswerBox->GetValue())
    {
        answers.emplace(amountOfQuestions - 1, "+");
        answers.emplace(amountOfQuestions - 1, answer->GetValue().ToStdString());
    }
    else answers.emplace(amountOfQuestions - 1, answer->GetValue().ToStdString());
        
    if (answersCounter == 0)
    {
        if (correctAnswerBox->GetValue())
        {
            string oldText = testPreview->GetLabelText().ToStdString();
            questions.push_back(question->GetValue().ToStdString());
            testPreview->SetLabel(oldText + "Питання №" + to_string(amountOfQuestions) + ": " + question->GetValue().ToStdString() +
                "\nВідповіді:\n" + to_string(answersCounter + 1) + ") " + answer->GetValue().ToStdString() + " (Правильна відповідь)\n");
            correctAnswerBox->Hide();
            checkboxText->Hide();
            correctAnswerBox->SetValue(false);
        }
        else
        {
            string oldText = testPreview->GetLabelText().ToStdString();
            questions.push_back(question->GetValue().ToStdString());
            testPreview->SetLabel(oldText + "Питання №" + to_string(amountOfQuestions) + ": " + question->GetValue().ToStdString() +
                "\nВідповіді:\n" + to_string(answersCounter + 1) + ") " + answer->GetValue().ToStdString() + "\n");
        }
    }
    else
    {
        if (correctAnswerBox->GetValue())
        {
            string oldText = testPreview->GetLabelText().ToStdString();
            testPreview->SetLabel(oldText + to_string(answersCounter + 1) + ") " + answer->GetValue().ToStdString() + " (Правильна відповідь)\n");
            correctAnswerBox->Hide();
            checkboxText->Hide();
            correctAnswerBox->SetValue(false);
        }
        else
        {
            string oldText = testPreview->GetLabelText().ToStdString();
            testPreview->SetLabel(oldText + to_string(answersCounter + 1) + ") " + answer->GetValue().ToStdString() + "\n");
        }
        
    }
    if (answersCounter >= 1 && !question->GetValue().ToStdString().empty() && !correctAnswerBox->IsShown())
        newQuestionButton->Show();
    answersCounter++;
    answer->SetValue("");
}


void CreateTestWindow::goToCreations(wxCommandEvent& event)
{
    titleText->SetLabel("Тема: " + title->GetValue().ToStdString());
    title->Hide();
    goToCreation->Hide();
    goBackButton->Hide();

    questionText->Show();
    question->Show();

    answersText->Show();
    answer->Show();

    checkboxText->Show();
    correctAnswerBox->Show();

    newAnswerButton->Show();
    testPreview->Show();
    testPreview->SetLabel("Попередній перегляд питання:\n");
}


void CreateTestWindow::finishTest(wxCommandEvent& event)
{
    T.createTest(title->GetValue().ToStdString(), questions, answers);
    MainWindowTeacher* mainWindowTeacher = new MainWindowTeacher;
    mainWindowTeacher->Show(true);
    Close(true);
}


void MainWindowTeacher::onExit(wxCommandEvent& exit)
{
    wxPuts("Вихід");
    Close(true);
}



MainWindowStudent::MainWindowStudent() : wxFrame(NULL, wxID_ANY, "Тести", wxPoint(100, 100), wxSize(1280, 720))
{
    this->SetBackgroundColour(*wxWHITE);

    //СТВОРЮЄМО ПАНЕЛЬ ДЛЯ КНОПОК МЕНЮ
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    
    searchBox = new wxTextCtrl(panel, wxID_ANY, "",
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY),
        wxSize(275, 25));

    wxButton* searchButton = new wxButton(panel, wxID_ANY, "Пошук",
        wxPoint(startButtonPanelCoordX + 280, startButtonPanelCoordY) , wxSize(95, 25));

    searchButton->Bind(wxEVT_BUTTON, &MainWindowStudent::search, this);

    testsPanel = new wxScrolledWindow(panel, wxID_ANY,
        wxPoint(startButtonPanelCoordX - 10, startButtonPanelCoordY + 35),
        wxSize(415, 505));
    testsPanel->SetBackgroundColour(wxColour(211, 211, 211));
    testsPanel->EnableScrolling(false, true);
    

    //СТВОРЮЄМО КНОПКИ 
    for (int i = 0; i < S.getTestsList().size(); i++)
    {
        wxButton* testButton = new wxButton(testsPanel, wxID_ANY, S.getTestsList().at(i).getTitle(),
            wxPoint(10, 10 + this->amountOfMenuButtons * 35), wxSize(375, 30));
        testButtons.push_back(testButton);
        testButton->SetId(i);
        testButton->Bind(wxEVT_BUTTON, &MainWindowStudent::startTest, this);
        this->amountOfMenuButtons++;
    }

    

    if (amountOfMenuButtons < 14)
    {
        testsPanel->SetSize(wxSize(395, 505));
    }

    testsPanel->SetScrollbars(0, 20, 0, (35 * amountOfMenuButtons + 15) / 20);

    sortButton = new wxButton(panel, wxID_ANY, "Сортувати за алфавітом",
        wxPoint(450, 60), wxSize(140, 30));

    sortButton->Bind(wxEVT_BUTTON, &MainWindowStudent::sortTests, this);

    wxStaticText* username = new wxStaticText(panel, wxID_ANY, S.getLogin(), wxPoint(770, 60));

    wxButton* showMarksButton = new wxButton(panel, wxID_ANY, "Переглянути свої оцінки",
        wxPoint(600, 95), wxSize(375, 30));

    wxButton* logOutButton = new wxButton(panel, wxID_ANY, "Вийти",
        wxPoint(600, 130), wxSize(375, 30));

    showMarksButton->Bind(wxEVT_BUTTON, &MainWindowStudent::showMarks, this);

    logOutButton->Bind(wxEVT_BUTTON, &MainWindowStudent::logOut, this);    
}


void MainWindowStudent::search(wxCommandEvent&)
{
    S.modTestsList(S.searchTests(searchBox->GetValue().ToStdString()));
    sortButton->Hide();

    for (int i = 0; i < testButtons.size(); i++)
    {
        testButtons.at(i)->Destroy();
    }

    amountOfMenuButtons = 0;
    testButtons.clear();

    for (int i = 0; i < S.getTestsList().size(); i++)
    {
        wxButton* testButton = new wxButton(testsPanel, wxID_ANY, S.getTestsList().at(i).getTitle(),
            wxPoint(10, 10 + this->amountOfMenuButtons * 35), wxSize(375, 30));
        testButtons.push_back(testButton);
        testButton->SetId(i);
        testButton->Bind(wxEVT_BUTTON, &MainWindowStudent::startTest, this);
        this->amountOfMenuButtons++;
    }
}


void MainWindowStudent::sortTests(wxCommandEvent& event)
{
    sortButton->Hide();
    S.sortTestsList();

    for (int i = 0; i < testButtons.size(); i++)
    {
        testButtons.at(i)->Destroy();
    }

    amountOfMenuButtons = 0;
    testButtons.clear();

    for (int i = 0; i < S.getTestsList().size(); i++)
    {
        wxButton* testButton = new wxButton(testsPanel, wxID_ANY, S.getTestsList().at(i).getTitle(),
            wxPoint(10, 10 + this->amountOfMenuButtons * 35), wxSize(375, 30));
        testButtons.push_back(testButton);
        testButton->SetId(i);
        testButton->Bind(wxEVT_BUTTON, &MainWindowStudent::startTest, this);
        this->amountOfMenuButtons++;
    }
}


void MainWindowStudent::startTest(wxCommandEvent& event)
{
    TestWindow* testWindow = new TestWindow(event.GetId());
    testWindow->Show(true);
    Close(true);
}


void MainWindowStudent::showMarks(wxCommandEvent& event)
{
    ShowMarksWindow* showMarksWindow = new ShowMarksWindow;
    showMarksWindow->Show(true);
    Close(true);
}


void MainWindowStudent::logOut(wxCommandEvent& event)
{
    S.~Student();
    StartWindow* startWindow = new StartWindow;
    startWindow->Show(true);
    Close(true);
}


void MainWindowStudent::onExit(wxCommandEvent& exit)
{
    wxPuts("Exit");
    Close(true);
}


bool containsInterface(char s, vector<string> str)
{
    for (int i = 0; i < str.size(); i++)
        if (s == str[i][0])
            return true;

    return false;
}



TestWindow::TestWindow(int testId) : wxFrame(NULL, wxID_ANY, "", wxPoint(100, 100), wxSize(1280, 720))
{
    this->SetBackgroundColour(*wxWHITE);
    this->SetTitle("Тест на тему: " + S.getTestsList().at(testId).getTitle());
    //СТВОРЮЄМО ПАНЕЛЬ ДЛЯ КНОПОК МЕНЮ
    panel = new wxPanel(this, wxID_ANY);
    
    test = S.getTestsList().at(testId);
    
    title = new wxStaticText(panel, wxID_ANY, "Тема: " + test.getTitle(),
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY));

    creationDate = new wxStaticText(panel, wxID_ANY,
        "Дата створення: " + to_string(test.getCreationDate().getDay()) + "." + to_string(test.getCreationDate().getMonth()) + "."
         + to_string(test.getCreationDate().getYear()),
        wxPoint(startButtonPanelCoordX + 300, startButtonPanelCoordY));
    

    string line;
    

    ifstream F;
    
    F.open(test.getTasksFile(), ifstream::app);

    vector<string> numbers = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

    getline(F, line);
    getline(F, line);
    getline(F, line);
    int numberOfQuestions = 0;
    while (!F.eof())
    {
        getline(F, line);
        questions.push_back(line);

        
        while (getline(F, line))
        {
            if (!containsInterface(line[0], numbers))
            {
                variants.emplace(numberOfQuestions, line);
            }
            else
            {
                numberOfQuestions++;
                break;
            }
        }
    }


    for (multimap<int, string>::iterator itr = variants.begin(); itr != variants.end(); ++itr) 
    {
        if (itr->first == questionCounter && itr->second != "+")
        {
            answers.push_back(itr->second);
        }
    }

    for (multimap<int, string>::iterator itr = variants.begin(); itr != variants.end(); ++itr)
    {
        if (itr->first == questionCounter)
        {
            if (itr->second == "+")
            {
                itr++;
                correctAnswer = itr->second;
            }
        } 
    }

    pageCount = new wxStaticText(panel, wxID_ANY, "Завдання " + to_string(questionCounter + 1) + " з " + to_string(questions.size()),
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY + 20));

    question = new wxStaticText(panel, wxID_ANY, questions.at(questionCounter),
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY + 40));

    
    for (int i = 0; i < answers.size(); i++)
    {
        choices[i] = answers.at(i);
    }

    answersRadioBox = new wxRadioBox(panel, wxID_ANY, "", wxPoint(60, 115), wxDefaultSize, answers.size(), choices, 0, wxVERTICAL);

    /*answersRadioBox = new wxRadioBox(panel, 4, "", wxPoint(40, 115), wxDefaultSize,
        answers.size(), choices, 0);*/

    nextQuestionButton = new wxButton(panel, wxID_ANY, "Наступне питання",
        wxPoint(startButtonPanelCoordX + 130, startButtonPanelCoordY), wxSize(150, 30));

    nextQuestionButton->Bind(wxEVT_BUTTON, &TestWindow::nextQuestion, this);

    finishTestButton = new wxButton(panel, wxID_ANY, "Завершити тест",
        wxPoint(startButtonPanelCoordX + 130, startButtonPanelCoordY), wxSize(150, 30));
    finishTestButton->Hide();

    finishTestButton->Bind(wxEVT_BUTTON, &TestWindow::finishTest, this);
}


void TestWindow::nextQuestion(wxCommandEvent& event)
{
    if (correctAnswer == answersRadioBox->GetString(answersRadioBox->GetSelection()))
        amountOfCorrectAnswers++;

    answers.clear();
    if (questionCounter + 1 < questions.size())
    {
        creationDate->Hide();
        answersRadioBox->~wxRadioBox();
        questionCounter++;
        question->SetLabel(questions.at(questionCounter));

        for (multimap<int, string>::iterator itr = variants.begin(); itr != variants.end(); ++itr)
        {
            if (itr->first == questionCounter && itr->second != "+")
            {
                answers.push_back(itr->second);
            }
        }

        for (multimap<int, string>::iterator itr = variants.begin(); itr != variants.end(); ++itr)
        {
            if (itr->first == questionCounter)
            {
                if (itr->second == "+")
                {
                    itr++;
                    correctAnswer = itr->second;
                }
            }
        }
        for (int j = 0; j < answers.size(); j++)
        {
            choices[j] = answers.at(j);
            //answersRadioBox->SetString(j, answers.at(j));
        }

        pageCount->SetLabel("Завдання " + to_string(questionCounter + 1) + " з " + to_string(questions.size()));

        answersRadioBox = new wxRadioBox(panel, wxID_ANY, "", wxPoint(60, 115), wxDefaultSize, answers.size(), choices, 0, wxVERTICAL);
    }
    else
    {
        answersRadioBox->Enable(false);
        nextQuestionButton->Hide();
        finishTestButton->Show();
    }
}
 

void TestWindow::finishTest(wxCommandEvent&)
{
    title->Hide();
    question->Hide();
    answersRadioBox->Hide();
    pageCount->Hide();
    finishTestButton->Hide();

    wxStaticText* result = new wxStaticText(panel, wxID_ANY,
        "Ваш результат: " + to_string((amountOfCorrectAnswers * 10) / questions.size()) + " з 10",
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY));
    test.saveResults(S.getLogin(), (amountOfCorrectAnswers * 10) / questions.size());

    wxButton* goToHomeButton = new wxButton(panel, wxID_ANY, "Повернутися на головну сторінку",
        wxPoint(startButtonPanelCoordX, startButtonPanelCoordY + 25), wxSize(300, 30));

    goToHomeButton->Bind(wxEVT_BUTTON, &TestWindow::goToHome, this);
}


void TestWindow::goToHome(wxCommandEvent&)
{
    S.setTestsList();
    MainWindowStudent* mainWindowStudent = new MainWindowStudent;
    mainWindowStudent->Show(true);
    Close(true);
}
