#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;





class node
{
		
	node* lnext;
	node* rnext;
	char  symbol;
	int   weight;
	
	public:		
		node(node* l,node* r);
		node(char s, int _weight);
		node();
	   ~node();		
		
		node* getLnextNode() const;
		node* getRnextNode() const;
		int   getWeight()const;
		char  getChar()const;
		
		void  setLNext(node* n);
		void  setRNext(node* n);
		void  setChar(char* s);


};

#endif
