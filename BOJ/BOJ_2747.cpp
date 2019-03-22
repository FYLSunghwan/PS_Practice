//BOJ 2747
#include <cstdio>
long long int fibo[50]={0,1,0,};
int n;
int main() {
    scanf("%d",&n);
    for(int i=2;i<=n;i++) fibo[i]=fibo[i-1]+fibo[i-2];
    printf("%lld",fibo[n]);
    return 0;
}