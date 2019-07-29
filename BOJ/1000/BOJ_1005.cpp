#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vec = vector<ll>;
using VV = vector<vector<ll>>;
using Que = queue<ll>;

int main() {
    ll N,M,T,K;
    VV g;
    Vec cnt;
    Vec tm;
    Vec dist;
    cin>>T;
    while(T--) {
        dist.clear();
        tm.clear();
        cnt.clear();
        g.clear();
        cin>>N>>M;
        dist.resize(N+1);
        tm.resize(N+1);
        cnt.resize(N+1);
        g.resize(N+1);
        for(int i=1;i<=N;i++) cin>>tm[i];
        for(int i=1;i<=M;i++) {
            ll a,b;
            cin>>a>>b;
            g[a].push_back(b);
            cnt[b]++;
        }
        cin>>K;
        Que q;
        for(int i=1;i<=N;i++)
            if(!cnt[i]) {
                dist[i] = tm[i];
                q.push(i);
            }
        while(!q.empty()) {
            ll p = q.front();
            q.pop();
            if(p==K) break;

            for(auto &i:g[p]) {
                cnt[i]--;
                dist[i] = max(dist[i],dist[p]+tm[i]);
                if(!cnt[i]) q.push(i);
            }
        }
        cout<<dist[K]<<'\n';
    }
    return 0;
}