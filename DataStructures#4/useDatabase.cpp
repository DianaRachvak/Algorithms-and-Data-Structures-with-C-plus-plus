/*
Diana Rachvak
Description: *Program "Book Database" using classes, separate
             compilation files, and overloaded operators*
             This is a C++ program that inmplements Book's Database
             entry, tests veriety of overloaded operators functions
             and constructors, uses maps, sets, and pairs as its
             structure.
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include "Books.h"
#include "BookDatabase.h"

using namespace std;

int main(){
    BookDatabase book;

    //file with Books Database
    ifstream infile("C:\\Users\\diana_000\\Documents\\C++HWs\\"
                    "AdvancedC++\\DataStractures\\DataStructures#4\\"
                    "book.txt");
    //file that checks all transactions
    ifstream incheck("C:\\Users\\diana_000\\Documents\\C++HWs\\"
                    "AdvancedC++\\DataStractures\\DataStructures#4\\"
                    "check.txt");
    if(!infile){ cout<<"File wasn't found"<<endl; }
    if(!incheck){ cout<<"incheck file wasn't found"<<endl; }

    string title, *authors, publisher;
    int numAuthors, year;

    //adds a new book to the database if it is not there already
    while(infile>>title>>numAuthors){
        authors = new string[numAuthors];
        for(int i=0; i<numAuthors; i++)
            infile>>authors[i];
        infile>>publisher;
        infile>>year;

        //Book's constructor
        Book b(title, publisher, year, authors, numAuthors);
        book.addBook(b);

        //free authors memory before next iteration of a loop
        delete [] authors;
    }

    //Prints a representation for a book database.
    cout<<"***************************************************"<<endl;
    cout<<"Books' database: "<<book<<endl<<endl;

    string findTitle, findAuthor, findPublisher, removeTitle;
    int findYear;

    //returns a reference to the Book object that
    //contains the given title
    incheck>>findTitle;
    cout<<"***************************************************"<<endl;
    cout<<"Reference to the Book object that contains "
                "the given title: "<<findTitle<<endl;
    cout<<"***************************************************"<<endl;
    Book t = book.searchByTitle(findTitle);
    cout<<t<<endl;

    //returns a set of Books by the given author.
    incheck>>findAuthor;
    cout<<"***************************************************"<<endl;
    cout<<"Set of Books by the given author: "<<findAuthor<<endl;
    cout<<"***************************************************"<<endl;
    set<Book> a = book.searchByAuthor(findAuthor);
    for(set<Book>::const_iterator it = a.begin(); it!= a.end();
        it++){
        cout<<*it<<endl;
    }

    //returns a set of Books that were published
    //before a given year.
    incheck>>findYear;
    cout<<"***************************************************"<<endl;
    cout<<"Set of Books that were published before a "
                "given year: "<<findYear<<endl;
    cout<<"***************************************************"<<endl;
    set<Book> bb = book.publishedBefore(findYear);
    for(set<Book>::const_iterator it1 = bb.begin(); it1!= bb.end();
        it1++){
        cout<<*it1<<endl;
    }

     //returns a set of Books that were published
     //by the given publisher
    incheck>>findPublisher;
    cout<<"***************************************************"<<endl;
    cout<<"Set of Books that were published by given "
                "publisher:"<<findPublisher<<endl;
    cout<<"***************************************************"<<endl;
    set<Book> c = book.searchByPublisher(findPublisher);
    for(set<Book>::const_iterator it2 = c.begin(); it2!= c.end();
        it2++)
        cout<<*it2<<endl;

    //Remove the book with the given title from the
    //database if it is there
    incheck>>removeTitle;
    cout<<"***************************************************"<<endl;
    cout<<"Title of a book title to be deleted: "<<removeTitle<<endl;

    Book r = book.searchByTitle(removeTitle);
    book.removeBook(r);

    //Prints a representation for a book database after deletion.
    cout<<"***************************************************"<<endl;
    cout<<endl<<"Books' database after deletion : "<<book<<endl;
}
