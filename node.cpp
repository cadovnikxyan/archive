#include "node.h"

node::node(word* w):lnext(0),rnext(0){
	symbol.push_back(w->wsymbol);
	weight=w->wcount;
}
node::node(){
}


node::~node(){
	
}

node* node::getLnextNode() const{
	return this->lnext;
}
node* node::getRnextNode() const{
	return this->rnext;
}

void node::setLNext(node* n){
	this->lnext=n;
}

void node::setRNext(node* n){
	this->rnext=n;
}

void node::writeBit(bool b){
	
	this->indexNode=b;
}

bool node::getIndexNode()const{
	return this->indexNode;
}
string node::toString()const{
		
		string str;
		for(int i=0;i<symbol.size();++i){
			str+=symbol[i];
		}
		return str;
}

void node::setChar(char* s){
	this->symbol.push_back(*s);
}

node node::operator+(const node& n){
	
	node m;
	vector<char> buf=this->symbol;
	m.weight=this->weight+n.weight;
	for(int i=0;i<n.symbol.size();++i){
		buf.push_back(n.symbol[i]);
	}
	m.symbol=buf;
	return m;
	
}

int node::getWeight()const{
	return this->weight;
}
