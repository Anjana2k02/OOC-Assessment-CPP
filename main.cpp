#include <iostream> // for cout
#include <cstring> // for strcpy

#define SIZE 2
using namespace std;
class User;
class Employee;
class Exam;
class Exam_Provider;
class FAQ;
class Message;
class Notice;
class Report;
class Result;
class Support_Staff;
class System_Admin;
class Admin;
// user class
class User
{
protected:
    char email[50];
    char password[30];
    char name[50];

public:
    User();
    User(const char *uemail, const char *pwd, const char *uname);
    void display();
    void login();
    void viewWebsite();
    ~User();
};
User::User()
{
    strcpy(email, "");
    strcpy(password, "");
    strcpy(name, "");
}

User::User(const char *uemail, const char *pwd, const char *uname)
{
    strcpy(email, uemail);
    strcpy(password, pwd);
    strcpy(name, uname);
}
void User::display()
{
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
    cout << "Name: " << name << endl;
}
void User::login()
{
}
void User::viewWebsite()
{
}
User::~User()
{
}
// Employee class
class Employee : public User
{
private:
    char employee_ID[10];
    char dob[10];
    char phoneNo[20];
    Exam *exams[SIZE];
    Result *results[SIZE];
    Notice *notices[SIZE];
    Message *message[SIZE];
    FAQ *faqs[SIZE];

public:
    Employee();
    Employee(const char *eemail, const char *epwd, const char *ename, const char *eID, const char *edob, const char *ephoneNo);
    void display();
    void attemptExam();
    void viewResult();
    void checkNotice();
    void sendMessage();
    void checkFAQ();
    ~Employee();
};

Employee::Employee()
{
    strcpy(employee_ID, "");
    strcpy(dob, "");
    strcpy(phoneNo, "");
}
Employee::Employee(const char *eemail, const char *epwd, const char *ename, const char *eID, const char *edob, const char *ephoneNo)
    : User(eemail, epwd, ename)
{
    strcpy(employee_ID, eID);
    strcpy(dob, edob);
    strcpy(phoneNo, ephoneNo);
}
void Employee::display()
{
    User::display();
    cout << "Employee ID : " << employee_ID << endl;
    cout << "DOB : " << dob << endl;
    cout << "Phone No : " << phoneNo << endl;
}
void Employee::attemptExam()
{
}
void Employee::viewResult()
{
}
void Employee::checkNotice()
{
}
void Employee::sendMessage()
{
}
void Employee::checkFAQ()
{
}
Employee::~Employee()
{
}
// FAQ class
class FAQ
{
private:
    char FAQ_ID[10];
    char question[200];
    char answer[200];
    Support_Staff *supportstaffs;

public:
    FAQ();
    FAQ(const char *faqid, const char *ques, const char *ans);
    void storeFAQDetails();
    void displayFAQ();
    ~FAQ();
};
FAQ::FAQ()
{
    strcpy(FAQ_ID, "");
    strcpy(question, "");
    strcpy(answer, "");
}
FAQ::FAQ(const char *faqid, const char *ques, const char *ans)
{
    strcpy(FAQ_ID, faqid);
    strcpy(question, ques);
    strcpy(answer, ans);
}

void FAQ::storeFAQDetails()
{
}
void FAQ::displayFAQ()
{
    cout << "FAQ ID: " << FAQ_ID << endl;
    cout << question << endl;
    cout << answer << endl;
}
FAQ::~FAQ()
{
}
// support staff class
class Support_Staff : public User
{
private:
    char supportStaff_ID[10];
    char phoneNo[20];
    FAQ *faqs[SIZE];
    Message *msg[SIZE];

public:
    Support_Staff();
    Support_Staff(const char *ssemail, const char *sspwd, const char *ssname, const char *ssID, const char *ssphoneNo);
    void display();
    void replyMessages();
    void manageFAQ();
    ~Support_Staff();
};
Support_Staff::Support_Staff()
{
    strcpy(supportStaff_ID, "");
    strcpy(phoneNo, "");
}

Support_Staff::Support_Staff(const char *ssemail, const char *sspwd, const char *ssname, const char *ssID, const char *ssphoneNo)
    : User(ssemail, sspwd, ssname)
{
    strcpy(supportStaff_ID, ssID);
    strcpy(phoneNo, ssphoneNo);
}
void Support_Staff::display()
{
    User::display();
    cout << "Support Staff ID: " << supportStaff_ID << endl;
    cout << "Support Staff Phone No: " << phoneNo << endl;
}
void Support_Staff::replyMessages()
{
}
void Support_Staff::manageFAQ()
{
}
Support_Staff::~Support_Staff()
{
}
// message class
class Message
{
private:
    char message_ID[10];
    char description[200];

public:
    Message();
    Message(const char *faqid, const char *desc);
    void storeMessages();
    void displayMessage();
    ~Message();
};

