#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include "word.h"

using namespace std;

class node
{
	bool indexNode;	
	node* lnext;
	node* rnext;
	vector<char> symbol;
	int weight;
	
	public:		
		node(word* w);
		node();
		~node();		
		
		string toString() const;
		node* getLnextNode() const;
		node* getRnextNode() const;
		bool getIndexNode() const;
		int getWeight()const;
		
		void setLNext(node* n);
		void setRNext(node* n);
		void writeBit(bool b);
		void setChar(char* s);
		
		node operator+(const node& n);

};

#endif
