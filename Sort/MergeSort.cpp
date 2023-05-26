#include "Set.h"

template<typename KEY, typename VALUE>
void mergeSort(SET<KEY, VALUE>* a, int l,int r){
	if(l==r) return;

	SET<KEY, VALUE>* aux=new SET<KEY, VALUE>[r-l+1];
	int mid=(l+r)>>1;
	int i=l, j=mid+1, k=0;

	mergeSort(a, l, mid);
	mergeSort(a, mid+1, r);

	while(i<=mid&&j<=r)
		if(a[i]<=a[j]) aux[k++]=a[i++];
		else aux[k++]=a[j++];
	while(i<=mid) aux[k++]=a[i++];
	while(j<=r) aux[k++]=a[j++];
	for(int m=0;m<k;++m)
		a[l+m]=aux[m];

	delete[]aux;
}