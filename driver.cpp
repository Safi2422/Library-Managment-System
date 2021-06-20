#include <iostream>
#include <fstream>
#include<string>
#include<cstring>
#include<conio.h>

using namespace std;

void AdminLogin(int n);
void UserLogin(int n);
void UserSignup(int n);
void savefile(int nU, string domain, string password);
bool confirmpassword(string password, string password1);
bool compareA(string domain, string password);
bool compareU(string domain, string password);
string username;

// Admin Login Function
void AdminLogin(int n)
{
    cout << "\t\t\t********************************\n";
    cout << "\t\t\tWelcome to Librarian login page \n" << endl;
    cout << "\t\t\t********************************\n";
    ifstream admin("admin.txt");
    string domain;
    string password;
    if (admin.is_open())
    {
        cout << "Enter your Librarian ID: ";
        cin >> domain;
        cout << "Enter your password:  ";
        cin >> password;

        if (compareA(domain, password) == false)
        {
            while (compareA(domain, password) == false)
            {
                cout << "\n\nLibrarian ID/Password not found!!!" << endl;
                cout << "Please enter your Librarian ID again: ";
                cin >> domain;
                cout << "Password: ";
                cin >> password;
                if (compareA(domain, password) == true) // Refered to the Compare function to verify the Password and Username
                {
                    cout << "\n*******************\n";
                    cout << "Login successful!!!" << endl;
                    cout << "Welcome " << domain << endl;
                    cout << "*******************\n";
                }
            }
        }
        else
        {
            cout << "\n*******************\n";
            cout << "Login successful!!!" << endl;
            cout << "Welcome " << domain << endl;
            cout << "*******************\n";
        }
    }
    admin.close();
}

// Hide Characters
char pwd()
{
    char password[25];
    int x = 0;
    while ((password[x] = _getch()) != '\r')    // Takes each character, saves into array and print asteriks on its place
    {
        cout << "*";    // Can be used to print astericks while typing password
        x++;    // Unable to implement beacause of ambiguty
    }
    return password[x];
}

