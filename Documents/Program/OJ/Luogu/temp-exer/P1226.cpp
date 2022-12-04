#include <cstdio>

int read(){
    register int x=0;char f=0,c=getchar();
    while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
    while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return f?-x:x;
}

int qpow(register long long base,register long long e,register const long long mod){
    base%=mod;
    register long long ans=1;
    while(e){
        if(e&1) ans=base*ans%mod;
        base=base*base%mod;
        e>>=1;
    }
    return ans;
}

int main(){
    int base=read();
    int e=read();
    int mod=read();
    printf("%d^%d mod %d=%lld",base,e,mod,qpow(base,e,mod));
    return 0;
}