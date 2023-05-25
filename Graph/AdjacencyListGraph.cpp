#include "Graph.h"

template<typename VerType, typename EdgeType>
class AdjacencyListGraph:public Graph<VerType, EdgeType>{
private:
	struct edgeNode{
		int end;
		EdgeType weight;
		edgeNode* nxt;
		edgeNode(int e, EdgeType w, edgeNode* n=nullptr):end(e), weight(w), nxt(n){}
	};
	struct verNode{
		VerType ver; //data
		edgeNode* head;
		verNode(edgeNode* h=nullptr):head(h){}
	};
	int vers,edges;
	verNode* verList;
	int find(VerType v) const{
		for(int i=1;i<=vers;++i)
			if(verList[i].ver==v)
				return i;
	}
	AdjacencyListGraph(int size, const VerType* data){
		vers=size, edges=0;
		verList=new verNode[size];
		for(int i=0;i<vers;++i)
			verList[i].ver=data[i];
	}
	~AdjacencyListGraph(){
		edgeNode* p;
		for(int i=0;i<vers;++i)
			while(verList[i].head!=nullptr){
				p=verList[i].head;
				verList[i].head=p->nxt;
				delete p;
			}
		delete[]verList;
	}
	void insert(VerType x, VerType y, EdgeType w){
		int u=find(x), v=find(y);
		verList[u].head=new edgeNode(v, w, verList[u].head);
		++edges;
	}
	void remove(VerType x, VerType y){
		int u=find(x), v=find(y);
		edgeNode *p=verList[u].head, *q;
		if(p==nullptr) return;
		if(p->end==v){
			verList[u].head=p->nxt;
			delete p;
			--edges;
			return;
		}
		while(p->nxt!=nullptr&&p->nxt->end!=v)
			p=p->nxt;
		if(p->nxt!=nullptr){
			q=p->nxt;
			p->nxt=q->nxt;
			delete q;
			--edges;
		}
	}
	bool exist(VerType x, VerType y) const{
		int u=find(x), v=find(y);
		edgeNode* p=verList[u].head;
		while(p!=nullptr&&p->end!=v)
			p=p->nxt;
		if(p==nullptr) return false;
		return true;
	}
};