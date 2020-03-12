#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    ll A, B;
    cin >> A >> B;
    ll D = A*A - B;
    if(D==0)
    {
        ll R = (ll)sqrt(D);
        ll ans = -A;
        cout << ans;
    }
    else
    {
        ll R = (ll)sqrt(D);
        ll ans1 = -A + R;
        ll ans2 = -A - R;
        if(ans1 < ans2)
            cout << ans1 << " " << ans2;
        else
            cout << ans2 << " " << ans1;
    }
    return 0;
}