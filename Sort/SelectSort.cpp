#include "Set.h"

template<typename KEY, typename VALUE>
void selectSort(SET<KEY, VALUE>* a, int size){
    int minn;
    for(int i=0;i<size-1;++i){
        minn=i;
        for(int j=i+1;j<size;++j)
            if(a[j].key<a[minn].key)
                minn=j;
        swap(a[i], a[minn]); 
    }
}