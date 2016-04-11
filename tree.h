#ifndef TREE_H
#define TREE_H
#include <map>
#include <list>
#include "node.h"
#include <fstream>

using namespace std;


class tree
{
	
	list<node*> 			 _tree;
	node* root;
	map<char,int> 			 dic;
	map<char, vector<bool> > tcode;
	vector<bool> 			 code;
	
	void 					 createDic(string* str);	
	void 					 createTree(list<node*>& __tree );
	void 					 buildCodeTable(node* _root);	
	
	public:
		
		tree(map<char,int>& _dic);
		tree(string* str);
	   ~tree();
				
	void 					 printTree();
	map<char,vector<bool> >& getCode();
	
	node* 					 getRoot() const;
	void 					 writeTree()const;
	void 					 writeTree(ofstream& stream)const;
	
};

#endif
