#include <iostream>
using namespace std;
int N, M, ans, i, cnt, now=1;
int main() {
    cin >> N >> M;
    while(i<M) {
        ++i;++cnt;
        if(i>=N) ans+=now;
        if(cnt>=now) {now++;cnt=0;}
    }
    cout << ans;
}