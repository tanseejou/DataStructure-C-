#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>

#include "booklist.h"
#include "trolley.h"
#include "customer.h"
#include "staff.h"
#include "node.h"

using namespace std;

ifstream bookFiles;
void customerDecision (char decision, Customer *customer, BookList *b, Trolley *trolley, Sale *sales)
{
	char searchChoice;
	string desiredBook;
		
	switch(decision)
	{
		case 'a': cout << endl << endl;	// display the booklist	
				customer->display();
				cout << endl << endl;	
		break;
		
		case 'b': cout << "\n\t\t\t Book Search by ..." << endl;		// customer choose the book search option 
				cout << "\t\t\t1. Book Title " << endl;				// customer can search by the book title or book author
				cout << "\t\t\t2. Author's name" << endl;
				cout << "\t\t     Please enter your choice : ";
				cin >> searchChoice;
			
				
				if(searchChoice=='1')
				{
					string bt;
					cout << "\n\t\t     Please enter the book title : ";
					cin.ignore();
					getline(cin,bt);	
					for(int i=0; i<bt.length(); i++)
					{bt[i] = toupper(bt[i]);}
					customer->titleSearch(bt);
				}
				else if(searchChoice=='2')
				{
					string at;
					cout << "\n\t\t     Please enter the author name : ";
					cin.ignore();
					getline(cin,at);
					for(int i=0; i<at.length(); i++)
					{at[i] = toupper(at[i]);}	
					customer->authorSearch(at);
				}  
				else 					
					{
						cout << "\n\t\t     Invalid input." << endl;
						break;
					}
				
		break;
		
				// buy book
		case 'c': 
				cin.ignore();
				book:
				cout << "\n\t\t\tPlease enter the desired book title ..." << endl;
				cout << "\t\t\tand the book will be add to trolley." << endl;
				cout << "\t\t\tBook Title : ";
				getline(cin, desiredBook);
				for(int i=0; i<desiredBook.length(); i++)
				{desiredBook[i] = toupper(desiredBook[i]);}
				
				char addCart, confirmStatus;
				double totalAmount;
				cout<<desiredBook<<endl;
				if(customer->titleSearch(desiredBook))
				{
					node *temp = customer->titleSearch(desiredBook);
						
					cout << "\nBook found! Add to trolley ? " << endl;
					cout << "Please insert 'Y - yes'  and  'N - no' " << endl;
					cin >> addCart;
					if(addCart == 'Y' || addCart == 'y')
					{
						trolley->Enqueue(temp->title, temp->author, temp->price);
						trolley->displayTrolley();
						
						cout << "\nConfirm buy and calculate the total amount?" << endl;
						cout << "Please insert 'Y - yes'  and  'N - no' " << endl;
						cin >> confirmStatus;
						
						if(confirmStatus == 'Y' || confirmStatus == 'y')
						{
							customer->calculateTotalAmount (*&trolley) ;
							node *currNode = trolley->front;
							while(currNode!=NULL)
							{
								sales->EnqueueSale(currNode->title, currNode->author, currNode->price);
								b->deleteStock(currNode->title);
								currNode = currNode->next;
							}
							trolley->destroyQueue();
						}
						else if(confirmStatus == 'N' || confirmStatus == 'n')
						{
							cout<<"Enter a book title again"<<endl;
							cin.ignore();
							goto book;
						}
						
					}
					else if(addCart == 'N' || addCart == 'n')
						cout << "\nBook not added to trolley" << endl<< endl;
					else 
						cout << "Invalid input." << endl << endl;
				}
				else 
					cout << "\nBook not found. Please make sure you enter the correct book title. " << endl<< endl;
		
		break;
		
		case 'd': break;
		case 'e':	
			{
				cout << "Thank You ! Please come again !" << endl;
				exit(0);	
			}
		
		
		default : cout << "Invalid choice." << endl; 
		break;
	}
	
	
}

