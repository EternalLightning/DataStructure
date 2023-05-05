#include<bits/stdc++.h>
using namespace std;
const int MAXN=10001;
int a[MAXN],n,cnt;
void merge(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	merge(l,mid);
	merge(mid+1,r);
	int i=l,j=mid+1,k=0,aux[MAXN];
	while(i<=mid&&j<=r)
		if(a[i]<=a[j]) aux[k++]=a[i++],cnt++;
		else aux[k++]=a[j++],cnt++;
	while(i<=mid) aux[k++]=a[i++];
	while(j<=r) aux[k++]=a[j++];
	for(int m=0;m<k;++m)
		a[l+m]=aux[m];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	merge(1,n);
//	for(int i=1;i<=n;++i)
//		cout<<a[i]<<" ";
	cout<<cnt;
	return 0;
}