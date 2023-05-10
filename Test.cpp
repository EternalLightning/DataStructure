#include "Tree/HuffmanTree.cpp"
#include <iostream>
using namespace std;

int main(){
    char ch[]={"aeistdn"};
	int w[]={10,15,12,3,4,13,1};
	HuffmanTree<char> a(ch,w,7);
	HuffmanTree<char>::HuffmanCode res[100];
	a.getCode(res);
	for(int i=0;i<7;++i)
		cout<<res[i].code<<endl;
    return 0;
}