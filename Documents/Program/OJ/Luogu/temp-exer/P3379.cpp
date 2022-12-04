#include <cstdio>
#include <cstring>
#include <algorithm>

struct rmq{
    int f[500001][22];
    void build(int n,int* pa){
        int k=std::__lg(n);
        register int i,j;

        for(i=1;i<=n;++i) f[i][0]=pa[i];

        for(j=1;j<=k;++j)
            for(i=1;i<=n;++i)
                f[i][j]=f[f[i][j-1]][j-1];

        return;
    }
}st;

struct node{
    int to,next;
    node(){
        next=-1;
    }
}tree[500100*2];

int head[500100],pa[500100],depths[500100],tot;

void addEdge(int u,int v){
	tree[tot].to=v;
	tree[tot].next=head[u];
	head[u]=tot;
    ++tot;
	return;
}

void count(int u,int p){
    pa[u]=p;
    depths[u]=depths[p]+1;
    for(int i=head[u];~i;i=tree[i].next)
        if(tree[i].to!=p)
            count(tree[i].to,u);
}

int read(){
    register int x=0;char f=0,c=getchar();
    while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
    while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return f?-x:x;
}

int LCA_ST(register int u,register int v){
    if(depths[u]<depths[v]){
        u^=v;
        v=u^v;
        u=u^v;
    }
    while(depths[u]>depths[v]) u=st.f[u][std::__lg(depths[u]-depths[v]-1)];
    if(u==v) return u;
    for(register int k=std::__lg(depths[u])-1;k>=0;--k)
        if(st.f[u][k]!=st.f[v][k])
            u=st.f[u][k],v=st.f[v][k];
    return st.f[u][0];
}

int main(){
    freopen("C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Program\\Luogu\\temp-exer\\P3379_1.in","r",stdin);
    puts("-yyy");
    memset(head,-1,sizeof(head));
    int n=read();
    int m=read();
    int head=read();

    puts("-yyy");

    int u,v;

    for(register int i=1;i<n;++i){
        u=read();
        v=read();
        addEdge(u,v);
        addEdge(v,u);
    }

    count(head,head);
    st.build(n,pa);

    puts("-yyy");

    for(register int i=0;i<m;++i){
        u=read();
        v=read();
        printf("%d\n",LCA_ST(u,v));
    }
    return 0;
}