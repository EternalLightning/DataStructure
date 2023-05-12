#include <string>
#include "PriorityQueue.cpp"

template<typename Type>
class HuffmanTree{
private:
	struct node{
		Type data;
		int weight,fa,left,right,i;
		bool operator<(const node &x) const{
			return this->weight<x.weight;
		}
	};
	node *array;
	int length;
	PriorityQueue<node> weightQueue;
public:
	struct HuffmanCode{
		Type data;
		std::string code;
	};
	HuffmanTree(const Type* data,const int* weight,int size){
		node min1,min2;
		length=(size<<1);
		array=new node[length];
		for(int i=size;i<length;++i){
			array[i].weight=weight[i-size];
			array[i].data=data[i-size];
			array[i].fa=array[i].left=array[i].right=0;
			array[i].i=i;
			weightQueue.push(array[i]);
		}
		for(int i=size-1;i>0;--i){
			min1=weightQueue.pop();
			min2=weightQueue.pop();
			array[i].weight=min1.weight+min2.weight;
			array[i].left=min1.i;
			array[i].right=min2.i;
			array[i].i=i;
			array[min1.i].fa=i;
			array[min2.i].fa=i;
			weightQueue.push(array[i]);
			//cuizhihui tailihaile
		}

	}
	void getCode(HuffmanCode *result){
		int size=(length>>1);
		int s,p;
		for(int i=size;i<length;++i){
			result[i-size].data=array[i].data;
			result[i-size].code="";
			p=array[i].fa;
			s=i;
			while(p){
				if(array[p].left==s)
					result[i-size].code+='0';
				else result[i-size].code+='1';
				s=p;
				p=array[p].fa;
			}
		}

	}
	~HuffmanTree(){
		delete[]array;
	}
};