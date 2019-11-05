#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class Segtree {
private:
    int N;
    vector<ll>& ar;
    vector<ll> tree;
    ll init(int node, int s, int e) {
        if(s==e) return tree[node] = ar[s];
        return tree[node] = init(node*2, s,(s+e)/2) + init(node*2+1, (s+e)/2+1, e);
    }

public:
    Segtree(int n, vector<ll>& inp) : N(n), ar(inp) {
        tree.resize(4*n+1);
        init(1,1,n);
    }

    ll GetSum(int node, int s, int e, int l, int r) {
        if(l<=s && e<=r) return tree[node];
        if(r<s || e<l) return 0;
        return GetSum(node*2,s,(s+e)/2,l,r) + GetSum(node*2+1,(s+e)/2+1,e,l,r);
    }

    void UpdTree(int node, int s, int e, int idx, ll diff) {
        if(idx<s || idx>e) return;
        tree[node] = tree[node] + diff;
        if(s!=e) {
            UpdTree(node*2, s, (s+e)/2, idx, diff);
            UpdTree(node*2+1, (s+e)/2+1, e, idx, diff);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, K, iter;
    vector<ll> ar;
    cin>>N>>M>>K;
    ar.resize(N+1);
    for(int i=1;i<=N;i++) {
        cin>>ar[i];
    }
    Segtree tree(N,ar);
    iter = (M+K);
    while(iter--) {
        ll k, a, b;
        cin>>k>>a>>b;
        if(k==1) {
            ll diff = b-ar[a];
            ar[a] = b;
            tree.UpdTree(1, 1, N, a, diff);
        }
        else {
            cout<<tree.GetSum(1, 1, N, a, b)<<'\n';
        }
    }
    return 0;
}