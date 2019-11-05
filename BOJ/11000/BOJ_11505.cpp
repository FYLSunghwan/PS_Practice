#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

class Segtree {
private:
    int N;
    vector<ll>& ar;
    vector<ll> tree;
    ll init(int node, int s, int e) {
        if(s==e) return tree[node] = ar[s];
        return tree[node] = (init(node*2, s,(s+e)/2) * init(node*2+1, (s+e)/2+1, e)) % MOD;
    }

public:
    Segtree(int n, vector<ll>& inp) : N(n), ar(inp) {
        tree.resize(4*n+1);
        init(1,1,n);
    }

    ll GetMul(int node, int s, int e, int l, int r) {
        if(l<=s && e<=r) return tree[node];
        if(r<s || e<l) return 1;
        return (GetMul(node*2,s,(s+e)/2,l,r) * GetMul(node*2+1,(s+e)/2+1,e,l,r))%MOD;
    }

    ll UpdTree(int node, int s, int e, int idx, ll val) {
        if(idx<s || idx>e) return tree[node];
        if(s==e) return tree[node] = val;
        return tree[node] = (UpdTree(node*2, s, (s+e)/2, idx, val) * 
                            UpdTree(node*2+1, (s+e)/2+1, e, idx, val))%MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, K, iter;
    vector<ll> ar;
    cin>>N>>M>>K;
    ar.resize(N+1);
    iter = M + K;
    for(int i=1;i<=N;i++) {
        cin>>ar[i];
    }
    Segtree tree(N,ar);
    while(iter--) {
        ll x, a, b;
        cin>>x>>a>>b;
        if(x==1) {
            tree.UpdTree(1,1,N,a,b);
        }
        else 
            cout<<tree.GetMul(1, 1, N, a, b)<<'\n';
    }
    return 0;
}