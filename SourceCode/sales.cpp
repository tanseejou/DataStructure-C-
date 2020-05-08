#include "sales.h"

#include <iostream>
#include <iomanip>

void Sale :: EnqueueSale(string bt, string ba, double bp)
{
	nodeSale *newptr = new nodeSale;
	newptr->title = bt;
	newptr->author = ba;
	newptr->price = bp;
	
	
	if(front==NULL){
		
		front = back = newptr;	
	}
	else 
	{
		newptr->next = NULL;			
		back->next = newptr;
		back = newptr;
	}
}


void Sale :: displaySale()
{
	
	nodeSale *currNode = front; 
	cout << "\n SALE " << endl;
	cout << "\tTITLE\t\t\t\t\tAUTHOR\t\t\t\tPRICES($)" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	
	while(currNode!=NULL)
	{
		cout << left << setw(45) << currNode->title << setw(38) << currNode->author << setw(15) << currNode->price<< endl;
		currNode = currNode->next;
	}
}

void Sale :: DequeueSale()
{
	nodeSale *temp;
	if(front==NULL)
	{
		cout << "\nThe sale is empty." << endl;
		return ;
	}
	if(front ==  back)
		front = back = NULL;
	else 
	{
		temp = front;
		front = front->next;
		temp->next = NULL;
		delete temp;
	}
	
	
		
}

void Sale::checkSale()
{
	displaySale();

	int clearSale;
	cout << "\nDo you want to delete sale record ?";
	cout << "\n1. Clear all the sale record.";			// PLEASE CHANGE THE DISPLAY WORD.
	cout << "\n2. Clear the earliest record.";			// WEIRD
	cout << "\n3. No" << endl; 
	cin >> clearSale;
					
	if(clearSale==1)
	{
		destroyQueueSale();
		displaySale();
	}
		
	else if(clearSale==2)
	{
		DequeueSale();
		displaySale();
	}
		
	else if(clearSale==3)
		cout << "All record are keeping." << endl;
	else 
		cout << "Invalid input " << endl;
}
