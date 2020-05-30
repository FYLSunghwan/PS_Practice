#include<bits/stdc++.h>
using namespace std;
int ar[101][101], ans;

int main() {
    for(int i=0;i<4;i++) {
        int xs, ys, xe, ye;
        cin >> xs >> ys >> xe >> ye;
        for(int y=ys;y<ye;y++) for(int x=xs;x<xe;x++) ar[y][x]=1;
    }
    for(int i=0;i<101;i++) for(int j=0;j<101;j++) ans += ar[i][j];
    cout << ans;
    return 0;
}