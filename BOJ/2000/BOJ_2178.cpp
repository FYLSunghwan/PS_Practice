//BOJ 2178
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

queue<pair<pair<int,int>,int>> q;
int n,m,ar[101][101],dy[4]={1,-1,0,0},dx[4]={0,0,1,-1};

int isPos(int y,int x) {return y>0 && y<=n && x>0 && x<=m && ar[y][x]==1;}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%1d",&ar[i][j]);
    q.push(make_pair(make_pair(1,1),1));
    while(!q.empty()) {
        pair<int,int> t = q.front().first;
        int sc=q.front().second;
        q.pop();
        if(t.first == n && t.second == m) {
            printf("%d",sc);
            return 0;
        }
        for(int i=0;i<4;i++)
            if(isPos(t.first+dy[i],t.second+dx[i])) {
                q.push(make_pair(make_pair(t.first+dy[i],t.second+dx[i]),sc+1));
                ar[t.first+dy[i]][t.second+dx[i]]=0;
            }
    }
    return 0;
}