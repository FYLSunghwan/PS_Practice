#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<pair<ll,ll>> graph[10001];
ll cnts[10001];
pair<ll,ll> cntsp[10001];
ll ans[10001];

int main() {
    cin >> n;
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++) {
        cntsp[i].second=i;
    }
    for(int i=0;i<n-1;i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(make_pair(i,b));
        graph[b].push_back(make_pair(i,a));
        cnts[a]++;
        cnts[b]++;
    }
    for(int i=1;i<=n;i++) {
        cntsp[i].first = cnts[i];
    }
    sort(cntsp+1, cntsp+n+1);
    int cnttt=0;
    for(int i=n;i>=1;i--) {
        int p = cntsp[i].first;
        for(auto &j:graph[p]) {
            if(ans[j.first]!=-1) ans[j.first] = cnttt++;
        }
    }
    for(int i=0;i<n-1;i++) {
        cout << ans[i] << endl;
    }
}