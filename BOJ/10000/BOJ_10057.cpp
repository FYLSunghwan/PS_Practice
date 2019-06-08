//BOJ 11057
#include <cstdio>
long long int dp[1001][10];
int n;
int main() {
    for(int i=0;i<=9;i++) dp[1][i]=i+1;
    scanf("%d",&n);
    for(int i=2;i<=n;i++) {
        dp[i][0]=dp[i-1][0];
        for(int j=1;j<10;j++) dp[i][j]=(dp[i][j-1]+dp[i-1][j])%10007;
    }
    printf("%d",dp[n][9]);
    return 0;
}
