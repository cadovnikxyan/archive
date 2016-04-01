#include "dictionary.h"

dictionary::dictionary(map<char,int>& _dic,int dsize):size(dsize){
	
	 
	_word= new word[size];
	map<char,int>::iterator it=_dic.begin();
	int i=0;
	for(it=_dic.begin();it!=_dic.end();++it){	
		if(i!=size)	{
			_word[i].wsymbol=it->first;
			_word[i].wcount=it->second;			
			++i;
			
			}
		}
		quickSort(_word,0,size);	
}

dictionary::~dictionary(){

	delete[] _word;
}

word* dictionary::getWord(){
	return this->_word;
}
int dictionary::getSize(){
	return size;
}

void dictionary::quickSort (word* a, int l,int r){
	
	int left=l;
	int right=r;
	int middle=a[(right+left)/2].wcount;
	word temp;
	
		while(left<=right){
			
		while((a[left].wcount<middle) && (left<=right))left++;
		
		while((a[right].wcount>middle) && (right>=left))right--;
		
		if(left<=right){
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
			left++;right--;
		}
	}
	if(right>l){
		quickSort(a,l,right);
	}
	if(left<r){
		quickSort(a,left,r);
	}


}
