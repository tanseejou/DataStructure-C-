#include "customer.h"
#include "sales.h"

#include <iostream>

using namespace std;

node* Customer :: titleSearch(string input)
{
	return book.titleSearch(input);		
}

// Search the book based on author input by the customer
node* Customer :: authorSearch(string input)
{
	return book.authorSearch(input);
}


void Customer::calculateTotalAmount(Trolley *troll)
{
	double total = 0.0;
	node *currNode = troll->front;
	while(currNode!=NULL)
	{
		total += currNode->price;
		currNode = currNode->next;
	}
	cout << "\n\nTOTAL AMOUNT	: $ " << total << endl;
	if(total >200)
	{
		cout << "20 % discount" << endl;
		total = total*0.8;
		cout << "TOTAL AMOUNT AFTER DISCOUNT	: $ " << total << endl << endl;
	}
}

void Customer::customerMenu()
{
	cout << "__________________________________________________________________________" << endl << endl << endl;
				cout << "\n\nGood day, my dearest customer : " << endl << endl;
				cout << "\t\t\t     U T M BOOK SHOP " << endl;
				cout << "\t\t\tWELCOME TO OUR BOOK SHOP " << endl << endl;
				cout << "\t\t\t    = Main Menu =" << endl << endl;
				cout << "\t\t\t    a. Book List" << endl;
				cout << "\t\t\t    b. Search Book" << endl;
				cout << "\t\t\t    c. Buy Book" << endl;
				cout << "\t\t\t    d. Return to main menu" << endl;
				cout << "\t\t\t    e. Exit" << endl;
				cout << "\t\t     Please enter your choice :";
}


///////////////// STAFF CHOICES FUNCTION /////////////////////