Message::Message()
{
    strcpy(message_ID, "");
    strcpy(description, "");
}
Message::Message(const char *messageid, const char *desc)
{
    strcpy(message_ID, messageid);
    strcpy(description, desc);
}
void Message::storeMessages()
{
}
void Message::displayMessage()
{
    cout << "Message ID: " << message_ID << endl;
    cout << description << endl;
}
Message::~Message()
{
}
// notice class
class Notice
{
private:
    char notice_ID[10];
    char description[200];

public:
    Notice();
    Notice(const char *id, const char *desc);
    void storeNotices();
    void displayNotice();
    ~Notice();
};
Notice::Notice()
{
    strcpy(notice_ID, "");
    strcpy(description, "");
}

Notice::Notice(const char *noticeid, const char *desc)
{
    strcpy(notice_ID, noticeid);
    strcpy(description, desc);
}
void Notice::storeNotices()
{
}
void Notice::displayNotice()
{
    cout << "Notice ID: " << notice_ID << endl;
    cout << description << endl;
}
Notice::~Notice()
{
}
// admin class
class Admin : public User
{
private:
    char admin_ID[10];
    Employee *employees[SIZE];
    Notice *notices2[SIZE];
    Support_Staff *supportstaff2[SIZE];
    Report *reports[SIZE];
    Exam_Provider *examproviders[SIZE];
    System_Admin *sydtemadmins[SIZE];

public:
    Admin();
    Admin(const char *aemail, const char *apwd, const char *aname, const char *aID);
    void display();
    void manageNotice();
    void manageAccount();
    void generateReport();
    ~Admin();
};
Admin::Admin()
{
    strcpy(admin_ID, "");
}
Admin::Admin(const char *aemail, const char *apwd, const char *aname, const char *aID)
    : User(aemail, apwd, aname)
{
    strcpy(admin_ID, aID);
}
void Admin::display()
{
    User::display();
    cout << " Admin ID : " << admin_ID << endl;
}
void Admin::manageNotice()
{
}
void Admin::manageAccount()
{
}
void Admin::generateReport()
{
}
Admin::~Admin()
{
}
// report class
class Report
{
private:
    char report_ID[10];
    Result *results[SIZE];
    Exam *exams[SIZE];

public:
    Report();
    Report(const char *reportid);
    void examReport();
    void ResultReport();
    ~Report();
};

Report::Report()
{
    strcpy(report_ID, "");
}
Report::Report(const char *reportid)
{
    strcpy(report_ID, reportid);
}
void Report::examReport()
{
}
void Report::ResultReport()
{
}
Report::~Report()
{
}
// exam provider class
class Exam_Provider : public User
{
private:
    char examProvider_ID[10];
    char phoneNo[20];
    Exam *exams[SIZE];
    Result *results[SIZE];

public:
    Exam_Provider();
    Exam_Provider(const char *epemail, const char *eppwd, const char *epname, const char *epID, const char *epphoneNo);
    void display();
    void manageExam();
    void publishResult();
    ~Exam_Provider();
};

Exam_Provider::Exam_Provider()
{
    strcpy(examProvider_ID, "");
    strcpy(phoneNo, "");
}
Exam_Provider::Exam_Provider(const char *epemail, const char *eppwd, const char *epname, const char *epID, const char *epphoneNo)
    : User(epemail, eppwd, epname)
{
    strcpy(examProvider_ID, epID);
    strcpy(phoneNo, epphoneNo);
}
void Exam_Provider::display()
{
    User::display();
    cout << "Exam Provider ID : " << examProvider_ID << endl;
    cout << "Phone No : " << phoneNo << endl;
}
void Exam_Provider::manageExam()
{
}
void Exam_Provider::publishResult()
{
}
Exam_Provider::~Exam_Provider()
{
}
// system admin class
class System_Admin : public User
{
private:
    char systemAdmin_ID[10];
    char phoneNo[20];

public:
    System_Admin();
    System_Admin(const char *SAemail, const char *SApwd, const char *SAname, const char *SAID, const char *SAphoneNo);
    void display();
    ~System_Admin();
};
System_Admin::System_Admin()
{
    strcpy(systemAdmin_ID, "");
    strcpy(phoneNo, "");
}
System_Admin::System_Admin(const char *SAemail, const char *SApwd,
                           const char *SAname, const char *SAID, const char *SAphoneNo)
    : User(SAemail, SApwd, SAname)
{
    strcpy(systemAdmin_ID, SAID);
    strcpy(phoneNo, SAphoneNo);
}
void System_Admin::display()
{
    User::display();
    cout << "System Admin ID : " << systemAdmin_ID << endl;
    cout << "Phone No : " << phoneNo << endl;
}
System_Admin::~System_Admin()
{
}
// Result class
class Result
{
private:
    char result_ID[10];
    Employee *employee;
    Exam_Provider *examProvider;

public:
    Result();
    Result(const char *resultid);
    void storeExamResults();
    void displayResult();
    ~Result();
};

