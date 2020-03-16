#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long N, M, t, cnt;
set<ll> ns;

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> t;
        ns.insert(t);
    }
    for(int i=0;i<M;i++) {
        cin >> t;
        if(ns.find(t) != ns.end()) cnt++;
    }
    cout <<(N+M-cnt*2);
    return 0;
}