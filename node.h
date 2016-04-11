#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;





class node
{
	bool indexNode;	
	node* lnext;
	node* rnext;
	char symbol;
	int weight;
	static int count;
	
	public:		
		node(node* l,node* r);
		node(char s, int _weight);
		node();
		~node();		
		
		string toString() const;
		node* getLnextNode() const;
		node* getRnextNode() const;
		bool getIndexNode() const;
		int getWeight()const;
		char getChar()const;
		
		void setLNext(node* n);
		void setRNext(node* n);
		void writeBit(bool b);
		void setChar(char* s);
		node operator+(const node& n);


};

#endif
