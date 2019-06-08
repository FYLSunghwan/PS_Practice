//BOJ 14501
#include <iostream>
#include <algorithm>
using namespace std;

int t[16],p[16],n,memo[16];
int dp(int k) {
    if(k>n) return 0;
    if(memo[k]) return memo[k];
    memo[k]=max(dp(k+t[k])+p[k]*(k+t[k]<=n+1),dp(k+1));
    return memo[k];
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i]>>p[i];
    cout<<dp(1);
    return 0;
}
