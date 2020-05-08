#ifndef nodeSale_h
#define nodeSale_h
#include<string>
using namespace std;

class nodeSale{
	public :
		string author, title;
		double price;
		nodeSale *next;
};

#endif
