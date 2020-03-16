#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[51][500001], N, H[51];

int main() {
    cin >> N;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++) cin >> H[i];
    dp[0][H[0]] = H[0];
    dp[0][0] = 0;
    for(int i=1;i<N;i++)
        for(int j=0;j<=500000;j++)
        {
            if(dp[i-1][j]==-1) continue;
            if(dp[i][j+H[i]] < dp[i-1][j]+H[i]) dp[i][j+H[i]] = dp[i-1][j]+H[i];
            if(H[i]>j && dp[i][H[i]-j] < dp[i-1][j]-j+H[i]) dp[i][H[i]-j] = dp[i-1][j]-j+H[i];
            if(H[i]<=j && dp[i][j-H[i]] < dp[i-1][j]) dp[i][j-H[i]] = dp[i-1][j];
            if(dp[i][j] < dp[i-1][j]) dp[i][j] = dp[i-1][j];
        }
    if(dp[N-1][0]==0) cout << -1;
    else cout << dp[N-1][0];
    return 0;
}