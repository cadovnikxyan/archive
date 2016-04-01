#include "tree.h"

tree::tree(dictionary& dic){
	size=dic.getSize();
	init(dic.getWord(),size);	
}

tree::~tree(){
	delete[] _tree;
}

void tree::init(word* w, int wsize){
	
	int m= (wsize%2)? 0 : -1;
	size = wsize*2+m;
	_tree=new node[size];

	int left=0,rsize;
	int lleft=wsize;
	
	cout<<"size: "<<size<<" wsize: "<<wsize<<endl;
	
	if(!(size%2)){
		 rsize=size-1;
		_tree[rsize]=&w[wsize-1];
		root=&_tree[rsize];
	}
	for(int i=0;i<rsize;++i){
		
		if((i>=wsize)){
				createTree(i,left,0);							

				if(i>=(wsize+wsize/2)){					
					createTree(i,lleft,wsize);
				}
		}else{			
			_tree[i]= &w[i];			
		}		
	}
	int buf=rsize-1;
	// тут косяк с инициализацией рута
	createTree(rsize,buf,0);
		
}


void tree::printNode(int n){
	cout<<_tree[n].toString();
}

void tree::printTree(){
	int count=0;
	for(int i=0;i<size;++i){
		
		if((_tree[i].getLnextNode()!=0)&&(_tree[i].getRnextNode()!=0)){
			cout<<_tree[i].getLnextNode()->toString()<<" "<<_tree[i].getLnextNode()->getWeight()<<endl;
			cout<<"\t"<<_tree[i].getRnextNode()->toString()<<" "<<_tree[i].getRnextNode()->getWeight()<<endl;
			++count;	
		}else{
			cout<<_tree[i].toString()<<" "<<_tree[i].getWeight()<<endl;		
		}
	}
	cout<<"count: "<<count<<endl;
}

void tree::createTree(int i,int& left, int wsize){

	
	if((wsize+left)!=size){
	int right=left+1;
		_tree[i]=_tree[wsize+left]+_tree[wsize+right];
				
				_tree[i].setLNext(&_tree[wsize+left]);
				_tree[i].setRNext(&_tree[wsize+right]);
								
				_tree[wsize+left].writeBit(true);
				_tree[wsize+right].writeBit(false);
				
				left+=2;
				
		
	}
	
}

node* tree::getRoot()const{
	return this->root;
}

int tree::getSize()const{
	return this->size;
}
