#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
using namespace std;

int main()
{
    map<string, pair<long long, long long> > menu;
    long long A, B, C, N, sums[3] = {0}, cnt[3] = {0}, price;
    string name;

    cin >> A >> B >> C;
    while(A--)
    {
        cin >> name >> price;
        menu[name] = make_pair(0, price);
    }
    while(B--)
    {
        cin >> name >> price;
        menu[name] = make_pair(1, price);
    }
    while(C--)
    {
        cin >> name;
        menu[name] = make_pair(2, 1);
    }
    cin >> N;
    while(N--)
    {
        string query;
        cin >> query;
        sums[menu[query].first] += menu[query].second;
        cnt[menu[query].first] ++;
    }
    bool ans = true;
    if(cnt[1] && sums[0] < 20000) ans = false;
    if(cnt[2] && sums[0] + sums[1] < 50000) ans = false;
    if(cnt[2] > 1) ans = false;
    cout << (ans ? "Okay" : "No");
    return 0;
}