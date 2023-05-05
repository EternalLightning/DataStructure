#include<bits/stdc++.h>
#include"DynamicSearchTable.h"

using namespace std;

template<typename KEY,typename VALUE>
class AvlTree:public DynamicSearchTable<KEY,VALUE>{
private:
	struct node{
		SET<KEY,VALUE> data;
		node *left,*right;
		int height;
		node(const SET<KEY,VALUE> &element,node* l=nullptr,node* r=nullptr,int h=1)
			:data(element),left(l),right(r),height(h){}
	};
	node *root;
	void insert(const SET<KEY,VALUE> &x,node *&t){
		if(t==nullptr)
			t=new node(x);
		else if(x.key<t->data.key){
			insert(x,t->left);
			if(height(t->left)-height(t->right)==2){
				if(x.key<t->left->data.key) LL(t);
				else LR(t);
			}
		}
		else if(x.key>t->data.key){
			insert(x,t->right);
			if(height(t->right)-height(t->left)==2){
				if(x.key>t->left->data.key) RR(t);
				else RL(t);
			}
		}
		t->height=max(height(t->left),height(t->right))+1;
	}
	bool remove(const KEY &x,node *&t){
		if(t==nullptr) return true;
		if(x==t->data.key){
			if(t->left==nullptr||t->right==nullptr){
				node *oldNode=t->left==nullptr?t->right:t->left;
				delete oldNode;
				return false;
			}
			else{
				node *tmp=t->right;
				while(tmp->left!=nullptr) tmp=tmp->left;
				t->data=tmp->data;
				if(remove(tmp->data.key,t->right)) return true;
				return adjust(t,1);
			}
		}
		if(x<t->data.key){
			if(remove(x,t->left)) return true;
			return adjust(t,0);
		}
		else{
			if(remove(x,t->right)) return true;
			return adjust(t,1);
		}
	}
	void clear(node *t){
		if(t==nullptr) return;
		clear(t->right);
		clear(t->left);
		delete t;
	}
	int height(node *t) const{
		return t==nullptr?0:t->height;
	}
	void LL(node *&t){
		node *t1=t->left;
		t->left=t1->right;
		t1->right=t;
		t->height=max(height(t->left),height(t->right))+1;
		t1->height=max(height(t1->left),height(t1->right))+1;
		t=t1;
	}
	void LR(node *&t){
		RR(t->left);
		LL(t);
	}
	void RL(node *&t){
		LL(t->right);
		RR(t);
	}
	void RR(node *&t){
		node *t1=t->right;
		t->right=t1->left;
		t1->left=t;
		t->height=max(height(t->left),height(t->right))+1;
		t1->height=max(height(t1->left),height(t1->right))+1;
		t=t1;
	}
	bool adjust(node *&t,int subTree){
		if(subTree){ //delete on right subtree
			if(height(t->left)-height(t->right)==1) return true;
			if(height(t->right)==height(t->left)){ //Attention, delete operation has been executed.
				--t->height;
				return false;
			}
			//In other case, the tree is not balance;
			if(height(t->left->right)>height(t->left->left)){
				LR(t);
				return false;
			}
			LL(t);
			return !(height(t->left)==height(t->right));
		}
		else{
			if(height(t->right)-height(t->left)==1) return true;
			if(height(t->right)==height(t->left)){ //Attention, delete operation has been executed.
				--t->height;
				return false;
			}
			//In other case, the tree is not balance;
			if(height(t->right->left)>height(t->right->right)){
				RL(t);
				return false;
			}
			RR(t);
			return !(height(t->left)==height(t->right));
		}
	}
public:
	AvlTree(){
		root=nullptr;
	}
	~AvlTree(){
		clear(root);
	}
	SET<KEY,VALUE>* find(const KEY &x) const{
		node *t=root;
		while(t!=nullptr&&t->data.key!=x)
			if(t->data.key>x) t=t->left;
			else t=t->right;
		return t==nullptr?nullptr:&t->data;
	}
	void insert(const SET<KEY,VALUE> &x){
		insert(x,root);
	}
	void remove(const KEY &x){
		remove(x,root);
	}
};

AvlTree<int,string>a;
int main(){
	SET<int,string> x;
	a.insert(x);
	a.remove(1);
	return 0;
}