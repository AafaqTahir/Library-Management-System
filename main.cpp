#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<process.h>
#include <stdlib.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;
bool stringCompare(string,string);
void DataBase();
class Books
{
    string Title;
    string Author;
    int YearOfPublication;
    string LibraryCode;
    string ISBN;
    string Catogery;
    string Status;
    string AccountNumberOfUser;
    int issuedDate[3];
    int ReturnDate[3];
public:

    Books()
    {
        Title="";
        Author="";
        LibraryCode="";
        ISBN="";
        Catogery="";
        Status="";
        AccountNumberOfUser="";
        YearOfPublication=0;
        issuedDate[0]=issuedDate[1]=issuedDate[2]=ReturnDate[0]=ReturnDate[1]=ReturnDate[2]=0;
    }
    Books(string t, string a, int y, string l, string i, string c, string s, string ac,int *isuedate, int *rtrndate)
    {
        Title = t;
        Author = a;
        LibraryCode = l;
        ISBN = i;
        Catogery = c;
        Status = s;
        AccountNumberOfUser=ac;
        YearOfPublication=y;
        for(int i=0; i<3; i++)
        {
            issuedDate[i]= *(isuedate+i);
            ReturnDate[i] = *(rtrndate+i);
        }
    }
    string GetTitle()
    {
        return Title;
    }
    void SetTitle(string val)
    {
        Title = val;
    }
    string GetAuthor()
    {
        return Author;
    }
    void SetAuthor(string val)
    {
        Author = val;
    }
    string GetLibraryCode()
    {
        return LibraryCode;
    }
    void SetLibraryCode(string val)
    {
        LibraryCode = val;
    }
    string GetISBN()
    {
        return ISBN;
    }
    void SetISBN(string val)
    {
        ISBN = val;
    }
    string GetCatogery()
    {
        return Catogery;
    }
    void SetCatogery(string val)
    {
        Catogery = val;
    }
    string GetStatus()
    {
        return Status;
    }
    void SetStatus(string val)
    {
        Status = val;
    }
    string GetAccountNumberOfUser()
    {
        return AccountNumberOfUser;
    }
    void SetAccountNumberOfUser(string val)
    {
        AccountNumberOfUser = val;
    }
    int GetYearOfPublication()
    {
        return YearOfPublication;
    }
    void SetYearOfPublication(int val)
    {
        YearOfPublication = val;
    }
    void SetIssuedDate(int *ptr)
    {
        for(int i=0; i<3; i++)
        {
            issuedDate[i]= *(ptr+i);
        }
    }
    int *GetIssuedDate()
    {
        return issuedDate;
    }
    void SetReturnDate(int *ptr)
    {
        for(int i=0; i<3; i++)
        {
            ReturnDate[i]= *(ptr+i);
        }
    }
    void SetBookBackToDefault()
    {
        AccountNumberOfUser = "";
        Status = "Available";
        int arr[3]= {0,0,0};
        SetIssuedDate(arr);
        SetReturnDate(arr);

    }
    int *GetReturnDate()
    {
        return ReturnDate;
    }
    void displayBook()
    {
        cout << "Title                                   " << Title << endl;
        cout << "Author                                  " << Author << endl;
        cout << "Year of Publication                     " << YearOfPublication << endl;
        cout << "Library Code                            " << LibraryCode << endl;
        cout << "International Standard Book Number      " << ISBN << endl;
        cout << "Category                                " << Catogery << endl;
        cout << "Status                                  " << Status << endl;
    }
} ListOfAllBooks[20]; //
int CounterForBooks = 0;
class AllUserS          // (student,teacher and staff)
{
    string name;
    string ID;
    string AccountNumber;
    const int MaxIssuedBooks;
    int CurrentIssuedBooks;
protected:
    //AllUserS() : MaxIssuedBooks(0){}
    AllUserS(string n="", string i="", string Ac="", int MIB=0, int CIB=0) : MaxIssuedBooks(MIB)
    {
        name = n;
        ID = i;
        AccountNumber = Ac;
        CurrentIssuedBooks = CIB;
    }
    void CheckStatusOfBook(string str)
    {
        if(ListOfAllBooks[0].GetYearOfPublication() == 0)
        {
            cout << "No Record To Display " << endl;
        }
        else
        {
            for(int i=0; i<CounterForBooks; i++)
            {
                if(stringCompare(ListOfAllBooks[i].GetTitle(),str))
                {
                    cout << "Status      " << ListOfAllBooks[i].GetStatus() << endl;
                    break;
                }
            }
        }
    }
    void searchBookByCatogery(string str)
    {
        if(ListOfAllBooks[0].GetYearOfPublication() == 0)
        {
            cout << "No Record Display" << endl;
        }
        else
        {
            bool flag = false;
            for(int i=0; i<CounterForBooks; i++)
            {
                if(ListOfAllBooks[i].GetYearOfPublication() != 0)
                {
                    if(stringCompare(ListOfAllBooks[i].GetCatogery(),str))
                    {
                        ListOfAllBooks[i].displayBook();
                        flag = true;
                    }
                }
            }
            if(!flag)
            {
                cout << "No Book of this category is avalible " << endl;
            }
        }
    }
    void DisplayAllBooks()
    {
        for(int i=0; i<CounterForBooks; i++)
        {
            ListOfAllBooks[i].displayBook();
            cout << "\n********************************************\n";
        }
    }
    void ReturnABook(string BookName)
    {
        for(int i=0; i<CounterForBooks; i++)
        {
            if (stringCompare(ListOfAllBooks[i].GetAccountNumberOfUser(),AccountNumber))
            {
                if(stringCompare(ListOfAllBooks[i].GetTitle(),BookName))
                {
                    cout << "Book is Return" << endl;
                    ListOfAllBooks[i].SetBookBackToDefault();
                }
            }
        }
    }
    void searchABookByItsName( string bookname)
    {
        for ( int i=0; i< CounterForBooks ; i++)
        {
            if ( stringCompare( ListOfAllBooks[i].GetTitle(), bookname ))
            {
                ListOfAllBooks[i].displayBook();
            }
        }
    }
    virtual void DisplayInfo () = 0;
    void IssueABook(string BookName)
    {
        if(CurrentIssuedBooks < MaxIssuedBooks)
        {
            for(int i=0; i<CounterForBooks; i++)
            {
                if(stringCompare(ListOfAllBooks[i].GetTitle(),BookName))
                {

                    if(stringCompare(ListOfAllBooks[i].GetStatus(),"available"))
                    {
                        ListOfAllBooks[i].SetStatus("Issued");
                        ListOfAllBooks[i].SetAccountNumberOfUser(AccountNumber);
                        cout << "\tEnter Date " << endl;
                        int a[3];
                        cout << "\nDay   ";
                        cin >> a[0];
                        cout << "Month  ";
                        cin >> a[1];
                        cout << "Year   ";
                        cin >> a[2];
                        ListOfAllBooks[i].SetIssuedDate(a);
                        int d=a[0],m=a[1];
                        int rd = 0,rm = 0,ry = 0;
                        if (d + 7 > 30)
                        {
                            rm = (d+7) - 30;
                            if (m < 11)
                                rm++;
                            else
                            {
                                rm = 1;
                                ry++;
                            }
                        }
                        int b[3];
                        b[0]=rd;
                        b[1]=rm;
                        b[2]=ry;
                        ListOfAllBooks[i].SetReturnDate(b);
                        cout << "The Book Is Issued SuccessFully" << endl;
                        system("CLS");
                    }
                }
            }
        }
    }
public:
    string Getname()
    {
        return name;
    }
    void Setname(string val)
    {
        name = val;
    }
    string GetID()
    {
        return ID;
    }
    void SetID(string val)
    {
        ID = val;
    }
    string GetAccountNumber()
    {
        return AccountNumber;
    }
    void SetAccountNumber(string val)
    {
        AccountNumber = val;
    }
    int GetCurrentIssuedBooks()
    {
        return CurrentIssuedBooks;
    }
    void SetCurrentIssuedBooks(int val)
    {
        CurrentIssuedBooks = val;
    }
};
class Student : public AllUserS
{
public:
    Student(string n="", string i="", string ac=""):AllUserS(n,i,ac,3,0) {}

