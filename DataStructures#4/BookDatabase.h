//BookDatabase.h
#ifndef BOOKDATABASE_H
#define BOOKDATABASE_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include "Books.h"

using namespace std;
class BookDatabase
{
    private:
        map <string,Book> bookData;
        Book defaultBook;
    public:
        //default constructor
        BookDatabase() : defaultBook(){}

        Book& searchByTitle(const string& title);
        set<Book> searchByAuthor(const string& author);
        set<Book> publishedBefore(int year);
        set<Book> searchByPublisher(const string& publisher);
        void addBook(Book &book);
        void removeBook(Book& book);
        friend ostream& operator <<(ostream &os, BookDatabase& bD);
};
#endif // !BOOKDATABASE_H