// Password Confirm Function
bool confirmpassword(string password, string password1)
{
    if (password == password1)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

// Compare Admin/Librarian Strings
bool compareA(string domain, string password)
{
    string userAndPass = domain + " " + password;
    int offset;
    string line;
    bool found = false;
    ifstream fin;
    fin.open("admin.txt");
    if (fin.is_open())
    {
        while (getline(fin, line) && !found)    // Save each line from the File into string line and check the status of bool found
        {
            if (line.compare(userAndPass) == 0) // Compare the string line with Domain and Password (userAndPass)
            {
                found = true;
            }
        }
        fin.close();
        if (found)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Compare User/Student Strings
bool compareU(string domain, string password)
{
    string userAndPass = domain + " " + password;
    int offset;
    int nU;
    string line;
    bool found = false;
    ifstream fin;
    fin.open("user.txt");
    fin >> nU;
    if (fin.is_open())
    {
        while (getline(fin, line) && !found)    // Save each line from the File into string line and check the status of bool found
        {
            if (line.compare(userAndPass) == 0) // Save each line from the File into string line and check the status of bool found
            {
                found = true;
            }
        }
        fin.close();
        if (found)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Save File data
void savefile(int nU, string domain, string password)
{
    int noOfUsers;
    char** myarray;
    myarray = new char* [20];
    for (int i = 0; i < 20; i++)
        myarray[i] = new char[100]; // Creating Dynamic Array
    
    ifstream fin("user.txt");

    fin >> noOfUsers;

    int ctr = 0;
    while (!fin.eof())
    {
        fin.getline(myarray[ctr], 100, '\n');   // Saves each line from file into myarray
        ctr++;
    }
    fin.close();
    
    ofstream fout;
    fout.open("user.txt");
    
    fout << noOfUsers + 1;
    
    for (int i = 0; i < ctr; i++)
        fout << myarray[i] << "\n"; // Saves the lines from myarray into file
    fout << domain << " " << password;  // Saves the newly entered domain and password into the file

    fout.close();
}

// User Main function
void user(int n)
{
    int nU = 0;
    cout << "\t\t\t**************************\n";
    cout << "\t\t\tWelcome to User login page\n" << endl;
    cout << "\t\t\t**************************\n";
    while (nU != 1 && nU != 2)
    {
        cout << "\n\nEnter corresponding numbers accordingly " << endl;
        cout << " 1: Login" << endl;
        cout << " 2: Signup" << endl;
        cin >> nU;
        cout << endl;
        if (nU != 1 && nU != 2)
        {
            cout << "\nWrong input. Enter numbers from the given options" << endl;
        }
        else
        {
            switch (nU)
            {
            case 1:
                cout << "\t\t\t*************\n";
                cout << "\t\t\tLogin Window \n" << endl;
                cout << "\t\t\t*************\n";
                UserLogin(nU);
                break;
            case 2:
                cout << "\t\t\t**************\n";
                cout << "\t\t\tSignup Window \n" << endl;
                cout << "\t\t\t**************\n";
                UserSignup(nU);
                break;
            }
        }
    }
}

// User Login Function
void UserLogin(int n)
{
    ifstream user("user.txt");
    string domain;
    string password;
    if (user.is_open())
    {
        cout << "\n*********************\n";
        cout << "Enter your Username: ";
        cin >> domain;
        cout << "Enter your password:  ";
        cin >> password;
        cout << "*********************\n";
        if (compareU(domain, password) == false)
        {
            while (compareU(domain, password) == false)
            {
                cout << "\nUsername/Password not found!!!" << endl;
                cout << "\nPlease enter your Username again: ";
                cin >> domain;
                cout << "Password: ";
                cin >> password;
                if (compareU(domain, password) == true) // Refered to the Compare function to verify the Password and Username
                {
                    cout << "*********************\n";
                    cout << "Login successful!!!" << endl;
                    cout << "Welcome " << domain << endl;
                    cout << "*********************\n";
                }
            }
        }
        else
        {
            cout << "*********************\n";
            cout << "Login successful!!!" << endl;
            cout << "Welcome " << domain << endl;
            cout << "*********************\n";
        }
    }
    username = domain;
    user.close();
}

// User Signup Function
void UserSignup(int n)
{
    fstream user("user.txt");
    int nU;
    string domain;
    int ndomain;
    string password;
    string password1;
    string id;
    if (user.is_open())
    {
        user >> nU;
        ndomain = nU++;
        cout << "\n*********************\n";
        cout << "Enter Username: ";
        cin >> domain;
        cout << "Enter Email: ";
        cin >> id;
        cout << "Enter password:  ";
        cin >> password;
        cout << "Enter password again to confirm:  ";
        cin >> password1;
        cout << "*********************\n";
        if (confirmpassword(password, password1) == false)
        {
            while (confirmpassword(password, password1) == false)
            {
                cout << "\n*********************\n";
                cout << "Password not matched" << endl;
                cout << "Enter again!!!" << endl;
                cout << "\nEnter your password :  ";
                cin >> password;
                cout << "Enter your password again to confirm:  ";
                cin >> password1;
                if (confirmpassword(password, password1) == true)
                {
                    savefile(ndomain, domain, password);
                    cout << "\n************************************************\n";
                    cout << "Your account has been created successfully!!!" << endl;
                    cout << "Your ID is " << domain << " with Password " << password << endl;
                    cout << "You have to use these Credentials to login!!!";
                    cout << "\n************************************************\n";
                }
            }
        }
        else
        {
            savefile(ndomain, domain, password);
            cout << "\n************************************************\n";
            cout << "Your account has been created successfully!!!" << endl;
            cout << "Your ID is " << domain << " with Password " << password << endl;
            cout << "You have to use these Credentials to login!!!" << endl;
            cout << "\n************************************************\n";
        }
    }
    user.close();

    UserLogin(0);
}

class Book
{
private:
    int book_ID;
    char* book_title;
    char* book_type;
    char* authorName;
    char* availability;
public:
    Book();
    ~Book();
    void loadBooks(ifstream& , Book**&, int);
    void showBooks(Book**, int);
    void newBook(Book**, int);
    void deleteBook(Book**, int, int);
    void editBookData(Book**, int, int);
    void booksToIssue(Book**, int);
    void viewUsersWithBooks(Book**, int);
    void requestBook(Book**, int);
    void returnBook(Book**, int);
};

//Constructor for initializing values
Book::Book()
{
    book_ID = 0;

    book_title = NULL;
    book_type = NULL;
    authorName = NULL;
    availability = NULL;

    book_title = new char[50];
    book_type = new char[10];
    authorName = new char[20];
    availability = new char[3];
}

//Destructor for memory deallocating
Book::~Book()
{
    delete[] book_type;
    delete[] book_title;
    delete[] authorName;
    delete[] availability;
}

//taking input from file to load books
void Book::loadBooks(ifstream& fin, Book**& books, int noOfBooks)
{
    for (int i = 0; i < noOfBooks; i++)
    {
        fin >> books[i]->book_ID;
        fin.ignore(1);
        fin.getline(books[i]->book_title, 50, '\n');
        fin.getline(books[i]->book_type, 10, '\n');
        fin.getline(books[i]->authorName, 20, '\n');
        fin.getline(books[i]->availability, 3, '\n');
    }
}

//input taken from file is displayed in user friendly format
void Book::showBooks(Book** books, int noOfBooks)
{
    cout << "\n-------------------------------------";
    for (int i = 0; i < noOfBooks; i++)
    {
        cout << "\n\nBook ID: " << books[i]->book_ID;
        cout << "\nBook Title: " << books[i]->book_title;
        cout << "\nBook Type: " << books[i]->book_type;
        cout << "\nAuthor Name: " << books[i]->authorName;
        cout << "\nAvailability: ";
        if (books[i]->availability[0] == 'N')
            cout << "Available";
        else if (books[i]->availability[0] == 'I')
            cout << "Not Available";

        cout << endl;
        cout << "-------------------------------------\n";
    }
}

//allows the user to add new books in library
//will ask for all book contents and save it in file
void Book::newBook(Book** books, int noOfBooks)
{
    int choice;
    noOfBooks += 1; //managing total no of books
    books[noOfBooks - 1]->book_ID = noOfBooks;
    //Taking inputs for book related contents
    cout << "\nEnter Book Title: ";
    cin.ignore();
    cin.getline(books[noOfBooks - 1]->book_title, 50, '\n');
    cout << "\nEnter Book Type: ";
    cin.getline(books[noOfBooks - 1]->book_type, 10, '\n');
    cout << "\nEnter Writer Name: ";
    cin.getline(books[noOfBooks - 1]->authorName, 20, '\n');
    cout << "\nPress required number to set availability:\n1. Available\t2. Not Available\n";
    cin >> choice;
    //setting availability status
    if (choice == 1)
    {
        books[noOfBooks - 1]->availability[0] = 'N';
        books[noOfBooks - 1]->availability[1] = 'I';
    }
    else if (choice == 2)
    {
        books[noOfBooks - 1]->availability[0] = 'I';
    }
    //saving back into file
    ofstream fout("Books.txt");
    fout << noOfBooks << endl;
    for (int i = 0; i < noOfBooks; i++)
    {
        fout << books[i]->book_ID << "\t" << books[i]->book_title << "\n";
        fout << books[i]->book_type << "\n";
        fout << books[i]->authorName << "\n";
        fout << books[i]->availability[0] << books[i]->availability[1] << "\n";
    }
    fout.close();
    cout << "\nBook has been added successfully.\n";
}

//will delete the book from file
void Book::deleteBook(Book** books, int noOfBooks, int bookToDelete)
{
    //finding the user entered book to delete from file
    for (int i = bookToDelete; i < noOfBooks; i++)
    {
        books[i - 1]->book_title = books[i]->book_title;
        books[i - 1]->book_type = books[i]->book_type;
        books[i - 1]->authorName = books[i]->authorName;
        books[i - 1]->availability = books[i]->availability;
    }

    noOfBooks -= 1;
    //deleting the book from file
    ofstream fout("Books.txt");

    fout << noOfBooks << endl;
    for (int i = 0; i < noOfBooks; i++)
    {
        fout << books[i]->book_ID << "\t" << books[i]->book_title << "\n";
        fout << books[i]->book_type << "\n";
        fout << books[i]->authorName << "\n";
        fout << books[i]->availability[0] << books[i]->availability[1] << "\n";
    }

    fout.close();

    cout << "\nBook with ID " << bookToDelete << " has been successfully deleted.\n";
}

//allows the user to edit book details
//can edit all attributes of book
void Book::editBookData(Book** books, int noOfBooks, int choice)
{
    //asking user what is to be changed
    int option;
    choice -= 1;
    cout << "\nWhat you want to edit:\n"
        "1. Book Title\n2. Book Type\n3. Author Name\n4. Availability\n";
    cout << "\nEnter number: ";
    cin >> option;
    //changing according to entered data
    if (option == 1)
    {
        cout << "\nEnter New Book Title: ";
        cin.ignore();
        cin.getline(books[choice]->book_title, 50, '\n');
    }
    else if (option == 2)
    {
        cout << "\nEnter New Book Type: ";
        cin.ignore();
        cin.getline(books[choice]->book_type, 10, '\n');
    }
    else if (option == 3)
    {
        cout << "\nEnter New Author Name: ";
        cin.ignore();
        cin.getline(books[choice]->authorName, 20, '\n');
    }
    else if (option == 4)
    {
        int choice_2;
        cout << "\nPress required number to set availability:\n1. Available\t2. Not Available\n";
        cin >> choice_2;

        if (choice_2 == 1)
        {
            books[choice]->availability[0] = 'N';
            books[choice]->availability[1] = 'I';
        }
        else if (choice_2 == 2)
        {
            books[choice]->availability[0] = 'I';
        }
    }
    //writting back into file
    ofstream fout("Books.txt");
    fout << noOfBooks << endl;
    for (int i = 0; i < noOfBooks; i++)
    {
        fout << books[i]->book_ID << "\t" << books[i]->book_title << "\n";
        fout << books[i]->book_type << "\n";
        fout << books[i]->authorName << "\n";
        fout << books[i]->availability[0] << books[i]->availability[1] << "\n";
    }
    fout.close();
    cout << "\nBook has been edited successfully.\n";
}

//checcking the request file and allowing librarian to issue book 
void Book::booksToIssue(Book** books, int noOfBooks)
{
    char* user;
    user = new char[10];
    int noOfRequestedBooks;
    int choice;
    int date, month, year;
    
    char** issuedBooks;
    issuedBooks = new char*[20];
    for (int i = 0; i < 20; i++)
        issuedBooks[i] = new char[100];
    //getting data from file
    ifstream FIN("issuedbooks.txt");
    int count = 0;
    while (!FIN.eof())
    {
        FIN.getline(issuedBooks[count], 100);
        count++;
    }
    FIN.close();

    ifstream fin("RequestsIssue.txt");
    ofstream FOUT("issuedbooks.txt");
    //getting request from file
    int* requestBooks;

    while (!fin.eof())
    {
        fin >> user;

        if (user[0] == '\0')
        {
            ofstream fout("Books.txt");
            fout << noOfBooks << endl;
            for (int i = 0; i < noOfBooks; i++)
            {
                fout << books[i]->book_ID << "\t" << books[i]->book_title << "\n";
                fout << books[i]->book_type << "\n";
                fout << books[i]->authorName << "\n";
                fout << books[i]->availability[0] << books[i]->availability[1] << "\n";
            }
            fout.close();

            ofstream Fout("RequestsIssue.txt");
            Fout << 0;
            Fout.close();

            for (int i = 0; i < count; i++)
                FOUT << issuedBooks[i] << "\n";

            delete[] user;
            fin.close();
            FOUT.close();
            return;
        }

        fin >> noOfRequestedBooks;
        if (user[0] == '0')
        {
            cout << "\nThere are no requests!!!\n";
            for (int i = 0; i < count; i++)
                FOUT << issuedBooks[i] << "\n";

            delete[] user;
            fin.close();
            FOUT.close();
            return;
        }
        requestBooks = new int[noOfRequestedBooks];
        for (int i = 0; i < noOfRequestedBooks; i++)
        {
            fin >> requestBooks[i];
        }
        cout << "\n-------------------------------------\n";
        cout << user << " has requested " << noOfRequestedBooks << " books:\n";
        cout << "\n-------------------------------------";
        for (int i = 0; i < noOfRequestedBooks; i++)
        {
            cout << "\n\nBook ID: " << books[requestBooks[i] - 1]->book_ID;
            cout << "\nBook Title: " << books[requestBooks[i] - 1]->book_title;
            cout << "\nBook Type: " << books[requestBooks[i] - 1]->book_type;
            cout << "\nAuthor Name: " << books[requestBooks[i] - 1]->authorName;

            cout << endl;
            cout << "-------------------------------------\n";
        }

        system("pause");
        //allowing librarian to issue book
        cout << "Enter Number:\n"
            << "1. Issue\t2. Don't Issue\n";
        cin >> choice;

        if (choice == 1)
        {
            //taking in return date
            cout << "\nEnter Return Date (Format: Date Month Year): ";
            cin >> date >> month >> year;

            FOUT << user << "\t" << noOfRequestedBooks << "\t";

            for (int i = 0; i < noOfRequestedBooks; i++)
            {
                FOUT << requestBooks[i] << " ";
            }

            FOUT << date << " " << month << " " << year << endl;

            cout << "\nBooks has been issued.\n";
            for (int i = 0; i < noOfRequestedBooks; i++)
            {
                books[requestBooks[i] - 1]->availability[0] = 'I';
            }
        }
        else if (choice == 2)
        {
            cout << endl << user << " has been informed through email that"
                " books has not been issued.\n";
        }

        system("pause");
    }
    //writting back on file
    ofstream fout("Books.txt");
    fout << noOfBooks << endl;
    for (int i = 0; i < noOfBooks; i++)
    {
        fout << books[i]->book_ID << "\t" << books[i]->book_title << "\n";
        fout << books[i]->book_type << "\n";
        fout << books[i]->authorName << "\n";
        fout << books[i]->availability[0] << books[i]->availability[1] << "\n";
    }
    fout.close();

    ofstream Fout("RequestsIssue.txt");
    Fout << 0;
    Fout.close();

    for (int i = 0; i < count; i++)
        FOUT << issuedBooks[i] << "\n";

    delete[] user;
    fin.close();
    FOUT.close();
}

//displays the users with books
void Book::viewUsersWithBooks(Book** books, int noOfBooks)
{
    char* user;
    user = new char[10];
    int noOfIssuedBooks;
    int book;
    int date, month, year;

    ifstream fin("issuedbooks.txt");

    while (!fin.eof())
    {
        fin >> user;
        if (user[0] == '\0')
        {
            delete[] user;
            fin.close();
            return;
        }
        //showing users to librarian
        cout << "\n--------------------------------";
        cout << "\n\nUser: " << user << "\t";
        fin >> noOfIssuedBooks;
        for (int i = 0; i < noOfIssuedBooks; i++)
        {
            fin >> book;
            cout << "\n\nBook " << i + 1 << ":\n";
            cout << "Book ID: " << books[book - 1]->book_ID << endl;
            cout << "Book Title: " << books[book - 1]->book_title << endl;
        }
        fin >> date >> month >> year;
        cout << "\nBooks to be returned before: " << date << " " << month << " " << year;
    }
    
    delete[] user;
    fin.close();
}

//allows the user to request book from librarian
void Book::requestBook(Book** books, int noOfBooks)
{
    char temp;
    int count = 0;
    ifstream fin("RequestsIssue.txt");
    fin >> temp;
    fin.close();

    char** tempData;
    tempData = new char*[10];
    for (int i = 0; i < 10; i++)
        tempData[i] = new char[100];
    //making backup
    if (temp != 0)
    {
        ifstream FIn("RequestsIssue.txt");
        while(!FIn.eof())
        {
            FIn >> tempData[count];
            count++;
        }
        FIn.close();
    }

    int* ids;
    int n;

    ofstream fout("RequestsIssue.txt");
    
    cout << "Enter the number of BOOKS you want to request: ";
    cin >> n;													//allocating memory for the number of requests
    ids = new int[n + n];

    cout << "Enter the BOOK ID'S you want to request: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ids[i];
    }
    
    fout << username << "\t";
    fout << n;

    int k = 0;											// for iterating req array
    for (int i = 0; i < noOfBooks; i++)
    {
        if (books[i]->book_ID == ids[k])						//searching id of the book given by user
        {
            if (books[i]->availability[0] == 'N')				// now checking if the book is available or not
            {
                fout << " " << books[i]->book_ID;
                cout << "The book\"" << books[i]->book_title << "\" with ID "
                    << books[i]->book_ID << " has been requested.\n";
                k++;
            }
            else
            {
                cout << "SORRY! The book\"" << books[i]->book_title << "\" with ID " 
                    << books[i]->book_ID << " is not available!!!\nOther books has been requested!!!\n\n";
                k++;
            }
        }
    }
    //restoring from backup
    for (int i = 0; i < count; i++)
    {
        fout << endl << tempData[i];
    }
    fout.close();
}

//allows the user to return book
void Book::returnBook(Book** books, int noOfBooks)
{
    int counter = 0, number, issue;
    int date, month, year;

    char** tempuser;
    tempuser = new char*[20];
    for (int i = 0; i < 20; i++)
        tempuser[i] = new char[10];
    
    char** tempdata;
    tempdata = new char* [20];
    for (int i = 0; i < 20; i++)
        tempdata[i] = new char[100];

    ifstream fin("issuedbooks.txt");
    
    int count = 0;
    //making backup
    while (!fin.eof())
    {
        char* user;
        user = new char[10];
        fin >> user;
        for (int i = 0; i < username.length(); i++)
        {
            if (username[i] == user[i])
            {
                counter++;
            }
        }
        if (counter == username.length())
        {
            int k;
            fin >> number;
            cout << "\nYou have " << number << " books pending to return\n";
            //taking data from file
            for (int i = 0; i < number; i++)
            {
                int bookno;
                fin >> bookno;
                cout << "------------------------------------\n";
                cout << "\nBook ID: " << books[bookno - 1]->book_ID;
                cout << "\nBook Title: " << books[bookno - 1]->book_title;
                cout << "\n------------------------------------\n";
            }
            fin >> date >> month >> year;
            cout << "\nTo be returned before: " << date << " " << month << " " << year;
            cout << "\n------------------------------------\n";

            cout << "Enter 0 if you don't want to return.\n"
                "Enter the ID of the book you want to return: ";
            cin >> k;

            if (k == 0)
                return;
            //setting availability status
            books[k - 1]->availability[0] = 'N';
            books[k - 1]->availability[1] = 'I';

            counter = 0;
        }
        else
        {
            tempuser[count] = user;
            fin.getline(tempdata[count], 100, '\n');
            count++;
            counter = 0;
        }
    }
    //using backup
    ofstream FOUT("issuedbooks.txt");
    for (int i = 0; i < count; i++)
    {
        FOUT << tempuser[i] << tempdata[i] << endl;
    }
    FOUT.close();
    //writting back into file
    ofstream fout("Books.txt");
    fout << noOfBooks << endl;
    for (int i = 0; i < noOfBooks; i++)
    {
        fout << books[i]->book_ID << "\t" << books[i]->book_title << "\n";
        fout << books[i]->book_type << "\n";
        fout << books[i]->authorName << "\n";
        fout << books[i]->availability[0] << books[i]->availability[1] << "\n";
    }
    fout.close();
    fin.close();

    cout << "\nBook has been returned.\n";
    system("pause");
}

class Books
{
private:
    int noOfBooks;
    Book book;
    Book** books;
public:
    Books();
    ~Books();
    void inputBooks();
    void printBookList();
    void addBook();
    void removeBook();
    void editBook();
    void issueBook();
    void returnNotice();
    void viewIssuedUsers();
    void Request();
    void ReturnBook();
};

Books::Books()
{
    noOfBooks = 0;
    books = NULL;
}

Books::~Books()
{

}

void Books::inputBooks()
{
    ifstream fin("Books.txt");

    fin >> noOfBooks;

    books = new Book * [noOfBooks + noOfBooks];
    for (int i = 0; i < (noOfBooks + noOfBooks); i++)
        books[i] = new Book[1];

    book.loadBooks(fin, books, noOfBooks);

    fin.close();
}

void Books::printBookList()
{
    book.showBooks(books, noOfBooks);
}

void Books::issueBook()
{
    book.booksToIssue(books, noOfBooks);
}

void Books::viewIssuedUsers()
{
    book.viewUsersWithBooks(books, noOfBooks);
}

void Books::returnNotice()
{
    char* user;
    user = new char[10];
    char** noticeUsers;
    noticeUsers = new char*[10];
    for (int i = 0; i < 10; i++)
        noticeUsers[i] = new char[10];
    
    book.viewUsersWithBooks(books, noOfBooks);
    
    cout << "\n-------------------------------------";
    cout << "\n\nEnter username exactly to give notice: ";
    cin >> user;
    //finding user data from file
    int count = 0;
    
    ifstream fin("NoticeUsers.txt");
    while (!fin.eof())
    {
        fin >> noticeUsers[count];
        count++;
    }
    fin.close();

    ofstream fout("NoticeUsers.txt");
    fout << user << endl;
    for (int i = 0; i < count; i++)
    {
        fout << noticeUsers[i] << endl;
    }
    fout.close();

    cout << "\n" << user << " has been notified.\n";
    system("pause");
    delete[] noticeUsers;
    delete[] user;
}

void Books::addBook()
{
    book.newBook(books, noOfBooks);
}

void Books::removeBook()
{
    int bookToDelete;

    cout << "\nEnter ID of book to delete: ";
    cin >> bookToDelete;

    book.deleteBook(books, noOfBooks, bookToDelete);

    delete[] books[bookToDelete];
}

void Books::editBook()
{
    int choice;

    cout << "\nEnter ID of book to edit: ";
    cin >> choice;

    book.editBookData(books, noOfBooks, choice);
}

void Books::Request()
{
    book.requestBook(books, noOfBooks);
}

void Books::ReturnBook()
{
    book.returnBook(books, noOfBooks);
}

class Librarian
{
public:
    int menu();
};

int Librarian::menu()
{
    int option;

    cout << endl << endl;
    cout << "\n--------------------------------\n";
    cout << "1. View Books\n2. Add Book\n3. Remove Book\n4. Edit Book Data\n"
        "5. Issue Requests\n6. Return Notice\n7. View Issued Users\n8. Log Out to Exit\n";
    cin >> option;

    while (option > 8 || option < 1)
    {
        cout << endl;
        cout << "Enter Correct Option!!!";
        cout << endl << endl;
        cout << "\n--------------------------------";
        cout << "1. View Books\n2. Add Book\n3. Remove Book\n4. Edit Book Data\n"
            "5. Issue Requests\n6. Return Notice\n7. View Issued Users\n8. Log Out to Exit\n";
        cin >> option;
    }

    cout << endl << endl;
    return option;
}

class User
{
public:
    int menu();
    void notification();
};

void User::notification()
{
    int counter = 0;

    char** tempuser;
    tempuser = new char* [20];
    for (int i = 0; i < 20; i++)
        tempuser[i] = new char[10];

    ifstream fin("NoticeUsers.txt");
    
    int count = 0;
    //creating backup and finding user
    while (!fin.eof())
    {
        char* user;
        user = new char[10];

        fin >> user;
        
        for (int i = 0; i < username.length(); i++)
        {
            if (username[i] == user[i])
            {
                counter++;
            }
        }
        //getting notification
        if (counter == username.length())
        {
            cout << "\nPlease return the books!!!\n";
        }
        else
        {
            tempuser[count] = user;
            count++;
        }
    }
    //using backup
    ofstream fout("NoticeUsers.txt");
    for (int i = 0; i < count; i++)
    {
        fout << tempuser[i] << endl;
    }
    fout.close();

    cout << "\nThats all for now.\n";
    fin.close();
}

int User::menu()
{
    int option;

    cout << endl << endl;
    cout << "1. View Books\n2. Request Books\n3. Return Books\n4. Notifications\n"
        "5. Log Out to Exit\n";
    cin >> option;

    while (option > 5 || option < 1)
    {
        cout << endl;
        cout << "Enter Correct Option!!!";
        cout << endl << endl;
        cout << "1. View Books\n2. Request Books\n3. Return Books\n4. Notifications\n"
            "5. Log Out to Exit\n";
        cin >> option;
    }

    cout << endl << endl;
    return option;
}

int main()
{
    int choice = 0, choice_2 = 0, choice_3 = 0;
    int choice_0 = 0;

    cout << "\t\t\t****************************************************\n";
    cout << "\t\t\tWelcome to <\\Cpp TrIos/> Library Managment System\n" << endl;
    cout << "\t\t\t****************************************************\n";

    Books b;
    Librarian l;
    User u;

    b.inputBooks();
    
    //menu for librarian and user
    while (choice_2 != 3)
    {
        cout << "=> How you want to continue:\n1. User\t\t2. Librarian\n3. Exit\n";
        cin >> choice_2;
    
        while (choice_2 > 3 || choice_2 < 1)
        {
            cout << "\nEnter Correct Option!!!\n"
                "=> How you want to continue:\n1. User\t2. Librarian\n3. Exit\n";
            cin >> choice_2;
        }

        if (choice_2 == 1)
        {
            user(choice_0);

            cout << endl << endl << endl;
            cout << "\t*******************************************************\n";
            cout << "\t*******************************************************\n";
            cout << "\t*********** WELCOME TO <\\Cpp TrIoS/> LIBRARY **********\n";
            cout << "\t*******************************************************\n";
            cout << "\t*******************************************************\n";

            while (choice_3 != 5)
            {
                choice_3 = u.menu();

                if (choice_3 == 1)
                {
                    cout << "\nFollowing books are included in Library:\n";
                    b.printBookList();
                }
                else if (choice_3 == 2)
                {
                    b.printBookList();
                    b.Request();
                }
                else if (choice_3 == 3)
                {
                    b.ReturnBook();
                    b.inputBooks();
                }
                else if (choice_3 == 4)
                {
                    u.notification();
                }
                else if (choice_3 == 5)
                {
                    username = {" "};
                    cout << "\nLogged out!!!\n";
                    system("pause");
                    cout << endl << endl;
                }
            }
            choice_3 = 0;
            choice_2 = 0;
        }
        if (choice_2 == 2)
        {
            AdminLogin(choice_0);
            while (choice != 8)
            {
                choice = l.menu();

                if (choice == 1)
                    b.printBookList();
                else if (choice == 2)
                {
                    b.addBook();
                    b.inputBooks();
                }
                else if (choice == 3)
                {
                    b.printBookList();
                    b.removeBook();
                    b.inputBooks();
                }
                else if (choice == 4)
                {
                    b.printBookList();
                    b.editBook();
                    b.inputBooks();
                }
                else if (choice == 5)
                {
                    b.issueBook();
                    b.inputBooks();
                }
                else if (choice == 6)
                {
                    b.returnNotice();
                }
                else if (choice == 7)
                {
                    b.viewIssuedUsers();
                }
                else if (choice == 8)
                {
                    cout << "\nLogged out!!!\n";
                    system("pause");
                    cout << endl << endl;
                }
            }
            choice = 0;
            choice_2 = 0;
        }
        if (choice_2 == 3)
        {
            cout << "\nNow Program will close!!!!\n";
            system("pause");
        }
    }
}