#ifndef TREE_H
#define TREE_H
#include <map>
#include <list>
#include "node.h"
#include "dictionary.h"

using namespace std;


class tree
{
	
	list<node*> _tree;
	node* root;
	map<char, vector<bool> > tcode;
	vector<bool> code;
	
		
	void createTree(list<node*>& __tree );
	void buildCodeTable(node* _root);	
	
	public:
		tree(map<char,int>& _dic);
		~tree();
				
		void printTree();
		node* getRoot() const;
		map<char,vector<bool> >& getCode();
		
	
};

#endif
