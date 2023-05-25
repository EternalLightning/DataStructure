#include "Queue.h"

template<typename Type>
class queue:public Queue<Type>{
private:
	Type* elem;
	int maxSize, front, rear;

    void doubleSpace(){
        Type* tmp=elem;
        elem=new Type[2*maxSize];
        for(int i=1;i<maxSize;++i)
            elem[i]=tmp[(front+i)%maxSize];
        front=0;
        rear=maxSize-1;
        maxSize<<=1;
        delete tmp;
    }
public:
    queue(int size=10){
        elem=new Type[size];
        maxSize=size;
        front=rear=0;
    }

    ~queue(){
        delete[]elem;
    }

    bool empty(){
        return front==rear;
    }

    void push(const Type &x){
        if((rear+1)%maxSize==front) doubleSpace();
        rear=(rear+1)%maxSize;
        elem[rear]=x;
    }

    Type pop(){
        front=(front+1)%maxSize;
        return elem[front];
    }

    Type top(){
        return elem[(front+1)%maxSize];
    }
};