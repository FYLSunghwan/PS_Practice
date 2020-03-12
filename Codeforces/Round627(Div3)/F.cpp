#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, color[200001], cnts[200001];
vector<ll> graph[200001];
vector<ll> graph2[200001];

void make_graph(ll i) {
    for(auto& next:graph[i]) {
        graph2[i].push_back(next);
        make_graph(next);
    }
}

ll pre(ll i) {
    if(graph2[i].empty()) {
        return cnts[i]=color[i]?1:-1;
    }
    cnts[i] = (color[i]?1:-1);
    for(auto& next:graph2[i]) {
        cnts[i] += max(pre(next.first),0LL);
    }
    return cnts[i];
}

void after(ll i) {
    for(auto& next:graph2[i]) {
        cnts[node] = max(cnts[node], cnts[i]-cnts[node]);
        after(node);
    }
}

int main() 
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> color[i];
    for(int i=0;i<n-1;i++) {
        ll s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    make_graph(1);
    pre(1);
    after(1);
    for(int i=1;i<=n;i++) cout << cnts[i] << " ";
}