#include <cstdio>

char book[100000010];
int primes[6000010];

int read(){
	register int x=0;char f=0,c=getchar();
	while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return f?-x:x;
}

int main(){
	int n,q;
	register int i,j,cnt=0;
	n=read();
	q=read();
	
	for(i=2;i<=n;++i){
		if(!book[i]) primes[cnt++]=i;
		for(j=0;j<cnt;++j){
			if(primes[j]*i>n) break;
			book[i*primes[j]]=1;
			if((!(i%primes[j]))) break;
		}
	}
	
	for(i=0;i<q;++i) printf("%d\n",primes[read()-1]);
	
	return 0;
}
