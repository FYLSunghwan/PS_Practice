#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        ll n, a[100001];
        cin >> n;
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        int back=a[0];
        ll cnt=n;
        for(int i=1;i<n;i++) {
            if(a[i]==back) cnt--;
            back=a[i];
        }
        cout << cnt << "\n";
    }
    return 0;
}