#include <cstdio>

struct U{
    int fa[10000+10];
    void build(int n){
        register int i;
        for(i=1;i<=n;++i) fa[i]=i;
        return;
    }

    int find(int x){
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }

    void merge(int a,int b){
        fa[find(a)]=fa[find(b)];
    }
}u;

int read(){
    register int x=0;char f=0,c=getchar();
    while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
    while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return f?-x:x;
}

int main(){
    register int i,a,b;
    register char z;
    int n=read();
    int m=read();
    u.build(n);
    for(i=0;i<m;++i){
        z=read();
        a=read();
        b=read();
        if(z==2) puts(u.find(a)==u.find(b)?"Y":"N");
        else u.merge(a,b);
    }

    return 0;
}