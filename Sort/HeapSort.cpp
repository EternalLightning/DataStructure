#include "Set.h"

template<typename KEY, typename VALUE>
void percolateDown(SET<KEY, VALUE>* a, int hole, int size){
    int child;
    SET<KEY, VALUE> tmp=a[hole];

    for(;(hole<<1)+1<size;hole=child){
        child=(hole<<1)+1;
        if(child!=size-1&&a[child+1].key>a[child].key)
            child++;
        if(a[child].key>tmp.key) a[hole]=a[child];
        else break;
    }

    a[hole]=tmp;
}

template<typename KEY, typename VALUE>
void heapSort(SET<KEY, VALUE>* a, int size){
    SET<KEY, VALUE> tmp;

    for(int i=(size>>1)-1;i>=0;--i)
        percolateDown(a, i, size);

    for(int i=size-1;i>0;--i){
        swap(a[i], a[0]);
        percolateDown(a, 0, i);
    }
}