#ifndef customer_h
#define customer_h

#include "booklist.h"
#include "trolley.h"
#include "sales.h"
#include "node.h"

#include <iostream>
class Customer{
	private:
		Sale sales;
		BookList book;
		Trolley trolley;
	public :
		Customer(node* head)
		{
			cout<<"A";
			book.head = head;cout<<"A";
			sales.back = NULL;cout<<"A";
			sales.front = NULL;cout<<"af";	
		}
		node *authorSearch(string);
		node *titleSearch(string);
		void calculateTotalAmount(Trolley *);
		void customerMenu();
		void display(){
			book.displayList();
		}
		
		nodeSale* getFront(){return sales.front;}
		nodeSale* getBack(){return sales.back;}
	
};

#endif