    void searchBooksByCategory(string str)
    {
        AllUserS::searchBookByCatogery(str);
    }
    void searchABookByName(string str)
    {
        AllUserS::searchABookByItsName(str);
    }

    void CheckStatusOAnyfBook(string str)
    {
        AllUserS::CheckStatusOfBook(str);
    }
    void ReturnBook(string BookName)
    {
        AllUserS::ReturnABook(BookName);
    }
    void IsueABook(string bookName)
    {
        AllUserS::IssueABook(bookName);
    }
    void DisplayInfo()
    {
        for(int i=0; i<CounterForBooks; i++)
        {
            if(stringCompare(ListOfAllBooks[i].GetAccountNumberOfUser(), GetAccountNumber()))
            {
                ListOfAllBooks[i].displayBook();
            }
        }
    }
    void operator = (Student &stu1)
    {
        Setname(stu1.Getname());
        SetID(stu1.GetID());
        SetAccountNumber(stu1.GetAccountNumber());
    }
} STUDENTS[10];
int counterForStudent=0;
class Teacher : public AllUserS
{
public:
    Teacher(string n="", string i="", string ac=""):AllUserS(n,i,ac,10,0) {}
    void searchBooksByCategory(string str)
    {
        AllUserS::searchBookByCatogery(str);
    }
    void CheckStatusOAnyfBook(string str)
    {
        AllUserS::CheckStatusOfBook(str);
    }
    void IsueABook(string bookName)
    {

        AllUserS::IssueABook(bookName);

    }
    void ReturnBook(string BookName)
    {
        AllUserS::ReturnABook(BookName);
    }
    void DisplayInfo()
    {
        for(int i=0; i<CounterForBooks; i++)
        {
            if(stringCompare(ListOfAllBooks[i].GetAccountNumberOfUser(), GetAccountNumber()))
            {
                ListOfAllBooks[i].displayBook();
            }
        }
    }
    void operator = (Teacher &stu1)
    {
        Setname(stu1.Getname());
        SetID(stu1.GetID());
        SetAccountNumber(stu1.GetAccountNumber());
    }
    void searchBookByName(string bookName)
    {
        AllUserS:: searchABookByItsName(bookName);
    }
} TEACHERS[10];
int counterForTeacher=0;
class LibraryStaff : public AllUserS
{
public:
    LibraryStaff(string n="", string i="", string ac=""):AllUserS(n,i,ac,5,0) {}
    void searchBooksByCategory(string str)
    {
        AllUserS::searchBookByCatogery(str);
    }
    void searchByName (string bookName)
    {
        AllUserS::searchABookByItsName(bookName);
    }
    void CheckStatusOAnyfBook(string str) // new one
    {
        AllUserS::CheckStatusOfBook(str);
    }
    void IsueABook(string bookName)
    {
        AllUserS::IssueABook(bookName);
    }
    void DisplayInfo()
    {
        for(int i=0; i<CounterForBooks; i++)
        {
            if(stringCompare(ListOfAllBooks[i].GetAccountNumberOfUser(), GetAccountNumber()))
            {
                ListOfAllBooks[i].displayBook();
            }
        }
    }
    void DisplayBooks ( ) //new one
    {
        AllUserS::DisplayAllBooks();
    }
    void ReturnBook(string BookName)
    {
        AllUserS::ReturnABook(BookName);
    }
    void operator = (LibraryStaff &stu1)
    {
        Setname(stu1.Getname());
        SetID(stu1.GetID());
        SetAccountNumber(stu1.GetAccountNumber());
    }
    void SetBook() // new
    {
        int num;
        do
        {
            cin.sync();
            // system("CLS");
            string str;

            cout << "Enter Title Of A Book              ";
            getline(cin,str);
            ListOfAllBooks[CounterForBooks].SetTitle(str);
            cout << "Enter Author Of A Book             ";
            getline(cin,str);
            ListOfAllBooks[CounterForBooks].SetAuthor(str);
            cout << "Enter Year Of Publication Of A Book    ";
            cin >> num;
            ListOfAllBooks[CounterForBooks].SetYearOfPublication(num);
            cin.sync();
            cout << "Enter Library Code Of A Book       ";
            getline(cin,str);
            ListOfAllBooks[CounterForBooks].SetLibraryCode(str);
            cout << "Enter International Standard Book Number ";
            getline(cin,str);
            ListOfAllBooks[CounterForBooks].SetISBN(str);
            cout << "Enter Category Of A Book        ";
            getline(cin,str);
            ListOfAllBooks[CounterForBooks].SetCatogery(str);
            cout << "Enter Status Of A Book          ";
            getline(cin,str);
            ListOfAllBooks[CounterForBooks].SetStatus(str);
            cin.sync();

            CounterForBooks++;
            // system("CLS");

            cout << "To Continue : Press \n";
            cout << "1 --> YES \n0 --> NO  ";
            cin>>num;
        }
        while(num);
    }
} STAFF[10];
int counterForStaff=0;
void makeDataBase();
int STOI(string);
void ReadRecordOfStudent()
{
    fstream file("STUDENTS.txt");
    string str;
    while(getline(file,str))
    {
        STUDENTS[counterForStudent].Setname(str);
        getline(file,str);
        STUDENTS[counterForStudent].SetID(str);
        getline(file,str);
        STUDENTS[counterForStudent].SetAccountNumber(str);
        getline(file,str);
        int num = STOI(str);
        STUDENTS[counterForStudent].SetCurrentIssuedBooks(num);
        counterForStudent++;
    }
    file.close();
}
void ReadRecordOfTeachers()
{
    fstream file("TEACHERS.txt");
    string str;
    while(getline(file,str))
    {
        TEACHERS[counterForTeacher].Setname(str);
        getline(file,str);
        TEACHERS[counterForTeacher].SetID(str);
        getline(file,str);
        TEACHERS[counterForTeacher].SetAccountNumber(str);
        getline(file,str);
        int num = STOI(str);
        TEACHERS[counterForTeacher].SetCurrentIssuedBooks(num);
        counterForTeacher++;
    }
    file.close();
}
void ReadRecordOfStaff()
{
    fstream file("STAFF.txt");
    string str;
    while(getline(file,str))
    {
        STAFF[counterForStaff].Setname(str);
        getline(file,str);
        STAFF[counterForStaff].SetID(str);
        getline(file,str);
        STAFF[counterForStaff].SetAccountNumber(str);
        getline(file,str);
        int num = STOI(str);
        STAFF[counterForStaff].SetCurrentIssuedBooks(num);
        counterForStaff++;
    }
    file.close();
}
void StoreStudentRecordOnFile()
{
    fstream file("STUDENTS.txt");
    for(int i=0; i<counterForStudent; i++)
    {
        file << STUDENTS[i].Getname()<<endl;
        file << STUDENTS[i].GetID() << endl;
        file << STUDENTS[i].GetAccountNumber()<<endl;
        file << STUDENTS[i].GetCurrentIssuedBooks()<<endl;
    }
    file.close();
}
void StoreTeacherRecordOnFile()
{
    fstream file("TEACHERS.txt");
    for(int i=0; i<counterForStudent; i++)
    {
        file << TEACHERS[i].Getname()<<endl;
        file << TEACHERS[i].GetID() << endl;
        file << TEACHERS[i].GetAccountNumber()<<endl;
        file << TEACHERS[i].GetCurrentIssuedBooks()<<endl;
    }
    file.close();
}
void StoreStaffRecordOnFile()
{
    fstream file("STAFF.txt");
    for(int i=0; i<counterForStudent; i++)
    {
        file << STAFF[i].Getname()<<endl;
        file << STAFF[i].GetID() << endl;
        file << STAFF[i].GetAccountNumber()<<endl;
        file << STAFF[i].GetCurrentIssuedBooks()<<endl;
    }
    file.close();
}
int main()
{
    DataBase();
    ReadRecordOfStaff();
    ReadRecordOfStudent();
    ReadRecordOfTeachers();
    cout << "\n\tWelcome To Library Management System \n" << endl;
    system("pause");
    system("CLS");
    int choice;
    do
    {
        cout << "1. Student \n";
        cout << "2. Teacher \n";
        cout << "3. Management Staff\n";
        cout << "\n Enter your Designation  ";
        cin >> choice;
        system("CLS");
        switch(choice)
        {
        case 1:
        {
            Student currentUser;
            int c;
            do
            {
                cout<<"1. SignUp for your account"<<endl;
                cout<<"2. Login into your account "<<endl;
                cout<<"3. Search a book by category"<<endl;
                cout<<"4. Search a book by its name"<<endl;
                cout<<"5. Issue a book "<<endl;
                cout<<"6. Return a book "<<endl;
                cout<<"7. Check Account Information"<<endl;
                cin>>c;
                system("CLS");
                switch (c)
                {
                case 1:
                {
                    cin.sync();
                    string name,id,accountNumber;
                    cout<< "Enter your name "<<endl;
                    getline(cin, name) ;
                    cin.sync();
                    cout<< "\nEnter your ID "<<endl;
                    getline(cin, id);
                    cin.sync();
                    cout<< "\nEnter your account number"<<endl;
                    getline(cin, accountNumber);
                    cin.sync();
                    Student obj1(name, id, accountNumber);
                    STUDENTS[counterForStudent]=obj1;
                    counterForStudent++;
                    currentUser = STUDENTS[counterForStudent];
                }
                break;
                case 2:
                {
                    cin.sync();
                    string name,id;
                    cout<< "Enter your name "<<endl;
                    getline( cin, name);
                    cin.sync();
                    cout<< "\nEnter your id"<<endl;
                    getline(cin, id);
                    cin.sync();
                    for ( int i =0; i<counterForStudent; i++)
                    {
                        if (stringCompare(STUDENTS[i].Getname(), name ))
                        {
                            if (stringCompare(STUDENTS[i].GetID(), id))
                            {
                                cout<< " WELCOME "<< STUDENTS[i].Getname()<< endl;
                                currentUser=STUDENTS[i];
                                break;
                            }
                        }
                    }
                }
                break;
                case 3:
                {
                    if(currentUser.Getname() != "")
                    {
                        string category;
                        cout<< "Enter Category To Search For It ";
                        cin.sync();
                        getline(cin,category);
                        currentUser.searchBooksByCategory(category);
                    }
                    else
                        cout << "You need to log in First To Access Data " << endl;
                }
                break;
                case 4:
                {
                    if (currentUser.Getname() != " ")
                    {
                        cin.sync();
                        string name;
                        cout << "Enter a Name: " ;
                        getline(cin, name );
                        cin.sync();
                        currentUser.searchABookByName(name);

                    }
                    else
                        cout << "You need to log in First To Access Data " << endl;

                }
                break;
                case 5:
                {
                    if (currentUser.Getname() != " ")
                    {
                        cin.sync();
                        string name;
                        cout<< " Enter a name"<<endl;
                        getline(cin, name);
                        cin.sync();
                        currentUser.IsueABook(name);
                    }
                    else
                        cout << "You need to log in First To Access Data " << endl;

                }
                break;
                case 6:
                {
                    cin.sync();
                    string name;
                    cout<< " Enter a name"<<endl;
                    getline(cin, name);
                    cin.sync();
                    currentUser.ReturnBook(name);
                }
                break;
                case 7:
                {
                    currentUser.DisplayInfo();
                }
                break;
                default:
                {
                    cout<< " INVALID OPTION "<<endl;
                }
                cin.sync();
                cout << "Do You Want To Go To The Students Menu Again ? " << endl;
                cout << "1. Yes\n0. NO " << endl;
                cin >> c;
                }
                }while(c);
            }
            break;

            case 2:
            {

                Teacher currentUser;
                int c;
                do
                {
                    cout<<"1. SignUp for your account"<<endl;
                    cout<<"2. Login into your account "<<endl;
                    cout<<"3. Search a book by category"<<endl;
                    cout<<"4. Search a book by its name"<<endl;
                    cout<<"5. Issue a book "<<endl;
                    cout<<"6. Return a book "<<endl;
                    cout<<"7. Check Account Information"<<endl;
                    cin>>c;
                    system("CLS");
                    switch (c)
                    {
                    case 1:
                    {
                        cin.sync();
                        string name,id,accountNumber;
                        cout<< " Enter your name "<<endl;
                        getline(cin, name) ;
                        cin.sync();
                        cout<< " Enter your ID "<<endl;
                        getline(cin, id);
                        cin.sync();
                        cout<< "Enter your account number"<<endl;
                        getline(cin, accountNumber);
                        cin.sync();
                        Teacher obj1(name, id, accountNumber);
                        TEACHERS[counterForTeacher]=obj1;
                        counterForTeacher++;
                        currentUser=TEACHERS[counterForTeacher];
                    }
                    break;
                    case 2:
                    {
                        cin.sync();
                        string name,id;
                        cout<< " Enter your name "<<endl;
                        getline( cin, name);
                        cin.sync();
                        cout<< " Enter your id"<<endl;
                        getline(cin, id);
                        cin.sync();
                        for ( int i =0; i<counterForTeacher; i++)
                        {
                            if (stringCompare(TEACHERS[i].Getname(), name ))
                            {
                                if (stringCompare(TEACHERS[i].GetID(), id))
                                {
                                    cout<< " WELCOME " << TEACHERS[i].Getname() << endl;
                                    currentUser=TEACHERS[i];
                                    break;
                                }
                            }
                        }
                    }
                    break;
                    case 3:
                    {
                        if(currentUser.Getname() != "")
                        {
                            cin.sync();
                            string category;
                            cout<< "Enter Category To Search For It ";
                            getline(cin,category);
                            currentUser.searchBooksByCategory(category);
                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;
                    }
                    break;
                    case 4:
                    {
                        if (currentUser.Getname() != " ")
                        {
                            string name;
                            cin.sync();
                            getline(cin, name );
                            currentUser.searchBookByName(name);

                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;
                    }
                    break;
                    case 5:
                    {
                        if(currentUser.Getname() != "")
                        {
                            cin.sync();
                            string name;
                            cout<< " Enter a name"<<endl;
                            getline(cin, name);
                            currentUser.IsueABook(name);
                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;

                    }
                    break;
                    case 6:
                    {
                        if(currentUser.Getname() != "")
                        {
                            cin.sync();
                            string name;
                            cout<< " Enter a name"<<endl;
                            getline(cin, name);

                            currentUser.ReturnBook(name);
                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;
                    }
                    break;
                    case 7:
                    {
                        if(currentUser.Getname() != "")
                        {
                            currentUser.DisplayInfo();
                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;
                    }
                    break;
                    default:
                    {
                        cout<< " INVALID OPTION "<<endl;
                    }
                    }
                    cin.sync();
                    cout << "Do You Want To Go To The Teacher's Menu Again ? " << endl;
                    cout << "1. Yes\n0. NO " << endl;
                }
                while(c);

            }
            break;
            case 3:
            {
                LibraryStaff currentUser;
                int c;
                do
                {
                    cout<<"1. SignUp for your account"<<endl;
                    cout<<"2. Login into your account "<<endl;
                    cout<<"3. Search a book by category"<<endl;
                    cout<<"4. Search a book by its name"<<endl;
                    cout<<"5. Issue a book "<<endl;
                    cout<<"6. Return a book "<<endl;
                    cout<<"7. Check Account Information"<<endl;
                    cout<<"8. Check Status of any book "<<endl;
                    cout<<"9. Display Books"<<endl;
                    cin>>c;
                    system("CLS");
                    switch (c)
                    {
                    case 1:
                    {
                        cin.sync();
                        string name,id,accountNumber;
                        cout<< " Enter your name "<<endl;
                        getline(cin, name) ;
                        cin.sync();
                        cout<< " Enter your ID "<<endl;
                        getline(cin, id);
                        cin.sync();
                        cout<< "Enter your account number"<<endl;
                        getline(cin, accountNumber);
                        cin.sync();
                        LibraryStaff obj1(name, id, accountNumber);
                        STAFF[counterForStaff]=obj1;
                        counterForStaff++;
                        currentUser=STAFF[counterForStaff];
                    }
                    break;
                    case 2:
                    {
                        cin.sync();
                        string name,id;
                        cout<< " Enter your name "<<endl;
                        getline( cin, name);
                        cin.sync();
                        cout<< " Enter your id"<<endl;
                        getline(cin, id);
                        cin.sync();
                        for ( int i =0; i<counterForStaff; i++)
                        {
                            if (stringCompare(STAFF[i].Getname(), name ))
                            {
                                if (stringCompare(STAFF[i].GetID(), id))
                                {
                                    cout<< " WELCOME " << STAFF[i].Getname() << endl;
                                    currentUser=STAFF[i];
                                    break;
                                }
                            }
                        }
                    }
                    break;
                    case 3:
                    {
                        if(currentUser.Getname() != "")
                        {
                            cin.sync();
                            string category;
                            cout<< "Enter Category To Search For It ";
                            cin.sync();
                            getline(cin,category);
                            currentUser.searchBooksByCategory(category);
                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;
                    }
                    break;
                    case 4:
                    {
                        if (currentUser.Getname() != " ")
                        {
                            string name;
                            cin.sync();
                            getline(cin, name );

                            currentUser.searchByName(name);

                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;

                    }
                    break;
                    case 5:
                    {
                        if(currentUser.Getname() != "")
                        {
                            cin.sync();
                            string name;
                            cout<< " Enter a name"<<endl;
                            getline(cin, name);

                            currentUser.IsueABook(name);
                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;

                    }
                    break;
                    case 6:
                    {
                        if(currentUser.Getname() != "")
                        {
                            cin.sync();
                            string name;
                            cout<< " Enter a name"<<endl;
                            getline(cin, name);
                            currentUser.ReturnBook(name);
                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;
                    }
                    break;
                    case 7:
                    {
                        if(currentUser.Getname() != "")
                        {
                            currentUser.DisplayInfo();
                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;
                    }
                    break;
                    case 8:
                    {
                        if(currentUser.Getname() != "")
                        {
                            cin.sync();
                            string name;
                            cout<< " Enter name of the book"<<endl;

                            getline(cin, name);
                            currentUser.CheckStatusOAnyfBook(name);
                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;
                    }
                    break;
                    case 9:
                    {
                        if(currentUser.Getname() != "")
                        {
                            cin.sync();
                            string name;
                            cout<< " Enter name of the book"<<endl;

                            getline(cin, name);
                            currentUser.DisplayBooks();

                        }
                        else
                            cout << "You need to log in First To Access Data " << endl;

                    }
                    break;
                    default:
                    {
                        cout<< " INVALID OPTION "<<endl;
                    }
                    }
                    cin.sync();
                    cout << "Do You Want To Go To The Main Menu Again ? " << endl;
                    cout << "1. Yes\n0. NO " << endl;
                    cin >> c;
                }
                while (c);
            }
            break;
            default:
            {
                cout << "You Have Selected an Invalid Option " << endl;
            }
        }
        cout << "Do You Want To Go To The Main Menu Again ? " << endl;
        cout << "1. Yes\n0. NO " << endl;
        cin >> choice;
    }while(choice);

        makeDataBase();
        StoreStaffRecordOnFile();
        StoreStudentRecordOnFile();
        StoreTeacherRecordOnFile();
        return 0;
    }
int STOI(string str)
    {
        stringstream ss(str);
        int x = 0;
        ss >> x;
        return x;
    }
void makeDataBase()
    {
        fstream file("Books.txt");
        if(!file)
        {
            cout << "Error 404!! File Not Found " << endl;
        }
        for(int i=0; i<CounterForBooks; i++)
        {
            cin.sync();
            file << ListOfAllBooks[i].GetTitle()<<endl;
            file << ListOfAllBooks[i].GetAuthor()<<endl;
            file << ListOfAllBooks[i].GetYearOfPublication()<<endl;
            file << ListOfAllBooks[i].GetLibraryCode()<<endl;
            file << ListOfAllBooks[i].GetISBN()<<endl;
            file << ListOfAllBooks[i].GetCatogery()<<endl;
            file << ListOfAllBooks[i].GetStatus()<<endl;
            file << ListOfAllBooks[i].GetAccountNumberOfUser()<<endl;
            int *ptr = ListOfAllBooks[i].GetIssuedDate();
            file << *(ptr+0)<<endl << *(ptr+1)<<endl << *(ptr+2) <<endl;
            ptr = ListOfAllBooks[i].GetReturnDate();
            file << *(ptr+0)<<endl << *(ptr+1)<<endl << *(ptr+2) <<endl;
            cin.sync();
        }
        file.close();
    }
void DataBase()
    {
        fstream file("Books.txt");
        if(!file)
        {
            cout << "Error 404! File Not Found  " << endl;
        }
        string str;
        int num;
        int arr[3];
        while(getline(file,str))
        {
            ListOfAllBooks[CounterForBooks].SetTitle(str);
            getline(file,str);
            ListOfAllBooks[CounterForBooks].SetAuthor(str);
            getline(file,str);
            num = STOI(str);
            ListOfAllBooks[CounterForBooks].SetYearOfPublication(num);
            file.sync();
            getline(file,str);
            ListOfAllBooks[CounterForBooks].SetLibraryCode(str);
            getline(file,str);
            ListOfAllBooks[CounterForBooks].SetISBN(str);
            getline(file,str);
            ListOfAllBooks[CounterForBooks].SetCatogery(str);
            getline(file,str);
            ListOfAllBooks[CounterForBooks].SetStatus(str);
            getline(file,str);
            ListOfAllBooks[CounterForBooks].SetAccountNumberOfUser(str);
            getline(file,str);
            arr[0] = STOI(str);
            getline(file,str);
            arr[1] = STOI(str);
            getline(file,str);
            arr[2] = STOI(str);
            ListOfAllBooks[CounterForBooks].SetIssuedDate(arr);
            arr[0] = STOI(str);
            getline(file,str);
            arr[1] = STOI(str);
            getline(file,str);
            arr[2] = STOI(str);
            ListOfAllBooks[CounterForBooks].SetReturnDate(arr);
            CounterForBooks++;
            getline(file,str);
            file.sync();
        }
        file.close();
    }
bool stringCompare(string str1, string str2)
    {
        if (str1.length() != str2.length() )
            return 0;
        else
        {
            int length = str1.length();
            for (int i=0; i < length; i++)
            {
                if (str1[i] != str2[i])
                {
                    if ((char)str1[i] != (char)str2[i]+32 && (char)str1[i] != (char)str2[i]-32 )
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
    }

