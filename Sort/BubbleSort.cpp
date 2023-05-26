#include "Set.h"

template<typename KEY, typename VALUE>
void bubbleSort(SET<KEY, VALUE>* a, int size){
    SET<KEY, VALUE> tmp;
    bool flag=true;

    for(int i=1;i<size&&flag;++i){
        flag=false;
        for(int j=0;j<size-i;++j){
            swap(a[j], a[j+1]);
            flag=true;
        }
    }
}