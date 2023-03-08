#include "LinkedListLibrary.h"
#include <iostream>

LinkedListLibrary::LinkedListLibrary() {
   // Front of nodes list
   headNode = nullptr;
   lastNode = nullptr;
}

LinkedListLibrary::~LinkedListLibrary() {
   while(headNode != nullptr) {
      BookNode* tempNode = headNode->GetNext();
      delete headNode;
      headNode = tempNode;
   }
}

int LinkedListLibrary::InsertSorted(BookNode* newNode, int counter) {
   BookNode* currNode, nextNode;

   // Special case for head node
   if (headNode == nullptr || headNode->GetBookISBN() >= newNode->GetBookISBN()) {
      newNode->SetNext(headNode);
      headNode = newNode;
   }
   else {
      // Locate the node before insertion point
      currNode = headNode;

      while (currNode->GetNext() && currNode->GetNext()->GetBookISBN() < newNode->GetBookISBN()) {
         currNode = currNode->GetNext();
      }
      currNode->insertAfter(newNode);
   }

   ++counter;
   return counter;
}

void LinkedListLibrary::PrintLibrary() const {
   BookNode* currNode;

   currNode = headNode->GetNext();
   while (currNode != nullptr) {
      currNode->PrintBookInfo();
      cout << endl;
      currNode = currNode->GetNext();
   }
}


ostream& operator<<(ostream &out, LinkedListLibrary& n) {
    BookNode* currNode;

    currNode = n.headNode->GetNext();
    while (currNode != nullptr) {
        out << *currNode;
        // cout << endl;
        currNode = currNode->GetNext();
    }
}

istream& operator>>(istream &inputFS, LinkedListLibrary& n) {
    BookNode* currNode;
    int linkedListOperations = 0;


    string bookTitle;
    string bookAuthor;
    long long bookISBN;

    // Try to open file
    // inputFS.open("books.txt");

    while(getline(inputFS, bookTitle)) {
        inputFS >> bookISBN;
        inputFS.ignore(1, '\n');
        getline(inputFS, bookAuthor);

        // Insert into linked list
        currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
        linkedListOperations = n.InsertSorted(currNode, linkedListOperations);
        n.lastNode = currNode;

    }
}