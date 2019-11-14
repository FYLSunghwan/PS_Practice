#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ll N, T;
    cin >> N >> T;
    ll cnt=0, piv=0, dx = 1;
    while(cnt < T)
    {
        piv+=dx;
        cnt++;
        if(dx > 0 && piv==2*N) dx = -1;
        if(dx < 0 && piv==1) dx=1;
    }
    cout << piv;
    return 0;
}