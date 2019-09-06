#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int n, k, visited[400000];
int main() {
    cin>>n>>k;
    queue<pair<int,int>> q;
    q.push({n,0});
    while(!q.empty()) {
        int nt = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(nt>=200000) continue;
        if(nt==k) {
            cout<<cnt;
            break;
        }
        visited[nt]=1;
        if(nt*2<=300000 && !visited[nt*2]) q.push({nt*2,cnt+1});
        if(!visited[nt+1]) q.push({nt+1,cnt+1});
        if(!visited[nt-1]) q.push({nt-1,cnt+1});
    }
    return 0;
}