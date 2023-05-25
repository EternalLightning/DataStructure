#include "Set.h"

template<typename VALUE>
struct node{
    SET<int, VALUE> data;
    node* nxt;
    node():nxt(nullptr){}
    node(SET<int, VALUE> d):data(d),nxt(nullptr){}
};

template<typename VALUE>
void radixSort(node<VALUE>* &p){
    //give up, no sense
}