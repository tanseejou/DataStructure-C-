#ifndef node_h
#define node_h
#include<string>
using namespace std;

class node{
	public :
		string author, title;
		double price;
		node *next;
};

#endif
