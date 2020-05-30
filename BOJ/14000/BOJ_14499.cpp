#include <iostream>
using namespace std;
int N, M, K;
int mp[21][21], dice[6], x, y, dicemove[5][6] = {
        {0, 0, 0, 0, 0, 0},
        {4, 1, 0, 3, 5, 2},
        {2, 1, 5, 3, 0, 4},
        {1, 5, 2, 0, 4, 3},
        {3, 0, 2, 5, 4, 1},
};
int dy[5] = {0,0,0,-1,1}, dx[5] = {0,1,-1,0,0};
int newdice[6];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> y >> x >> K;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin >> mp[i][j];
    while(K--) {
        int cmd;
        cin >> cmd;
        if(y+dy[cmd] >= N || y+dy[cmd]<0 || x+dx[cmd]>=M || x+dx[cmd]<0) continue;
        y += dy[cmd];
        x += dx[cmd];
        for(int i=0;i<6;i++) newdice[i] = dice[dicemove[cmd][i]];
        for(int i=0;i<6;i++) dice[i] = newdice[i];
        if(mp[y][x]==0) mp[y][x] = dice[5];
        else {
            dice[5] = mp[y][x];
            mp[y][x] = 0;
        }
        cout << dice[0] << '\n';
    }
    return 0;
}