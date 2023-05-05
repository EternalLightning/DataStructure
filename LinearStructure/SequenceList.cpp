#include<bits/stdc++.h>

using namespace std;

template<class Type>
class seqList{
private:
	Type *data;
	int currentLength;
	int maxSize;
	void doubleSpace(){
		Type *tmp=data;
		maxSize*=2;
		data=new Type[maxSize];
		for(int i=0;i<currentLength;++i)
			data[i]=tmp[i];
		delete[]tmp;
	}
public:
	seqList(int initSize=10){
		data=new Type[initSize];
		maxSize=initSize;
		currentLength=0;
	}
	~seqList(){
		delete[]data;
	}
	void clear(){
		currentLength=0;
	}
	int length() const{
		return currentLength;
	}
	void insert(int i,const Type &x){
		if(currentLength==maxSize) doubleSpace();
		for(int j=currentLength;j>i;--j)
		    data[j]=data[j-1];
		data[i]=x;
		++currentLength;
	}
	void remove(int i){
		for(int j=i;j<currentLength-1;++j)
			data[j]=data[j+1];
		--currentLength;
	}
	int search(const Type &x) const{
		int i;
		for(i=0;i<currentLength&&x!=data[i];++i);
		if(i==currentLength) return -1;
		return i;
	}
	Type visit(int i) const{
		return data[i];
	}
	void traverse() const{
		for(int i=0;i<currentLength;++i)
			cout<<data[i]<<" ";
	}
};

int main(){

	return 0;
}