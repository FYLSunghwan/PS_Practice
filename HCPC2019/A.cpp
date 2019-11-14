#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;

int main()
{
    vector<pair<ll,ll> > cur;
    ll t=0, sc=0, inp, inpsc, inpt, N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        int flag;
        cin >> flag;
        if(flag)
        {
            cin >> inpsc >> inpt;
            cur.push_back(make_pair(i+inpt-1, inpsc));
        }
        while(cur.size() && cur.back().first == i)
        {
            sc += cur.back().second;
            cur.pop_back();
        }
    }
    cout << sc << endl;
    return 0;
}