Result::Result()
{
    strcpy(result_ID, "");
}
Result::Result(const char *resultid)
{
    strcpy(result_ID, resultid);
}
void Result::storeExamResults()
{
}
void Result::displayResult()
{
    cout << "Result ID: " << result_ID << endl;
}
Result::~Result()
{
}
// exam Class
class Exam
{
private:
    char exam_ID[10];
    Employee *employee[SIZE];
    Exam_Provider *examProvider;
    Result *results[SIZE];

public:
    Exam();
    Exam(const char *examid);
    void storeExamDetails();
    void addExamResult(const char *resultid);
    void displayExamResult();
    void DisplayExamDetails();
    ~Exam();
};
Exam::Exam()
{
    strcpy(exam_ID, "EX0024");
}
Exam::Exam(const char *examid)
{
    strcpy(exam_ID, examid);
}
void Exam::storeExamDetails()
{
}
void Exam::addExamResult(const char *resultid)
{
    results[0] = new Result(resultid);
}
void Exam::displayExamResult()
{
    cout << "Exam ID: " << exam_ID << endl;
    results[0]->displayResult();
}
void Exam::DisplayExamDetails()
{
}
Exam::~Exam()
{
    for (int i = 0; i < SIZE; i++)
    {
        delete results[i];
    }
}
// main
int main()
{
    cout << "**********//Employee//**********" << endl
         << endl;
    Employee *employee = new Employee("em223441@gmail.com",
                                      "BlueKite@123", "John Doe", "em223441", "1980-01-01",
                                      "0745678904");
    employee->display();
    cout << "**********//Exam_Provider//**********" << endl
         << endl;
    Exam_Provider *examProvider = new Exam_Provider("ep190011@gmail.com'", "bk@321", "Dahami Kaveesha",
                                                    "ep190011", "0776543210");
    examProvider->display();
    cout << "**********//Support_Staff//**********" << endl
         << endl;
Support_Staff* supportStaff = new
Support_Staff("ss199595@gmail.com", "A234@32", "Maleesha
Thennakoan", "ss199595", "0742563844");
supportStaff->display();
cout << "**********//System_Admin//**********" << endl <<
endl;
System_Admin* systemAdmin = new
System_Admin("sa220010@gmail.com", "SA34@22", "Anjana Indunil",
"sa220010", "0745484632");
systemAdmin->display();
cout << "**********//Admin//**********" << endl << endl;
Admin* admin = new Admin("adminpradeep@gmail.com",
"Admin@123", "Pradeep Rathnayake", "AD220458");
admin->display();
cout << "**********//Notice//**********" << endl << endl;
Notice* notice = new Notice("N001", "Exam Schedule");
notice->displayNotice();
cout << "**********//FAQ//**********" << endl << endl;
FAQ* faq = new FAQ("FAQ001", "Can employees get exam results
in fast?", "Yes");
faq->displayFAQ();
cout << "**********//Message//**********" << endl << endl;
Message* message = new Message("MS12001", "Upadate the exam
as soon as possible");
message->displayMessage();
cout << "**********//Exam//**********" << endl << endl;
Exam* exam;
exam = new Exam;
exam->addExamResult("RS0055");
exam->displayExamResult();
cout << "**********//Result//**********" << endl << endl;
Result* result = new Result("RS15001");
result->displayResult();
cout << "**********//thank you!//**********" << endl << endl;
delete employee;
delete examProvider;
delete supportStaff;
delete systemAdmin;
delete admin;
delete notice;
delete faq;
delete message;
delete exam;
delete result;
return 0;
}
