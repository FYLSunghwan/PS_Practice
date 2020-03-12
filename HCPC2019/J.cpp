#include <iostream>
#include <string.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll memo[1000001];
ll mul(ll a, ll x)
{
    if(memo[x] > 0) return memo[x];
    if(x == 1) return memo[x] = a;
    if(x == 0) return memo[x] = 1;
    return memo[x] = ((mul(a, x/2)%MOD)*(mul(a, x-x/2)%MOD)-MOD) % MOD +MOD;
}

int main()
{
    ll h, x, tot = 0;
    cin >> h >> x;
    for(int i=1; i<=h; i++)
    {
        ll tmp;
        cin >> tmp;
        tot = (tot+(mul(x, i)*tmp) -MOD) % MOD +MOD;
    }
    cout << tot%MOD;
    return 0;
}