#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, n, k;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll cnt=1;
        while(k>1) {
            if(n<cnt) break;
            n -= cnt;
            cnt += 2;
            k--;
        }
        if(n%2 && n >= cnt && k==1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}