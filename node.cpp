#include "node.h"



node::node(node* l, node* r):lnext(l),rnext(r){
	this->weight=l->getWeight()+r->getWeight();
	this->symbol=0;
}

node::node(char s, int _weight):lnext(nullptr),rnext(nullptr){
	this->symbol=s;
	this->weight=_weight;
}
node::node(){
	
}
int node::count=0;

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
		return str+=symbol;
}

void node::setChar(char* s){
	this->symbol=(*s);
}

node node::operator+(const node& n){
	
	node m;
	m.weight=this->weight+n.weight;
		
	return m;
	
}

int node::getWeight()const{
	return this->weight;
}

char node::getChar()const{
	return this->symbol;
}
