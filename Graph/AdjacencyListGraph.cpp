#include "Graph.h"
#include "../LinearStructure/Queue.cpp"

template<typename VerType, typename EdgeType>
class AdjacencyListGraph:public Graph<VerType, EdgeType>{
private:
	struct edgeNode{
		int end; //point to another vertex
		EdgeType weight;
		edgeNode* nxt;
		edgeNode(int e, EdgeType w, edgeNode* n=nullptr):end(e), weight(w), nxt(n){}
	};

	struct verNode{
		VerType ver; //data
		edgeNode* head;
		verNode(edgeNode* h=nullptr):head(h){}
	};

	struct EulerNode{
		int num;
		EulerNode* nxt;
		EulerNode(int ver):num(ver), nxt(nullptr){}
	};

	int vers,edges;
	verNode* verList;

	int find(VerType v) const{
		for(int i=0;i<vers;++i)
			if(verList[i].ver==v)
				return i;
	}

	void EulerCircuit(int start, EulerNode* &begin, EulerNode* &end){
		int nxt;
		begin=end=new EulerNode(start);
		while(verList[start].head!=nullptr){
			nxt=verList[start].head->end;
			remove(start, nxt);
			remove(nxt, start);
			start=nxt;
			end->nxt=new EulerNode(start);
			end=end->nxt;
		}
	}
public:
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

	void dfs(int start, bool* visit){
		edgeNode* p=verList[start].head;
		// cout<<verList[start].ver<<" ";
		visit[start]=true;

		while(p!=nullptr){
			if(!visit[p->end]) dfs(p->end, visit);
			p=p->nxt;
		}
	}

	void dfs() const{
		bool* visit=new bool[vers];

		for(int i=0;i<vers;++i)
			visit[i]=false;
		for(int i=0;i<vers;++i){
			if(visit[i]) continue;
			dfs(i, visit);
			// cout<<endl;
		}
	}

	void bfs(){
		bool* visit=new bool[vers];
		int currentNode;
		queue<int> q;
		edgeNode* p;

		for(int i=0;i<vers;++i)
			visit[i]=false;
		for(int i=0;i<vers;++i){
			if(visit[i]) continue;
			q.push(i);
			while(!q.empty()){
				currentNode=q.pop();
				if(visit[currentNode]) continue;
				// cout<<verList[currentNode].ver<<" ";
				visit[currentNode]=true;
				p=verList[currentNode].head;
				while(p!=nullptr){
					if(!visit[p->end]) q.push(p->end);
					p=p->nxt;
				}
			}
			// cout<<endl;
		}
	}

	verNode* clone() const{
		verNode* tmp=new verNode[vers];
		edgeNode* p;

		for(int i=0;i<vers;++i){
			tmp[i].ver=verList[i].ver;
			p=verList[i].head;
			while(p!=nullptr){
				tmp[i].head=new edgeNode(p->end, p->weight, tmp[i].head);
				p=p->nxt;
			}
		}

		return tmp;
	}

	void EulerCircuit(VerType start){
		EulerNode *begin, *end, *p, *q, *tb, *te;
		int degree;
		edgeNode* r;
		verNode* tmp;

		if(edges==0) {
			// cout<<"Not found."<<endl;
			return;
		}
		for(int i=0;i<vers;++i){
			degree=0;
			r=verList[i].head;
			while(r!=nullptr){
				++degree;
				r=r->nxt;
			}
			if(degree&1){
				// cout<<"Not found."<<endl;
				return;
			}
		}

		int s=find(start);
		tmp=clone();

		EulerCircuit(s, begin, end);

		while(true){
			p=begin;

			while(p->nxt!=nullptr){
				if(verList[p->nxt->num].head!=nullptr) break;
				else p=p->nxt;
			}
			if(p->nxt==nullptr) break;
			q=p->nxt;
			EulerCircuit(q->num, tb, te);
			te->nxt=q->nxt;
			p->nxt=tb;
			delete q;
		}

		delete[]verList;
		verList=tmp;

		while(begin!=nullptr){
			//std::cout<<verList[begin->num].ver<<" ";
			p=begin;
			begin=begin->nxt;
			delete p;
		}
		//cout<<endl;
	}

	void topoSort(){
		queue<int> q;
		edgeNode* p;
		int current;
		int* inDegree=new int[vers];
		for(int i=0;i<vers;++i)
			inDegree[i]=0;
		for(int i=0;i<vers;++i)
			for(p=verList[i].head;p!=nullptr;p=p->nxt)
				++inDegree[p->end];
		for(int i=0;i<vers;++i)
		    if(!inDegree[i]) q.push(i);
		while(!q.empty()){
			current=q.pop();
			// cout<<verList[current].ver<<" ";
			for(p=verList[current].head;p!=nullptr;p=p->nxt)
				if(--inDegree[p->end]==0)
					q.push(p->end);
		}
	}
};