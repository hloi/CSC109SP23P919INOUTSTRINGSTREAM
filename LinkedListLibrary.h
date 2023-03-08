#ifndef LINKEDLISTLIBRARYH
#define LINKEDLISTLIBRARYH

#include "BookNode.h"
using namespace std;

class LinkedListLibrary {
   public:
      //Linked list nodes
      BookNode* headNode;
      BookNode* lastNode;

      LinkedListLibrary();

      ~LinkedListLibrary();

      int InsertSorted(BookNode* newNode, int counter);

      void PrintLibrary() const;

    friend ostream& operator<<(ostream &out, LinkedListLibrary& n);

    friend istream& operator>>(istream &in, LinkedListLibrary& n);


};

#endif