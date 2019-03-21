//BOJ 2579
#include <iostream>
#include <algorithm>
using namespace std;
int dp[301][2],n,sc[301];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>sc[i];
    dp[1][0]=sc[1];
    for(int i=2;i<=n;i++) {
        dp[i][0]=sc[i]+max(dp[i-2][0],dp[i-2][1]);
        dp[i][1]=sc[i]+dp[i-1][0];
    }
    cout<<max(dp[n][0],dp[n][1]);
    return 0;
}