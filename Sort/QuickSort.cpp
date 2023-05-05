#include<bits/stdc++.h>

using namespace std;
int a[1000005],n,cnt;
void quickSort(int l,int r){
	if(l>r) return;
	int i=l,j=r,tmp=a[l];
	while(i!=j){
		while(a[j]>=tmp&&i<j)
			j--,++cnt;
		while(a[i]<=tmp&&i<j)
			i++,++cnt;
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	swap(a[i],a[l]);
	quickSort(l,i-1);
	quickSort(i+1,r);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	quickSort(1,n);
	cout<<cnt;
	return 0;
}