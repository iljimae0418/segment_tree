// https://www.acmicpc.net/problem/2042
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll;  
const int MAXN = 1000000+10;
ll seg[4*MAXN]; 
ll a[MAXN];
void build(int l,int r,int rt){
	if (l == r){
		seg[rt] = a[l]; 
		return; 
	}
	int mid = (l+r)>>1; 
	build(l,mid,rt<<1); // build left subtree
	build(mid+1,r,rt<<1|1); // build right subtree 
	seg[rt] = seg[rt<<1]+seg[rt<<1|1]; 
}  
void update(int p,ll newval,int l,int r,int rt){
	if (l == r){
		seg[rt] = newval; 
		return; 
	}
	int mid = (l+r)>>1;  
	if (p <= mid){
		update(p,newval,l,mid,rt<<1); 
	}else{
		update(p,newval,mid+1,r,rt<<1|1); 
	}
	seg[rt] = seg[rt<<1]+seg[rt<<1|1];  
}
ll query(int L,int R,int l,int r,int rt){ 
	if (L > r || R < l) return 0LL; 
	if (l >= L && r <= R){
		return seg[rt];  
	}
	int mid = (l+r)>>1;  
	return query(L,R,l,mid,rt<<1)+query(L,R,mid+1,r,rt<<1|1);  
}
int main(){
	int n,m,k; 
	scanf("%d %d %d",&n,&m,&k); 
	m += k; 
	for (int i = 1; i <= n; i++){
		scanf("%lld",a+i); 
	}
	build(1,n,1);  
	while (m--){
		int x,y; 
		ll z; 
		scanf("%d %d %lld",&x,&y,&z); 
		// if x = 1, update 
		// else print range sum 
		if (x == 1){
			update(y,z,1,n,1);  
		}else{
			printf("%lld\n",query(y,z,1,n,1)); 
		}
	}
	return 0; 
}
