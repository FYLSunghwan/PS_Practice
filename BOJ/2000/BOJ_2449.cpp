#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K, ar[201];
ll dp[201][201];

int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> ar[i];
    for(int lim=1;lim<N;lim++) {
        for(int n=lim-1;n>=0;n--) {
            dp[n][lim] = 1e9;
            for(int k=n;k<lim;k++) {
                dp[n][lim] = min(dp[n][lim], dp[n][k]+dp[k+1][lim] + (ar[n]!=ar[k+1]));
            }
        }
    }
    cout << dp[0][N-1];
}