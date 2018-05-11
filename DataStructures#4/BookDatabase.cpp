//BookDatabase.cpp
#include "BookDatabase.h"

//searches for a book by its title and returns Book object, if found
//and empty object otherwise
Book & BookDatabase::searchByTitle(const string & title)
{
    if(bookData.count(title)) //if title matched with a databases tile
        return bookData[title]; //returns Book object's value
    return defaultBook;
}

//searches for a specific author in a database and returns
//a set of all books written by requested author
set<Book> BookDatabase::searchByAuthor(const string & author)
{
    set<Book> s;
    for (map <string,Book>::iterator it = bookData.begin();
         it != bookData.end(); it++)
    {
        Book b = it->second;
        //stores all authors in a vector and then compares database a
        //author to a requested author. Once authors mached, inserts
        //the Book objects of matched authors into a set
        vector<string> authors = b.getAuthors();
        for (int i=0; i<authors.size(); i++){
            if(authors[i]==author){
                s.insert(b);
            }
        }
    }
    return s;
}

//searches through the BookDatabase for book published before
//requested year and returns a set of books published before that year
set<Book> BookDatabase::publishedBefore(int year)
{
    set<Book> s;
    for (map <string,Book>::iterator it = bookData.begin();
         it != bookData.end(); it++)
    {
        Book b = it->second;
        //if it finds a book with year before requested year,
        //it inserts it into a set of Book objects
        if (b.getYear() < year)
        s.insert(b);
    }
    return s;
}

//searches through the whole database of books and returns a set
//with all books from a given publisher
set<Book> BookDatabase::searchByPublisher(const string & publisher)
{
    set<Book> s;
    for (map <string,Book>::iterator it = bookData.begin();
         it != bookData.end(); it++){
            Book b = it->second;
            //if it finds an equivalent publisher, it inserts it into
            //a set of Book objects
            if (b.getPublisher() == publisher)
            s.insert(b);
    }
    return s;
}

//adds book to the BookDatabase
void BookDatabase::addBook(Book & book)
{
    bookData.insert(pair<string,Book>(book.getTitle(), book));
}

//removes a book with a specific title from a database,
//using map function erase()
void BookDatabase::removeBook(Book & book)
{
    bookData.erase(book.getTitle());
}

//prints a representation of the whole book database
ostream & operator<<(ostream & os, BookDatabase& bD)
{
    for (map <string,Book>::iterator it = bD.bookData.begin();
         it != bD.bookData.end(); it++)
    {
        Book b = it->second;
        os << "Title: " << b.getTitle() << endl;

        //using vector to store all authors
        vector<string> authors = b.getAuthors();
        os<<"Authors: ";
        for (int i = 0; i < authors.size(); i++)
            os << authors[i] << " ";
        os << endl;
        os << "Publisher: " << b.getPublisher() << endl;
        os << "Year: " << b.getYear() <<endl<<endl<<endl;
    }
    return os;
}
