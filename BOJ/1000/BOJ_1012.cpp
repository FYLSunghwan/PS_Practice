#include <iostream>
#include <memory.h>
using namespace std;
using ll = long long;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
ll baechu[51][51], ans=0;
ll M, N, K;

bool isPos(ll (*baechu)[51], int y, int x) {
    return y>=0 && y<N && x>=0 && x<M && baechu[y][x];
}
void fills(ll (*baechu)[51], int y, int x) {
    baechu[y][x]=0;
    for(int i=0;i<4;i++) {
        if(isPos(baechu, y+dy[i], x+dx[i])) 
            fills(baechu, y+dy[i], x+dx[i]);
    }
}

int main() {
    ll T;
    cin >> T;
    while(T--) {
        memset(baechu,0,sizeof(baechu));
        ans=0;
        cin >> M >> N >> K;
        while(K--) {
            int x, y;
            cin >> x >> y;
            baechu[y][x] = 1;
        }
        for(int y=0;y<N;y++) {
            for(int x=0;x<M;x++) {
                if(baechu[y][x]) {
                    ans++;
                    fills(baechu, y, x);
                }
            }
        }
        cout << ans << endl;
    }
}