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
				dic[*it]++;				
		}
		itm=dic.begin();		
}

void p(node* n,bool flag){
	if(flag){
		cout<<"\troot: "<<n->getWeight()<<endl;
	}
	
		if(n->getRnextNode()!=nullptr){
			cout<<"\t\tright: "<<n->getRnextNode()->getWeight()<<endl;			
			p(n->getRnextNode(),false);					
	}
		cout<<n->getChar()<<endl;	
		return;	
		
	
	
}

int main (int argc, char** argv) {

	
	
	map<char,int> dic;
	map<char,int>::iterator it=dic.begin();

	string* str= CppStyleFileRead("main.cpp");	
//	passGenerator.exe
	string* fstr=CppStyleFileRead("main.cpp");	
	int s=0;
	string* str1= new string(CStyleFileRead("main.cpp",&s));
	int strIt=0;

	createDic(dic,it,str);
	tree* t= new tree(dic);


	cout<<"--------------------------------"<<endl;
	
	ofstream g("output.a", ios::out | ios::binary);
	
	int count=0; char buf=0;
    while (strIt!=str->size())
    { char c = str->c_str()[strIt];
	  vector<bool> x = t->getCode()[c];
	  for(int n=0; n<x.size(); n++)
	   {buf = buf | x[n]<<(7-count);   
	    count++;   
	    if (count==8) { count=0;  g<<buf; buf=0; } 
       }
	  ++strIt;
    }
	g.close();
	
	
	ifstream F("output.a", ios::in | ios::binary);
	ofstream go("output.cpp", ios::out | ios::binary);
	
	node *p = t->getRoot();
	count=0; char byte; 
	byte = F.get();
	int cc=0;
	while(!F.eof())
	{   bool b = byte & (1 << (7-count) );
		if (b) p=p->getRnextNode(); else p=p->getLnextNode();
		if (p->getRnextNode()==nullptr && p->getLnextNode()==nullptr) {go<<p->getChar();cout<<p->getChar(); p=t->getRoot();}  
		count++;
		if (count==8) {count=0;byte = F.get();}
	}


	F.close();	
	go.close();
	
	delete fstr,str,str1;
	delete t;
	
	return 0;
}