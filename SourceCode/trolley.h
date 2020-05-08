#ifndef trolley_h
#define trolley_h

#include "node.h"

class Trolley{
	public:
		node *front;	
		node *back;	
		Trolley (void){front = NULL; back = NULL;}
		bool isEmpty(){return (back==NULL && front==NULL);}
		// destro the whole queue
		void destroyQueue(){
			node *temp = front;
			while(temp)
			{
				front = temp->next;
				delete temp;
				temp = front;
			}
		}
		void Enqueue(string, string, double);
		void Dequeue();
		void displayTrolley(void);
};

#endif
