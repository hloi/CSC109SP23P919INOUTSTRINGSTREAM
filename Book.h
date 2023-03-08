#ifndef BOOKH
#define BOOKH
#include <iostream>
#include <string>
using namespace std;

class Book{
   public:
      Book();

      Book(string userBookTitle, string userBookAuthor, long long userBookISBN);

      long GetBookISBN() const;

      void PrintInfo() const;

    friend ostream& operator<<(ostream &out, Book& n);

private:
      string bookTitle;
      string bookAuthor;
      long long bookISBN;
};

#endif