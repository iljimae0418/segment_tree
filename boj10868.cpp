// typical RMQ 
#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <algorithm>
using namespace std;  
const int MAXN = 100000+10;  
const int INF = 2e9+88888;  
int a[MAXN]; 
int seg[MAXN*4]; 
void build(int l,int r,int rt){
	if (l == r){
		seg[rt] = a[l]; 
		return;  
	}
	int mid = (l+r)>>1; 
	build(l,mid,rt<<1); // build left subtree 
	build(mid+1,r,rt<<1|1); // build right subtree 
	seg[rt] = min(seg[rt<<1],seg[rt<<1|1]); 
}
int query(int L,int R,int l,int r,int rt){
	// find minimum in [L,R] when the defined range is [l,r] 
	if (L > r || R < l) return INF;  
	if (l >= L && r <= R) return seg[rt];  
	int mid = (l+r)>>1; 
	return min(query(L,R,l,mid,rt<<1),query(L,R,mid+1,r,rt<<1|1));  
}
int main(){
	int N,M; 
	scanf("%d %d",&N,&M);  
	for (int i = 1; i <= N; i++){
		scanf("%d",a+i); 
	}
	build(1,N,1); 
	while (M--){	
		int from,to; 
		scanf("%d %d",&from,&to); 
		int ret = query(from,to,1,N,1);  
		printf("%d\n",ret);  
	}
	return 0; 
}
