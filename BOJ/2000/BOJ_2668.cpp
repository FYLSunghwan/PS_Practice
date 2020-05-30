#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, ar[101], visited[101], ans[101], cnt=0;
vector<ll> csps;

int findCSP(int now) {
    if(visited[now]) return now;
    findCSP(ar[now]);
}

void findANS(int now) {
    if(ans[now]) return;
    findANS(ar[now]);
    ++cnt;
}

int main() {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> ar[i];
    for(int i=1;i<=N;i++) {
        if(visited[i]) continue;
        csps.push_back(findCSP(i));
    }
    for(auto& i:csps) {
        findANS(i);
    }
    cout << cnt << endl;
    for(int i=1;i<=N;i++) {
        if(ans[i]) cout << i << endl;
    }
}