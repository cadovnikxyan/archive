#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <map>
#include <iostream>
#include "word.h"

using namespace std;
	
class dictionary
{
	word* _word;		
	void quickSort (word* a, int l,int r);
	const int size;
	
	public:
		dictionary(map<char,int>& _dic,int dsize);
		word* getWord();
		int   getSize();
		~dictionary();
	
};

#endif
