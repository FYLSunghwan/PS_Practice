#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, ar[51][51];

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            scanf("%1d",&ar[i][j]);
        }
    }
    ll ans = 1;
    ll limit = min(N ,M);
    for(int i=2;i<=limit;i++) {
        for(int y=0;y<=N-i;y++) {
            for(int x=0;x<=M-i;x++) {
                if(ar[y][x]==ar[y+i-1][x+i-1]
                && ar[y][x]==ar[y+i-1][x]
                && ar[y][x]==ar[y][x+i-1]) ans=i;
            }
        }
    }
    cout << (ans*ans);
}