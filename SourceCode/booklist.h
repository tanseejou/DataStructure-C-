//#include<graphics.h>

#ifndef booklist_h
#define booklist_h

#include "node.h"
class BookList{
	
	public :
		node *head;
		BookList (void){ head=NULL;}
//		~BookList(void);
		node *getHead(){return head;}
		bool isEmpty(){return (head==NULL);}
		node *authorSearch(string);
		node *titleSearch(string);
		void insert(string[], int);
		void deleteStock(string);
		void displayList(void);		
};

#endif
