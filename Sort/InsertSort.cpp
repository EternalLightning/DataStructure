#include "Set.h"

template<typename KEY, typename VALUE>
void insertSort(SET<KEY, VALUE>* a, int size){
    int j;
    SET<KEY, VALUE> tmp;
    for(int i=1;i<size;++i){
        tmp=a[i];
        for(j=i-1;j>=0&&tmp.key<a[j].key;--j)
            a[j+1]=a[j];
        a[j+1]=tmp;
    }
}