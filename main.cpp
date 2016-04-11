#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
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

void writeArchive(const char* filepath,string* str,tree* t){
	
	ofstream g(filepath, ios::out | ios::binary);	
	int strIt=0;
	int count=0; 
	char buf=0;
	
    while (strIt!=str->size()){
		char c = str->c_str()[strIt];
		 vector<bool> x = t->getCode()[c];
		  for(int n=0; n<x.size(); n++){
		  	buf = buf | x[n]<<(7-count);   
			    count++;   
			    if(count==8){
				 	count=0;
					g<<buf;
					buf=0;
				} 
	       }
		  ++strIt;
    }
	g.close();	
}

void readArchive(const char* afilepath, const char* ofilepath,tree* t){
	ifstream F(afilepath, ios::in | ios::binary);
	ofstream go(ofilepath, ios::out | ios::binary);
	
	node *p = t->getRoot();
	int count=0; char byte; 
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
	
}

void help(){
				cout<<"this programm for archive with haffman algorithm"<<endl
				<<"flag description:"<<endl
				<<"flag -I enter input file to archive  "<<endl
				<<"flag -O if you want to customize output file name"<<endl;			
}
		

int main (int argc, char* argv[]) {

	string out,outa,file;
	string* str;
	tree* t;
	if(argc>1){
		if(strcmp(argv[1],"-I")==0){
			if(strcmp(argv[3],"-O")==0){
				str= CppStyleFileRead(argv[2]);	
				t= new tree(str);
				
				outa=argv[2];
				file;
				string::iterator s=outa.end();				
				bool flag=true;				
				while(flag || s==outa.begin()){
					if(*s=='.'){
						flag=false;
						file=outa.substr(0,outa.find(*s));
						outa=file+".a";
					}
					--s;
				}
				out=argv[4];
				
								
			}else{
				cout<<"output file is not declared"<<endl;
				out="output";
			}
		cout<<"size of input file is: "<<str->size()<<endl;
		cout<<"--------------------------------"<<endl;
		
		t->writeTree();
		
		writeArchive(outa.c_str(),str,t);
		
		readArchive(outa.c_str(),out.c_str(),t);
			
		}else{
			cout<<"input file is not declared"<<endl;
			return 0;
		}
	}else{
		help();
	}	

	return 0;
}


