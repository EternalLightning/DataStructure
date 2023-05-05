#include<bits/stdc++.h>
#include"DynamicSearchTable.h"
using namespace std;

template<typename KEY,typename VALUE>
class BinarySearchTree:public DynamicSearchTable<KEY,VALUE>{
private:
	struct node{
		SET<KEY,VALUE> data;
		node *left,*right;
		node(const SET<KEY,VALUE> &element,node* l=nullptr,node* r=nullptr):data(element),left(l),right(r){}
	};
	node *root;
	void insert(const SET<KEY,VALUE> &x,node* &t){
		if(t==nullptr)
			t=new node(x);
		else if(x.key<t->data.key)
			insert(x,t->left);
		else if(x.key>t->data.key)
			insert(x,t->right);
	}
	void remove(const KEY &x,node* &t){
		if(t==nullptr) return;
		if(x<t->data.key) remove(x,t->left);
		else if(x>t->data.key) remove(x,t->right);
		else if(t->left!=nullptr&&t->right!=nullptr){
			node *tmp=t->right;
			while(tmp->left!=nullptr) tmp=tmp->left;
			t->data=tmp->data;
			remove(t->data.key,t->right);
		}
		else{
			node *oldNode=t;
			t=(t->left!=nullptr)?t->left:t->right;
			delete oldNode;
		}
	}
	void clear(node* t){
		if(t==nullptr) return;
		clear(t->left);
		clear(t->right);
		delete t;
	}
public:
	BinarySearchTree(){
		root=nullptr;
	}
	~BinarySearchTree(){
		clear(root);
	}
	SET<KEY,VALUE>* find(const KEY &x) const{
		node *t=root;
		while(t!=nullptr&&t->data.key!=x){
			if(x<t->data.key) t=t->left;
			else t=t->right;
		}
		return t==nullptr?nullptr:&t->data;
	}
	void insert(const SET<KEY,VALUE> &x){
		insert(x,root);
	}
	void remove(const KEY &x){
		remove(x,root);
	}
};


int main(){

	return 0;
}