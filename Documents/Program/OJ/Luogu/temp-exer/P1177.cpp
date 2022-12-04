#include <cstdio>
#include <algorithm>

int arr[100000+10];

int read(){
    register int x=0;char f=0,c=getchar();
    while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
    while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return f?-x:x;
}

int main(){
    int n=read();
    register int i;

    for(i=0;i<n;++i) arr[i]=read();
    std::sort(arr,arr+n);
    for(i=0;i<n;++i) printf("%d ",arr[i]);

    return 0;
}