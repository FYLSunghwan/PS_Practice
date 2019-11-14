#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll N, M, V[11][100001], dp[11][100001]={0};

int main()
{
    cin >> N >> M;
    ll tmpmax = -1;
    for(int i=1;i<=M;i++)
    {
        for(int j = 1; j<= N; j++)
        {
            cin >> V[i][j];
            if(j==1) dp[i][j] = V[i][j];
        }
    }
    for(int i=2;i<=N;i++)
    {
        for(int now = 1; now<=M; now++)
        {
            ll maxnum = -1;
            for(int back=1; back<=M;back++)
            {
                if(now==back)
                {
                    maxnum = max(V[now][i]/2 + dp[back][i-1], maxnum);
                }
                else
                {
                    maxnum = max(V[now][i] + dp[back][i-1], maxnum);
                }
            }
            dp[now][i] = maxnum;
        }
    }
    ll ans = -1;
    for(int i=1;i<=M;i++)
    {
        ans = max(ans, dp[i][N]);
    }
    cout << ans;
    return 0;
}
