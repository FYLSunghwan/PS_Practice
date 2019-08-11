#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

class Mintree {
protected:
    int N;
    vector<ll>& ar;
    vector<ll> tree;
    ll init(int node, int s, int e) {
        if(s==e) return tree[node] = ar[s];
        return tree[node] = min(init(node*2, s,(s+e)/2), init(node*2+1, (s+e)/2+1, e));
    }

public:
    Mintree(int n, vector<ll>& inp) : N(n), ar(inp) {
        tree.resize(4*n+1);
        init(1,1,n);
    }

    ll GetMin(int node, int s, int e, int l, int r) {
        if(l<=s && e<=r) return tree[node];
        if(r<s || e<l) return 2e9;
        return min(GetMin(node*2,s,(s+e)/2,l,r), GetMin(node*2+1,(s+e)/2+1,e,l,r));
    }
};

class Maxtree {
    private:
        int N;
        vector<ll>& ar;
        vector<ll> tree;
        ll init(int node, int s, int e) {
            if(s==e) return tree[node] = ar[s];
            return tree[node]  = max(init(node*2, s,(s+e)/2), init(node*2+1, (s+e)/2+1, e));
        }
    
    public:
        Maxtree(int n, vector<ll>& inp) : N(n), ar(inp) {
            tree.resize(4*n+1);
            init(1,1,n);
        }

        ll GetMax(int node, int s, int e, int l, int r) {
            if(l<=s && e<=r) return tree[node];
            if(r<s || e<l) return 0;
            return max(GetMax(node*2,s,(s+e)/2,l,r), GetMax(node*2+1,(s+e)/2+1,e,l,r));
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, K, iter;
    vector<ll> ar;
    cin>>N>>M;
    ar.resize(N+1);
    for(int i=1;i<=N;i++) {
        cin>>ar[i];
    }
    Mintree tree(N,ar);
    Maxtree tree2(N,ar);
    while(M--) {
        ll a, b;
        cin>>a>>b;
        cout<<tree.GetMin(1,1,N,a,b)<<' '<<tree2.GetMax(1,1,N,a,b)<<'\n';
    }
    return 0;
}