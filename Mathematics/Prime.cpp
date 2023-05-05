#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN=100000001;
bitset<MAXN>comp;//是否为合数，true为合数
ull prime[MAXN],cnt;
void zs(ull size){
	comp[0]=comp[1]=true;
	for(ull i=2;i<=size;++i){
		if(!comp[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=size;++j){
			comp[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	zs(n);
	for(int i=1;i<=q;++i){
		scanf("%d",&n);
		printf("%d\n",prime[n]);
	}
	return 0;
}