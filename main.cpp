#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "stdlib.h"
#include <algorithm>
#include "dictionary.h"
#include "tree.h"

using namespace std;
	
		
char* CStyleFileRead(const char* filepath, int* _fsize ){
	
	FILE* file = fopen(filepath,"rb");
	fseek(file,0,SEEK_END);
	long fsize=ftell(file);
	rewind(file);
	char* buf= (char*) malloc(fsize);	
	size_t result=fread(buf,1, fsize,file);
	*_fsize=result;
	printf("%i \n",result);
		
	return buf;
}

string* CppStyleFileRead(const char* filepath){
	
	static std::string* str=new std::string(
	(std::istreambuf_iterator<char>
	(*(std::auto_ptr<std::ifstream>(new std::ifstream(filepath)))
	.get())),
    std::istreambuf_iterator<char>());
	return str;		
}


void createDic(map<char,int>& dic,map<char,int>::iterator& itm, string* str){
			
			
		string::iterator it=str->begin();		
		for(;it!=str->end();++it){		
			string buf(str->begin(),it);			
			if(buf.find(*it)==(-1)){
				dic.insert(itm,pair<int,int>(*it,1));	
				
			}else{
				dic[*it]++;
				
			}			
		}
		itm=dic.begin();
}

void p(node* n){
	cout<<"root: "<<n->toString()<<endl;
	cout<<"left: "<<n->getLnextNode()->toString()<<endl;
//	cout<<"right: "<<n->getRnextNode()->toString()<<endl;
		p(n->getLnextNode());
//		p(n->getRnextNode());
	if(n->getLnextNode()==0){
		return ;
	}
}

int main(int argc, char** argv) {
	
	map<char,int> dic;
	map<char,int>::iterator it=dic.begin();

	
	string* str= new string("wwwwdwwxzwqhhqqaaahaaxxnxqq/][]");		
	createDic(dic,it,CppStyleFileRead("main.cpp"));
//	createDic(dic,it,str);
	dictionary* d= new dictionary(dic,dic.size());
	tree* t= new tree(*d);
	cout<<"tree size: "<<t->getSize()<<endl;
//	t->printTree();
	cout<<"-----------------------------"<<endl;
	p(t->getRoot());


	
	delete str;
	delete d;
	delete t;
	
	return 0;
}
