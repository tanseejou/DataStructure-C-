#include "trolley.h"
#include <iostream>
#include <iomanip>

void Trolley :: displayTrolley()
{
	node *currNode = front;
	cout << "\n******* TROLLEY ******" << endl;
	cout << "\tTITLE\t\t\t\t\tAUTHOR\t\t\t\tPRICES($)" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	while(currNode!=NULL)
	{
		cout << left << setw(45) << currNode->title << setw(38) << currNode->author << setw(15) << currNode->price<< endl;
		currNode = currNode->next;
	}
}

void Trolley :: Enqueue(string bt, string ba, double bp)
{
	node *newptr = new node;
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
