#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#define file

//************************************************************************************************
#include <cstring>
#define MATRIX_MOD %100000007
#define MATRIX_TYPE long long
const int MATRIX_MAX_N=2;
const int MATRIX_MAX_M=2;
struct MATRIX{
    int n,m;
    MATRIX_TYPE matrix[MATRIX_MAX_N][MATRIX_MAX_M];

    MATRIX(){
        memset(matrix,0,sizeof(matrix));
        return;
    }

    void operator = (const MATRIX &a){
        n=a.n;
        m=a.m;
        for(register int i=0;i<n;++i)
            for(register int j=0;j<m;++j)
                matrix[i][j]=a.matrix[i][j];
    }

    MATRIX operator + (const MATRIX &a) const {
        MATRIX ans;
        ans.n=n;
        ans.m=m;
        for(register int i=0;i<n;++i)
            for(register int j=0;j<m;++j)
                ans.matrix[i][j]=(matrix[i][j]+a.matrix[i][j])MATRIX_MOD;

        return ans;
    }

    MATRIX operator * (const MATRIX &a) const {
        MATRIX ans;
        ans.n=n;
        ans.m=a.m;
        for(register int i=0;i<n;++i)
            for(register int k=0;k<m;++k)
                for(register int j=0;j<a.m;++j)
                    ans.matrix[i][j]=(ans.matrix[i][j]+matrix[i][k]*a.matrix[k][j]MATRIX_MOD)MATRIX_MOD;

        return ans;
    }

    friend MATRIX operator ^ (MATRIX base,MATRIX_TYPE exponential){
        MATRIX ans;
        ans.n=base.n;
        ans.m=base.n;

        for(register int i=0;i<base.n;++i)
            ans.matrix[i][i]=1;

        while(exponential){
            if(exponential&1) ans=ans*base;
            base=base*base;
            exponential>>=1;
        }

        return ans;
    }

    void print(){
        for(register int i=0;i<n;++i){
            for(register int j=0;j<n;++j)
                printf("%d ",matrix[i][j]MATRIX_MOD);
            putchar('\n');
        }

        return;
    }
}base,ans;
//************************************************************************************************

long long read();

int main(){
	#ifdef file
	freopen("war.in", "r", stdin);
	freopen("war.out", "w", stdout);
	#endif

    long long n=read();

    base.n=1;
    base.m=2;
    base.matrix[0][0]=1;
    base.matrix[0][1]=1;

    ans.n=2;
    ans.m=2;
    ans.matrix[0][0]=1;
    ans.matrix[0][1]=1;
    ans.matrix[1][0]=1;

    ans=ans^n;
    base=base*ans;

    printf("%lld",base.matrix[0][0]MATRIX_MOD);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

long long read(){
    long long x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}