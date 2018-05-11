//Books.cpp
#include "Books.h"
using namespace std;

//rather straightforward inline functions
vector<string> Book::getAuthors() { return this->authors; }
int Book::getYear() { return year; }
string Book::getTitle() { return title; }
string Book::getPublisher() { return publisher; }
bool operator==(Book& b1, Book& b2) {return b1.title == b2.title;}
bool operator<(const Book& b1, const Book& b2)
              {return b1.title < b2.title;}

//prints all values of Book class
ostream & operator<<(ostream& os, const Book& b)
{
    os << "Title: " << b.title << endl;
    for (int i = 0; i < b.authors.size(); i++)
        os << b.authors[i] << " ";
    os << endl;
    os << "Publisher: " << b.publisher << endl;
    os << "Year: " << b.year << endl;
    return os;
}
