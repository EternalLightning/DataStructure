#include "../LinearStructure/Queue.h"

template<typename Type>
class PriorityQueue:public Queue<Type>{
private:
	int currentSize,maxSize;
	Type* array;
	void doubleSpace(){
		Type* tmp=array;
		maxSize<<=1;
		array=new Type[maxSize];
		for(int i=0;i<=currentSize;++i)
			array[i]=tmp[i];
		delete[]tmp;
	}
	void buildHeap(){
		for(int i=(currentSize>>1);i>=1;--i)
			percolateDown(i);
	}
	void percolateDown(int i){
		int child;
		Type tmp=array[i];
		for(;(i<<1)<=currentSize;i=child){
			child=(i<<1);
			if(child!=currentSize&&array[child+1]<array[child])
				++child;
			if(array[child]<tmp) array[i]=array[child];
			else break;
		}
		array[i]=tmp;
	}
public:
	PriorityQueue(int length=100){
		array=new Type[length];
		maxSize=length;
		currentSize=0;
	}
	PriorityQueue(const Type *data,int size){
		maxSize=size+10;
		currentSize=size;
		array=new Type[maxSize];
		for(int i=1;i<=size;++i)
			array[i]=data[i-1];
		buildHeap();
	}
	~PriorityQueue(){
		delete[]array;
	}
	bool isEmpty() const{
		return currentSize==0;
	}
	void push(const Type &x){
		if(currentSize==maxSize-1) doubleSpace();
		int i=++currentSize;
		for(;i>1&&x<array[i/2];i/=2)
			array[i]=array[i/2];
		array[i]=x;
	}
	Type pop(){
		Type top=array[1];
		array[1]=array[currentSize--];
		percolateDown(1);
		return top;
	}
	Type top() const{
		return array[1];
	}
};