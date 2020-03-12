#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

struct Node {
    ll value;
    vector<ll> lazy;
};

class Segtree {
private:
    int N;
    vector<ll>& ar;
    vector<Node> tree;
    ll init(int node, int s, int e) {
        if(s==e) return tree[node].value = ar[s];
        return tree[node].value = (init(node*2, s,(s+e)/2) + init(node*2+1, (s+e)/2+1, e));
    }

public:
    Segtree(int n, vector<ll>& inp) : N(n), ar(inp) {
        tree.resize(4*n+1);
        init(1,1,n);
    }

    ll GetSum(int node, int s, int e, int sums, int sume) {
        if(!tree[node].lazy.empty())
        {
            for(auto& lz : tree[node].lazy)
            {
                tree[node].value += ((e-s+1) * lz +  (e-s)*(e-s+1)/2);
                if(s!=e)
                {
                    tree[node*2].lazy.push_back(lz);
                    tree[node*2+1].lazy.push_back(lz+(e-s+1)/2);
                }
            }
            tree[node].lazy.clear();
        }
        if(sums > e || sume < s) return 0;
        if(sums <= s && e <= sume) return tree[node].value;
        return GetSum(node*2, s, (s+e)/2, sums, sume) + GetSum(node*2+1, (s+e)/2+1,e, sums, sume);
    }

    void UpdTree(int node, int s, int e, int upds, int upde, ll val) {
        if(!tree[node].lazy.empty())
        {
            for(auto& lz : tree[node].lazy)
            {
                tree[node].value += (e-s+1)*lz + (e-s)*(e-s+1)/2;
                if(s!=e)
                {
                    tree[node*2].lazy.push_back(lz);
                    tree[node*2+1].lazy.push_back(lz+(e-s+1)/2);
                }
            }
            return;
        }
        if(upde < s || upds > e) return;
        if(upds <= s && e <= upde)
        {
            tree[node].value += ((e-s+1) * val + (e-s)*(e-s+1)/2);
            if(s!=e)
            {
                tree[node*2].lazy.push_back(val);
                tree[node*2+1].lazy.push_back(val+(e-s+1)/2);
            }
            return;
        }
        UpdTree(node*2, s, (s+e)/2, upds, upde, val);
        UpdTree(node*2+1, (s+e)/2+1, e, upds, upde, val+(e-s+1)/2);

        tree[node].value = tree[node*2].value + tree[node*2+1].value;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    vector<ll> ar;
    cin>>N;
    ar.resize(N+1);
    for(int i=1;i<=N;i++) {
        cin>>ar[i];
    }
    Segtree tree(N,ar);
    cin >> Q;
    while(Q--) {
        ll x, a, b;
        cin>>x;
        if(x==1) {
            cin >> a >> b;
            tree.UpdTree(1,1,N,a,b,1);
        }
        else {
            cin >> a;
            cout<<tree.GetSum(1, 1, N, a, a) + 1<<'\n';
        }
    }
    return 0;
}