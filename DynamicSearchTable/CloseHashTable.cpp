#include"DynamicSearchTable.h"

template<typename KEY,typename VALUE>
class CloseHashTable:public DynamicSearchTable<KEY,VALUE>{
private:
	struct node{
		SET<KEY,VALUE> data;
		int state; //0--empty, 1--active, 2--deleted
		node(){
			state=0;
		}
	};

	node *array;
	int size;
	int (*getHashKey)(const KEY &x); //a function pointer

	static int defaultKey(const int &x){
		return x;
	}
public:
	CloseHashTable(int length=101,int (*f)(const KEY &x)=defaultKey){
		size=length;
		array=new node[size];
		getHashKey=f; //You can create your own key function
	}

	~CloseHashTable(){
		delete[]array;
	}

	SET<KEY,VALUE>* find(const KEY &x) const{
		int initPos,pos;
		initPos=pos=getHashKey(x.key)%size;
		do{
			if(array[pos].state==0) return nullptr;
			if(array[pos].state==1&&array[pos].data.key==x) return &array[pos].data;
			pos=(pos+1)%size;
		}while(pos!=initPos);
	}

	void insert(const SET<KEY,VALUE> &x){
		int initPos,pos;
		initPos=pos=getHashKey(x.key)%size;
		do{
			if(array[pos].state!=1){
				array[pos].data=x;
				array[pos].state=1;
				return;
			}
			pos=(pos+1)%size;
		}while(pos!=initPos);
	}
	
	void remove(const KEY &x){
		int initPos,pos;
		initPos=pos=getHashKey(x.key)%size;
		do{
			if(array[pos].state==0||array[pos].state==2) return;
			if(array[pos].state==1&&array[pos].data.key==x){
				array[pos].state=2;
				return;
			}
			pos=(pos+1)%size;
		}while(pos!=initPos);
	}
};