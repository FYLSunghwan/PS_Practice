#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string a,b;
    ll asum=0,bsum=0;
    cin >> a >> b;
    for(auto& i:a) asum+=(i-'0');
    for(auto& i:b) bsum+=(i-'0');
    cout << (asum*bsum);
    return 0;
}