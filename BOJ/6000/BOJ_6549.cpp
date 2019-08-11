#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

class Segtree {
private:
    int N;
    vector<ll>& ar;
    vector<ll> tree;
    ll init(int node, int s, int e) {
        if(s==e) return tree[node] = s;
        ll idx1 = init(node*2, s,(s+e)/2);
        ll idx2 = init(node*2+1, (s+e)/2+1, e);
        if(ar[idx1]<ar[idx2]) return tree[node] = idx1;
        return tree[node] = idx2;
    }

public:
    Segtree(int n, vector<ll>& inp) : N(n), ar(inp) {
        tree.resize(4*n+1);
        init(1,1,n);
    }

    ll GetMin(int node, int s, int e, int l, int r) {
        if(l<=s && e<=r) return tree[node];
        if(r<s || e<l) return -1;
        ll idx1 = GetMin(node*2,s,(s+e)/2,l,r);
        ll idx2 = GetMin(node*2+1,(s+e)/2+1,e,l,r);
        if(idx1==-1) return idx2;
        if(idx2==-1) return idx1;
        if(ar[idx1] < ar[idx2]) return idx1;
        return idx2;
    }

    ll solve(int s, int e) {
        if(s==e) return ar[s];
        ll idx = GetMin(1,1,N,s,e);
        ll ans = -1;
        if(s<idx) ans = solve(s,idx-1);
        if(e>idx) ans = max(ans,solve(idx+1,e));
        ans = max(ans, (e-s+1)*ar[idx]);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    while(1) {
        int inp;
        cin>>inp;
        if(!inp) break;
        vector<ll> ar(inp+1);
        for(int i=1;i<=inp;i++) cin>>ar[i];
        Segtree tree(inp,ar);
        cout<<tree.solve(1,inp)<<'\n';
    }
    return 0;
}