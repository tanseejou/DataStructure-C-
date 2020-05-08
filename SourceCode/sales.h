#ifndef sales_h
#define sales_h

#include "nodeSale.h"

class Sale
{
	public : 
		nodeSale *front;
		nodeSale *back;
		Sale() {front = NULL; back = NULL;}
		bool isEmpty(){return (back==NULL && front==NULL);}
		// clear the whole Sale queue
		void destroyQueueSale(){
			nodeSale *temp = front;
			while(temp)
			{
				front = front->next;
				delete temp;
				temp = front;
			}
		}
		void EnqueueSale(string, string, double);
		void DequeueSale();
		void checkSale();
		void displaySale();
};

#endif
