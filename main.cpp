#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <algorithm>
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
	
	static string* str=new string(
	(istreambuf_iterator<char>
	(*(auto_ptr<ifstream>(new ifstream(filepath,ios::binary))).get())),istreambuf_iterator<char>());
	return str;		
}



	
		

int main (int argc, char* argv[]) {

		
	string* str= CppStyleFileRead("passGenerator.exe");	

	tree* t= new tree(str);

	const char outa[] ="output.a";
	const char out[] ="output.exe";
	cout<<str->size()<<endl;
	cout<<"--------------------------------"<<endl;

	t->writeTree();
	
	ofstream g(outa, ios::out | ios::binary);	
	int strIt=0;
	int count=0; char buf=0;
	
    while (strIt!=str->size()){
		char c = str->c_str()[strIt];
		 vector<bool> x = t->getCode()[c];
		  for(int n=0; n<x.size(); n++){
		  	buf = buf | x[n]<<(7-count);   
			    count++;   
			    if(count==8){
				 count=0;  g<<buf; buf=0;
				} 
	       }
		  ++strIt;
    }
	g.close();
	

	
	ifstream F(outa, ios::in | ios::binary);
	ofstream go(out, ios::out | ios::binary);
	
	node *p = t->getRoot();
	count=0; char byte; 
	byte = F.get();
	while(!F.eof()){   
		bool b = byte & (1 << (7-count) );
			if(b) p=p->getRnextNode(); else p=p->getLnextNode();
			if(p->getRnextNode()==nullptr && p->getLnextNode()==nullptr){
					go<<p->getChar(); 
					p=t->getRoot();
				}  
			count++;
			if(count==8){
				count=0;byte = F.get();
			}
	}
	
	F.close();	
	go.close();
	
	delete str;
	delete t;
	
	return 0;
}


