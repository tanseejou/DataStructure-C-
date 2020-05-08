#include "staff.h"
#include "sales.h"

#include <iostream>
#include <cstdlib>
using namespace std;

void Staff::insert(string arrDetail[], int size)
{
	book.insert(arrDetail,size);
}

void Staff :: deleteStock(string t)
{
	book.deleteStock(t);
}


void Staff::staffMenu()
{
	cout << "__________________________________________________________________________" << endl << endl << endl;
				cout << "\n\nGood day, my dearest employee : " << endl << endl;
				cout << "\t\t\t     U T M BOOK SHOP " << endl;
				cout << "\t\t\tWELCOME TO OUR BOOK SHOP " << endl << endl;
				cout << "\t\t\t    = Main Menu =" << endl << endl;
				cout << "\t\t\t    a. Add Book" << endl;
				cout << "\t\t\t    b. Remove Book" << endl;
				cout << "\t\t\t    c. Check Sale" << endl;
				cout << "\t\t\t    d. Print Sale Report " << endl;
				cout << "\t\t\t    e. Return to main menu" << endl;
				cout << "\t\t\t    f. exit "<< endl;
				cout << "\t\t     Please enter your choice :";
}
