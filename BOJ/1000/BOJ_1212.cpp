#include <bits/stdc++.h>
using namespace std;

string inp;
string ans;

int main() {
    cin >> inp;
    for(auto& i:inp) {
        int k = i-'0';
        int tmp = 4;
        while(k) {
            ans.append(to_string(k%tmp));
            if(k%tmp) k-=tmp;
            tmp/=2;
        }
    }
    cout << ans;
    return 0;
}