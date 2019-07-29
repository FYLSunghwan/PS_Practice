#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vec = vector<ll>;
using Que = queue<ll>;

int N,M;
Vec graph[100001];
ll cnt[100001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        cnt[b]++;
    }
    Que q;
    for(int i=1;i<=N;i++)
        if(!cnt[i]) q.push(i);
    while(!q.empty()) {
        ll p = q.front();
        q.pop();
        cout<<p<<" ";
        for(auto i:graph[p]) {
            cnt[i]--;
            if(!cnt[i]) q.push(i);
        }
    } 
    return 0;
}