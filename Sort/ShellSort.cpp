#include "Set.h"

template<typename KEY, typename VALUE>
void shellSort(SET<KEY, VALUE>* a, int size){
    int step, j;
    SET<KEY, VALUE> tmp;
    for(step=(size>>1);step>0;step>>=1)
        for(int i=step;i<size;++i){
            tmp=a[i];
            for(j=i-step;j>=0&&tmp.key<a[j].key;j-=step)
                a[j+step]=a[j];
            a[j+step]=tmp;
        }
}