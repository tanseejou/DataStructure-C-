#ifndef staff_h
#define staff_h

#include "booklist.h"
#include "sales.h"
#include "customer.h"


class Staff{
	private:
		Sale* sales;
		BookList book;
	public:
		Staff(void)
		{

		}
		void setSale(nodeSale* _front, nodeSale* _back)
		{

			sales->front = _front;
			sales->back = _back;
		}
		void insert(string[], int);
		void deleteStock(string);	
		
		void staffMenu();
};

#endif
