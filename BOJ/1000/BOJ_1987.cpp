#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int R, C;
char ar[21][21];
bool visited[21][21];
int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
int ans = -1;

bool isPos(ll state, int y, int x)
{
    ll mask = 1<<(ar[y][x]-'A');
    return y>=0 && y<R && x>=0 && x<C
        && !(mask & state) && !visited[y][x];
}


void dfs(int y, int x, ll state, int cnt)
{
    for(int i=0;i<4;i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(isPos(state, ny, nx))
        {
            visited[ny][nx] = true;
            dfs(ny, nx, state|(1<<(ar[ny][nx]-'A')), cnt+1);
            visited[ny][nx] = false;
        }
    }
    ans = max(ans, cnt);
}

int main()
{
    cin >> R >> C;
    for(int i=0;i<R;i++) cin >> ar[i];
    dfs(0,0,1<<(ar[0][0]-'A'),1);
    cout << ans;
    return 0;
}