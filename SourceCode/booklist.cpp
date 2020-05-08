#include "booklist.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
//using namespace std;

node* BookList :: titleSearch(string input)
{
	node *currNode = head;
	while(currNode && currNode->title != input)
		currNode = currNode->next;
	if(currNode)
	{
		cout << "\n\t\t\t    *** FOUND!!! ***" << endl;
		cout << "\t\t\tTitle	: " << currNode->title << endl;
		cout << "\t\t\tAuthor	: " << currNode->author << endl;
		cout << "\t\t\tPrice	: $ " << currNode->price << endl;
		return currNode;
	}
	else 
	{
		cout << "\n\t\t\t*** Book NOT FOUND ***." << endl;
		return NULL;
	}
		
}

// Search the book based on author input by the customer
node* BookList :: authorSearch(string input)
{
	node *currNode = head;
	while(currNode && currNode->author != input)
		currNode = currNode->next;
	if(currNode)
	{
		cout << "\n\t\t\t    *** FOUND!!! ***" << endl;
		cout << "\t\t\tTitle	: " << currNode->title << endl;
		cout << "\t\t\tAuthor	: " << currNode->author << endl;
		cout << "\t\t\tPrice	: $ " << currNode->price << endl;
		return currNode;
	}
	else 
	{
		cout << "\n\t\t\t*** Book NOT FOUND ***." << endl;
		return NULL;
	}
		
}

// method used for insertion book 
// and the books is sorted alphabetically
void BookList :: insert(string arrDetail[], int size){
	node *currNode = head;
	node *prevNode = NULL;
	node *newNode = new node;
	
	newNode->title = arrDetail [0];
	newNode->author = arrDetail [1];
	string sprice = arrDetail[2];
	newNode->price = atof(sprice.c_str());

	while(currNode && (newNode->title > currNode->title)){
		prevNode = currNode;
		currNode = currNode->next;
	}
	
	if(prevNode==NULL){
		newNode->next = head;
		head = newNode;
			
	}
	else
	{
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}	
}

// method used for display the whole book list
void BookList :: displayList()
{

	node *currNode = head;
	cout << "\tTITLE\t\t\t\t\tAUTHOR\t\t\t\tPRICES($)" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	while(currNode!=NULL)
	{
		cout << left << setw(45) << currNode->title << setw(38) << currNode->author << setw(15) << currNode->price<< endl;
		currNode = currNode->next;
	}
}

// method used for remove certain book from the book list. 
void BookList :: deleteStock(string t)
{
	node *prevNode = NULL;
	node *currNode = head;
	
	if(isEmpty())
		cout << "\nBook list is empty!" << endl;
			
	while (currNode && currNode->title!=t)
	{
		prevNode = currNode;
		currNode = currNode->next;
	}
	
	if(currNode)
	{
		if(prevNode)
		{
			prevNode->next = currNode->next;
			delete currNode;
		}
		else
		{
			head = currNode->next;
			delete currNode;	
		}
	}
	
}

