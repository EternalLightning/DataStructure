#include<bits/stdc++.h>

using namespace std;

template<class Type>
class sLinkList{
private:
	struct node{
		Type data;
		node *nxt;
		node(const Type &x,node *n=nullptr){
			data=x,nxt=n;
		}
		node():nxt(nullptr){}
	};
	node *head;
	int currentLength;
	node* move(int i) const{ //return the address of node i
		node *p=head;
		while(i>=0){
			p=p->nxt;
			--i;
		}
		return p;
	}
	void delnxt(node* p){//delete the NEXT node of pointer p
		node *delp=p->nxt;
		p->nxt=p->nxt->nxt;
		delete delp;
		--currentLength;
	}
public:
	sLinkList(){
		head=new node;
		currentLength=0;
	}
	~sLinkList(){
		delete[]head;
	}
	void clear(){
		node *q,*p=head->nxt;
		head->nxt=nullptr;
		while(p!=nullptr){
			q=p->nxt;
			delete p;
			p=q;
		}
		currentLength=0;
	}
	int length() const{
		return currentLength;
	}
	void insert(int i,const Type &x){
		node *pos=move(i-1);
		pos->nxt=new node(x,pos->nxt);
		++currentLength;
	}
	void remove(int i){
		node *pos=move(i-1),*delp;
		delp=pos->nxt;
		pos->nxt=delp->nxt;
		delete delp;
		--currentLength;
	}
	int search(const Type &x) const{
		node *p=head->nxt;
		int i=0;
		while(p!=nullptr&&p->data!=x){
			p=p->nxt;
			++i;
		}
		if(p==nullptr) return -1;
		return i;
	}
	Type visit(int i) const{
		return move(i)->data;
	}
	void traverse() const{
		node *p=head->nxt;
		while(p!=nullptr){
			cout<<p->data<<" ";
			p=p->nxt;
		}
		cout<<endl;
	}
	void erase(int x,int y){

	}
};
int main(){
	int n,tmp;
	cin>>n;
	sLinkList<int> test;
	for(int i=1;i<=n;++i){
		cin>>tmp;
		test.insert(i-1,tmp);
	}
	test.traverse();
	test.remove(3);
	test.traverse();
	return 0;
}