#include <iostream>
#include <utility>
using namespace std;
using ll = long long;

ll def[100001], N, Q;
pair<ll, ll> tree[400001];

void update(int node, int l, int r, int s, int e, ll p) {
    if(l>e || r<s) return;
    if(s <= l && r <= e)
    {
        tree[node].first++;
        tree[node].second += p;
        return;
    }
    update(node*2, l, (l+r)/2, s, e, p);
    update(node*2+1, (l+r)/2+1, r, s, e, p);
}

ll query(int idx) {
    int l = 1, r = N, node = 1;
    ll lsum = 0, cntsum = 0;
    while(l<r) {
        int mid  =(l+r)/2;
        if(idx<=mid) {
            r = mid;
            node = node * 2;
        }
        else  {
            l=mid+1;
            node = node * 2 + 1;
        }
    }
    while(node>=1) {
        cntsum += tree[node].first;
        lsum += tree[node].second;
        node/=2;
    }
    return def[idx] + cntsum*(ll)idx - lsum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> def[i];
    cin >> Q;
    while(Q--) {
        int term, l, r;
        cin >> term;
        if(term == 1) {
            cin >> l >> r;
            update(1, 1, N, l, r, l - 1);
        }
        else {
            cin >> l;
            cout << query(l) << '\n';
        }
    }
    return 0;
}