#ifndef TREE_H
#define TREE_H
#include <map>
#include "node.h"
#include "dictionary.h"

using namespace std;


class tree
{
	
	node* _tree;
	node* root;
	int size;	
	void init(word* w, int wsize);
	void createTree(int i,int& left, int wsize );	
	public:
		tree(dictionary& dic);
		~tree();
		
		void printNode(int n);
		void printTree();
		node* getRoot() const;
		int getSize()const;
	
};

#endif
