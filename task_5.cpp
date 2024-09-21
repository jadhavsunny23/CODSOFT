#include<iostream>
#include<cstring>
 using namespace std;
 class Book
 {
    public:
    char title[25];
    char author[20];
    int isbn;

    public:
    void accept()
    {
        cout<<"Enter Book Title:";
        cin>>title;
        cout<<"Enter Author name:";
        cin>>author;
        cout<<"Enter Book ISBN No.:";
        cin>>isbn;
    }
    void display()
    {
        cout<<"Book Title:" <<title<<endl;
        cout<<"Author Name:" <<author<<endl;
        cout<<"ISBN No.:" <<isbn<<endl<<endl;
    }
    void searchBookByTitle(const char* head)  //Search Book By Title
    {
        if(strcmp(head , title)==0)
        {
            display();
        }
    }
    void searchBookByAuthor(const char* aname)  //Search Book By Author
    {
        if(strcmp(aname,  author)==0)
        {
            display();
        }
    }
    void searchBookByISBN(int bnum)  //Search Book By ISBN Number
    {
        if(bnum == isbn)
        {
            display();
        }
    }

    void availBook(const char * tit)  //Check availability of Book
    {
        if(strcmp(tit, title)==0)
        {
            cout<<"Book is available";
        } 
    }
 };
 class Borrower:public Book
 {
    char borrower_name[20], book_name[30];
    int bid;
    int dd, mm, yy;
    int d, m, y;
    int days_lated;
    
    public:
    void b_accept()
    {
        cout<<"Enter Borrower Name:";
        cin>>borrower_name;
        cout<<"Enter Borrower ID:";
        cin>>bid;
        cout<<"Enter Book name that YOU WANT:";
        cin>>book_name;
        cout<<"Enter Book receiving date:";
        cin>>dd >>mm >>yy;
        cout<<"Enter Book Submission date:";
        cin>>d >>m >>y;
    }
    void b_display()
    {
        cout<<"Borrower Name:" <<borrower_name<<endl;
        cout<<"Borrower ID:" <<bid<<endl;
        cout<<"Book received date:" <<dd<<"/"<<mm<<"/"<<yy<<endl;
        cout<<"Book Submission date:"<<d<<"/"<<m<<"/"<<y<<endl;
        if(strcmp(book_name, title) == 0)
        {
            cout<<"Book Details:";
            display();
        }
    }

    void fineCalculate(int date, int month, int year, char* fineName)   //Fine calculation
    {
        if(strcmp(fineName, borrower_name)==0)
        cout<<"Enter real time submission date:";
        cin>>date>>month>>year;
        if(year > y || (year == y && month > m) || (year == y && month == m && date > d))
        {
            days_lated = (year-y) * 365 + (month-m) * 30 + (date - d);
            int fine = days_lated * 20;

            cout<<"You're Lated, you've to pay Overdue fine:"<<endl;
            cout<<"Fine is:"<<fine;
        }
        else {  
            cout<<"You have submitted book before submission date, WELL DONE";
        }

    }
    
 };

 int main()
 {
    int b,book_isbn;
    char book_title[20], book_author[20], tit[20];
    cout<<"Enter no. of books:";
    cin>>b;
    Book* books = new Book[b];
    int choice, i;
    bool foundauthor, foundtitle, foundisbn, foundavail;

    do 
    {
        cout<<"\n\n----------MENU----------\n\n1)Accept Book Details\n 2)Display Book Details\n 3)Display book details by TITLE\n 4)Display book details by AUTHOR\n 5)Display book details by ISBN\n 6)Check Book availability\n 7)For Borrower\n 8)Exit\n\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: for(i=0; i<b; i++)
                    {
                        cout<<"\nEnter Details of book" <<(i+1) <<":"<<endl;
                        books[i].accept();
                    }
                    break;

            case 2: cout<<"\nDetails of Books:\n";
                    for(i=0; i<b; i++)
                    {
                        cout<<"Detail of BOOK"<<(i+1)<<":"<<endl;
                        books[i].display();
                    }
                    break;

            case 3: cout<<"Enter Book title to Search:";
                    cin>>book_title;
                    foundtitle=false;
                    for(i=0; i<b; i++)
                    {
                        if(strcmp(book_title, books[i].title)==0)
                        {
                            cout<<"Detail of Searched Book:"<<endl;
                            books[i].searchBookByTitle(book_title);
                            foundtitle = true;
                            break;
                        }
                    }
                    if(!foundtitle)
                    {
                        cout<<"BOOK TITLE NOT FOUND"<<endl;
                    }
                    break;

            case 4: cout<<"Enter Book author to Search:";
                    cin>>book_author;
                    foundauthor=false;
                    for(i=0; i<b; i++)
                    {
                        if(strcmp(book_author, books[i].author)==0)
                        {
                            cout<<"Detail of Searched Book by Author:"<<endl;
                            books[i].searchBookByAuthor(book_author);
                            foundauthor = true;
                            break;
                        }
                    }
                    if(!foundauthor)
                    {
                        cout<<"AUTHOR NAME NOT FOUND"<<endl;
                    }
                    break;

            case 5: cout<<"Enter Book ISBN to Search:";
                    cin>>book_isbn;
                    foundisbn = false;
                    for(i=0; i<b; i++)
                    {
                        if(book_isbn == books[i].isbn)
                        {
                            cout<<"Detail of Searched Book by ISBN:"<<endl;
                            books[i].searchBookByISBN(book_isbn);
                            foundisbn = true;
                            break;
                        }
                    }
                    if(!foundisbn)
                    {
                        cout<<"INVALID ISBN!BOOK NOT FOUND"<<endl;
                    }
                    break;

            case 6: cout<<"Enter book name you want check available or not?";
                    cin>>tit;
                    foundavail=false;
                    for(i=0; i<b; i++)
                    {
                        if(strcmp(tit, books[i].title)==0)
                        {
                            books[i].availBook(tit);
                            foundavail=true;
                            break;
                        }
                    }
                    if(!foundavail)
                    {
                        cout<<"Books is not available"<<endl;
                    }
                    break;

            case 7: {
                    int n;
                    
                    int date, month, year;
                    char finename[20];
                    cout<<"Enter no. of borrower:";
                    cin>>n;
                    Borrower* bor = new Borrower[n];
                    int choice, i;
                    do 
                    {
                        cout<<"\n\n----------MENU----------\n\n 1)Accept Borrower's Detail\n 2)Display Borrower details\n 3)Check Book overdue or FINE\n 4)Exit\n\n";
                        cout<<"Enter your choice:";
                        cin>>choice;
                        switch(choice)
                        {
                             case 1: for(i=0; i<n; i++)
                                    {
                                        cout<<"Enter detail of borrower"<<(i+1)<<":"<<endl;
                                        bor[i].b_accept();
                                    }
                                    break;

                            case 2: for(i=0; i<n; i++)
                                    {
                                        cout<<"Details of borrower"<<(i+1)<<":"<<endl;
                                        bor[i].b_display();
                                    }
                                    break;

                            case 3: cout<<"Enter Borrower name:";
                                    cin>>finename;
                                    cout<<"Enter submission date, month, year:";
                                    cin>>date>>month>>year;
                                    for(i=0; i<n;i++)
                                    {
                                        bor[i].fineCalculate(date, month, year, finename);
                                    }
                                    break;
                                
                            case 4: cout<<"Exixting...";
                                    break;

                            default: cout<<"Invalid choice!";
                                        break;
            
                        }
                    } while(choice!=4);
                    delete[] bor;
                    break;
                }
                
            case 8: cout<<"Existing...";
                    break;

            default: cout<<"Invalid choice!";
                        break;
        }
    } while(choice!=8);
    delete[] books;

    return 0;

 }