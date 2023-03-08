#include "Book.h"
#include <iostream>

Book::Book() {
   bookTitle = "";
   bookAuthor = "";
   bookISBN = 0;
}

Book::Book(string userBookTitle, string userBookAuthor, long long userBookISBN) {
   bookTitle = userBookTitle;
   bookAuthor = userBookAuthor;
   bookISBN = userBookISBN;
}

long Book::GetBookISBN() const{
   return bookISBN;
}

void Book::PrintInfo() const{
   cout << "Title: " << bookTitle << endl;
   cout << "Author: " << bookAuthor << endl;
   cout << "ISBN: " << bookISBN << endl;
}

ostream& operator<<(ostream &out, Book& n) {
    out << "Title: " << n.bookTitle << endl;
    out << "Author: " << n.bookAuthor << endl;
    out << "ISBN: " << n.bookISBN << endl;
    return out;
}