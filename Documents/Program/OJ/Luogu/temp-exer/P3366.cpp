#include <cstdio>
#include <algorithm>

struct node{
	int u,v,w;
	bool operator < (const node in) const{
		return w<in.w;
	}
}e[200000+10];

struct U{
	int fa[5000+10];
	void build(int n){
		register int i;
		for(i=1;i<=n;++i) fa[i]=i;
	}
	
	int find(int x){
		return (x==fa[x])?x:(fa[x]=find(fa[x]));
	}
	
	void merge(int i,int j){
		fa[find(i)]=find(j);
		return;
	}
}u;

int read(){
	register int x=0;char f=0,c=getchar();
	while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return f?-x:x;
}

int main(){
	int n=read();
	int m=read();
	
	register int i,cnt=0,sum=0;
	u.build(n);
	
	for(i=0;i<m;++i){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	
	std::sort(e,e+m);
	
	for(i=0;i<m;++i){
		if(u.find(e[i].u)!=u.find(e[i].v)){
			u.merge(e[i].u,e[i].v);
			sum+=e[i].w;
			++cnt;
			if(cnt==n-1) break;
		}
	}
	
	if(cnt==n-1) printf("%d",sum);
	else printf("orz");

	return 0;
}
