#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, L;
    vector<ll> ar;
    cin>>N>>L;
    ar.resize(N+1);
    for(int i=1;i<=N;i++) {
        cin>>ar[i];
    }
    deque<ll> dq;
    for(int i=1;i<=N;i++) {
        while(!dq.empty() && dq.front() <= i-L) dq.pop_front();
        while(!dq.empty() && ar[dq.back()] >= ar[i]) dq.pop_back();
        dq.push_back(i);
        cout<<ar[dq.front()]<<" ";
    }
    return 0;
}