void staffDecision(char decision, BookList *b, Sale *sales, Staff *staff)
{	

	string arr[3];
	string t, a, p;
	switch (decision)
	{
		// Adding new book to the book list
		case 'A' :
		case 'a' : 	cout << "\n\nTo adding new book to the book list, please insert the following details correctly : " << endl;
					cout << "Book Title	: ";
					cin.ignore();
					getline(cin, t);
					for(int i=0; i<t.length(); i++)
					{
						t[i] = toupper(t[i]);
					}
					arr[0] = t;
					
					cout << "Author		: ";
					getline(cin, a); 
					for(int i=0; i<a.length(); i++)
					{
						a[i] = toupper(a[i]);
					}
					arr[1] = a;
					
					cout << "Price		: $ " ;
					getline(cin, p);
					for(int i=0; i<p.length(); i++)
					{
						p[i] = toupper(p[i]);
					}
					arr[2] = p;
					
					staff->insert(arr,3);
					cout << "\n\nThis is the latest book list. Please check the details of the book. "<< endl;
					b->displayList();
					
		break;
		
		// remove book from the book list
		case 'B' :
		case 'b' :	cout << "\n\nTo remove the book from the book list, please insert the following details correctly : " << endl;
					cout << "Book Title : ";
					cin.ignore();
					getline(cin,t);
					for(int i=0; i<t.length(); i++)
					{
						t[i] = toupper(t[i]);
					}
					staff->deleteStock(t);
					cout << "This is the latest book list. Please check the details of the book. "<< endl;
					staff->displayList();
		
		break;
		
		// check sale
		case 'C' :
		case 'c' : staff->checkSale();
		break;
		
		// print sale
		case 'D' :
		case 'd' : staff->displaySale();
		break;
		
		case 'F' :
		case 'f' : 	cout << "\nThank you ! You are a wonderful part of our team ! KEEP GOING !" << endl;
					exit(0);
	}
	

		
}

char choosePosition()
{
	char position;
	cout << "\t\t\t     U T M BOOK SHOP " << endl;
	cout << "\t\t\tWELCOME TO OUR BOOK SHOP " << endl << endl;
	cout << "\t\t\t    = Main Menu =" << endl << endl;
	cout << "\t\t       Are you a customer or staff ?" << endl;
	cout << "\t\t\t    a. Customer " << endl;
	cout << "\t\t\t    b. Staff" << endl;
	cout << "\t\t\t    c. Exit" << endl; 
	cout << "\t\t       Please enter your choice : ";
	cin >> position;
	
	while(position <'a' || position>'c' )
	{
		cout << "\t\t  Invalid input! Please enter a, b, or c :";
		cin >> position;
	}	
	return position;
}
int main()
{
	
	bookFiles.open("BOOK.txt");
	if(!bookFiles)
	{
		cout << "ERROR! Cannot open the file.";
		return 0;
	}
	
	
	Trolley trolley;
	BookList b;	
	Staff staff;
	Sale sales;
	
	string line;
	cout << setprecision(2) << fixed;
	while(getline(bookFiles, line, '\n')){
		int size = 3;	
		stringstream linestream(line);
		string temp;
		string detail [size];
		int i=0;
		while (getline(linestream, temp, ','))
		{
			detail[i]=temp;
			i++;
		}
		b.insert(detail,3);
		
	}
	cout<<"a";
	//node * head = b.getHead();cout<<"a";
	Customer customer(b.getHead());

	char position, custChoice;
	char staffChoice;
	
	cout << endl << endl << endl;
	

start:
	{
		
	do{
		position = choosePosition();
			
	switch (position)
	{
		case 'a': 
				here:
				customer.customerMenu();
				cin >> custChoice;
				if(custChoice == 'd')
				{
					goto start;
				}
				else
					
					customerDecision(custChoice,&customer, &b, &trolley, &sales);
					if(custChoice != 'e')
					{
						goto here;
					}				
		break;
		
		case 'b': 
				staff:
				staff.staffMenu();
				cin >> staffChoice;
				if((staffChoice == 'F') || (staffChoice == 'f'))
				{
					goto start;
				}
				else
					staffDecision (staffChoice, &b, &sales, &staff);
					if(staffChoice != 'e')
					{
						goto staff;
					}
		break;
		
		case 'c': cout << "You had choose to quit. Good bye ~" << endl;
		return 0;
		
		default : cout << "Invalid choice." << endl; 
		break;
	}

	} while(position !=3);
		
	}
		
	

	
	return 0;
}



