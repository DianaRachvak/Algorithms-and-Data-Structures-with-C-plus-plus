//Books.h
#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
    private:
        string title;
        string publisher;
        int year;
        vector<string> authors;
    public:
        //default constructor needed for defaultBook in BookDatabase
        Book(){};

        //constructor with 5 parameters
        Book(const string &title, const string &publisher,
         int yearOfPublication, string *authors, int numOfAuthors)
        {
            this->title = title;
            this->publisher = publisher;
            this->year = yearOfPublication;
            for (int i = 0; i < numOfAuthors; i++){
                this->authors.push_back(authors[i]);
            }
        }

        //all the rest functions
        friend bool operator==(Book& b1, Book& b2);
        friend bool operator <(const Book& b1, const Book& b2);
        friend ostream& operator <<(ostream& os, const Book& b);
        vector<string> getAuthors();
        int getYear();
        string getTitle();
        string getPublisher();
};
#endif // !BOOKS_H
