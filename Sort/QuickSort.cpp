#include "Set.h"

template<typename KEY, typename VALUE>
void quickSort(SET<KEY, VALUE>* a, int l, int r){
    if(l>=r) return;
	int i=l, j=r;
	SET<KEY, VALUE> tmp=a[l];
	while(i!=j){
		while(a[j]>=tmp&&i<j) --j;
		while(a[i]<=tmp&&i<j) ++i;
		if(i<j) swap(a[i],a[j]);
	}
	swap(a[i], a[l])
	quickSort(a, l, i-1);
	quickSort(a, i+1, r);
}