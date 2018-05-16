#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <vector> 
using namespace std;  
const int MAXN = 100005;  
const int INF = 2e9+88;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
int a[MAXN];  
int seg_min[MAXN*4];
int seg_max[MAXN*4];    
void build_min(int l,int r,int rt){
	if (l == r){
		seg_min[rt] = a[l];  
		return;   
	}
	int mid = (l+r)>>1;  
	build_min(l,mid,rt<<1); 
	build_min(mid+1,r,rt<<1|1); 
	seg_min[rt] = min(seg_min[rt<<1],seg_min[rt<<1|1]); 
}
int range_min_query(int L,int R,int l,int r,int rt){
	if (L > r || R < l) return INF;  
	if (l >= L && r <= R) return seg_min[rt]; 
	int mid = (l+r)>>1;  
	return min(range_min_query(L,R,l,mid,rt<<1),range_min_query(L,R,mid+1,r,rt<<1|1));  
}
void build_max(int l,int r,int rt){
	if (l == r){
		seg_max[rt] = a[l]; 
		return;  
	}
	int mid = (l+r)>>1;  
	build_max(l,mid,rt<<1); 
	build_max(mid+1,r,rt<<1|1);  
	seg_max[rt] = max(seg_max[rt<<1],seg_max[rt<<1|1]); 
}
int range_max_query(int L,int R,int l,int r,int rt){
	if (L > r || R < l) return -INF;  
	if (l >= L && r <= R) return seg_max[rt];  
	int mid = (l+r)>>1;  
	return max(range_max_query(L,R,l,mid,rt<<1),range_max_query(L,R,mid+1,r,rt<<1|1)); 	
}	
int main(){ 
	int N,M;  
	scanf("%d %d",&N,&M);  
	for (int i = 1; i <= N; i++){
		scanf("%d",a+i); 
	}	
	build_min(1,N,1);  
	build_max(1,N,1);
	while (M--){
		int u,v; 
		cin >> u >> v; 
		printf("%d %d\n",range_min_query(u,v,1,N,1),range_max_query(u,v,1,N,1)); 
	} 
	return 0;  
}
