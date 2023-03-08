#ifndef VECTORLIBRARYH
#define VECTORLIBRARYH

#include "Book.h"
#include <vector>
using namespace std;

class VectorLibrary {
   public:
      VectorLibrary();

      int InsertSorted(const Book &newBook, int counter);

      void PrintLibrary() const;

    friend ostream& operator<<(ostream &out, VectorLibrary& n);

    friend istream& operator>>(istream &in, VectorLibrary& n);

   private:
   // vector library
   vector<Book> library;

};

#endif