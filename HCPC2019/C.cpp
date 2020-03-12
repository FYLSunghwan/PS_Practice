#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

ll muls[16];

ll toDex(string& st)
{
    ll len = st.size();
    ll ans = 0;
    for(int i = 0; i<len;i++)
    {
        char c = st[len-1-i];
        if(c>='0' && c<='9') c-='0';
        else 
        {
            c-='a';
            c+=10;
        }
        ans += muls[i] * c;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<=15;i++)
    {
        muls[i] = pow(16,i);
    }

    map<string, ll> cap;
    ll k;
    cap["char"] = 2;
    cap["int"] = 8;
    cap["long_long"] = 16;
    string full, inp;

    cin >> full;
    cin >> k;

    while(k--)
    {
        cin >> inp;
        ll tmp = cap[inp];
        string mys = full.substr(0,tmp);
        ll out = 0;
        /*
        if(k) out = stoi(mys, 0, 16);
        else out = stoi(full,0,16);
        */
        if(k) out = toDex(mys);
        else out = toDex(full);
        full = full.substr(tmp);
        cout << out << " ";
    }
}