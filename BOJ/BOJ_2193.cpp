//BOJ 2193
#include <cstdio>
long long int dp[91][2];
int n;
int main() {
    dp[1][1]=1;
    scanf("%d",&n);
    for(int i=2;i<=n;i++) {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    printf("%lld",dp[n][0]+dp[n][1]);
    return 0;
}
