#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int three[8][3] = {0,1,2, 0,1,3, 0,2,4, 0,3,4, 1,2,5, 1,3,5, 2,4,5, 3,4,5};
int two[12][2] = {0,1, 0,2, 0,3, 0,4, 1,2, 1,3, 1,5, 2,4, 2,5, 3,4, 3,5, 4,5};

int main() {
    ll N, dice[6];
    cin >> N;
    for(int i=0;i<6;i++) cin >> dice[i];
    ll threemin=9e9, twomin=9e9, onemin=9e9;
    for(int i=0;i<8;i++)
        threemin = min(threemin,dice[three[i][0]]+dice[three[i][1]]+dice[three[i][2]]);
    for(int i=0;i<12;i++)
        twomin = min(twomin, dice[two[i][0]]+dice[two[i][1]]);
    for(int i=0;i<6;i++)
        onemin = min(onemin, dice[i]);
    if(N==1) {
        int sum=0;
        ll maxnum=-1;
        for(int i=0;i<6;i++) {
            sum+=dice[i];
            maxnum = max(maxnum, dice[i]);
        }
        cout <<sum-maxnum;
    }
    else {
        cout << 4LL*threemin + (8LL*N-12LL)*twomin + (5LL*N*N-16LL*N+12LL)*onemin;
    }
    return 0;

}