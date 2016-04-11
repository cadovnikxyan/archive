#include "node.h"

node::node(node* l, node* r):lnext(l),rnext(r){
	this->weight=l->getWeight()+r->getWeight();
	this->symbol=0;
}

node::node(char s, int _weight):lnext(nullptr),rnext(nullptr){
	this->symbol=s;
	this->weight=_weight;
}
node::node():lnext(nullptr),rnext(nullptr){
	this->symbol=0;
	this->weight=0;
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


void node::setChar(char* s){
	this->symbol=(*s);
}


int node::getWeight()const{
	return this->weight;
}

char node::getChar()const{
	return this->symbol;
}
