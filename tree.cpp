#include "tree.h"



tree::tree(map<char,int>& _dic){
	
	for(map<char,int>::iterator it= _dic.begin();it!= _dic.end();++it){
		_tree.push_back(new node(it->first,it->second));
	}
		createTree(_tree);
}

tree::tree(string* str){
	
	string::iterator its=str->begin();		
		for(;its!=str->end();++its){					
				dic[*its]++;				
		}	
	for(map<char,int>::iterator it= dic.begin();it!= dic.end();++it){
		_tree.push_back(new node(it->first,it->second));
	}
	createTree(_tree);
}

tree::~tree(){
	delete root;
}


void tree::printTree(){
		map<char, vector<bool> >::iterator itc=tcode.begin();
		for(;itc!=tcode.end();++itc){
			cout<<itc->first<<endl;
			vector<bool> b=itc->second;
			for(int i=0;i<b.size();++i){
				cout<<b[i];
			}
			cout<<endl;
		}
}

struct MyCompare
{
    bool operator()(const node* l, const node* r) const{
	 return l->getWeight() < r->getWeight();
	}
};

void tree::createTree(list<node*>& __tree ){
	
	while(__tree.size()!=1){
		
		__tree.sort(MyCompare());
		
		node* l=__tree.front();
		__tree.pop_front();
		node* r=__tree.front();
		__tree.pop_front();
		
		node* p= new node(l,r);
					
		__tree.push_back(p);
						
	}		
		root=__tree.front();
		buildCodeTable(root);					
}

node* tree::getRoot()const{
	return this->root;
}


void tree::buildCodeTable(node* _root){
	
	if(_root->getLnextNode()!=nullptr){
		code.push_back(0);
		buildCodeTable(_root->getLnextNode());
	}
	if(_root->getRnextNode()!=nullptr){
		code.push_back(1);
		buildCodeTable(_root->getRnextNode());
	}
	if(_root->getLnextNode()==nullptr && _root->getRnextNode()==nullptr){		
		tcode[_root->getChar()]=code;
	}		
		code.pop_back();
}


map<char,vector<bool> >& tree::getCode(){

	return this->tcode;
}


void tree::writeTree()const{
	ofstream t("output.tree",ios::out);
		map<char, vector<bool> >::iterator it= this->tcode.begin();
			while(it!=this->tcode.end()){
				t<<it->first;
					string str;
					vector<bool> b=it->second;
						for(int i=0;i<b.size();++i){
							if(b[i]){
								str+="1";
							}else{
								str+="0";
							}
						}
						t<<str<<endl;
						++it;
			}
}
void tree::writeTree(ofstream& stream)const{
		map<char, vector<bool> >::iterator it= this->tcode.begin();
			while(it!=this->tcode.end()){
				stream<<it->first;
					string str;
					vector<bool> b=it->second;
						for(int i=0;i<b.size();++i){
							if(b[i]){
								str+="1";
							}else{
								str+="0";
							}
						}
						stream<<str<<endl;
						++it;
			}
}

void tree::createDic(string* str){
						
	string::iterator it=str->begin();		
		for(;it!=str->end();++it){					
				dic[*it]++;				
		}
				
}


