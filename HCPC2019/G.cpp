#include <deque>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n *= 2;
    int sw = 0;
    deque<int> up, down;
    for(int i=1;i<=n;i++)
    {
        switch(sw)
        {
            case 0:
                up.push_front(i);
                break;
            case 1:
                down.push_front(i);
                break;
            case 2:
                down.push_back(i);
                break;
            case 3:
                up.push_back(i);
                break;
        }
        sw = (sw+1) % 4;
    }
    long long ans = 0;
    for(int i = 2; i<= n; i++)
    {
        ans += (i+n)*(n-i+1)/2*(i-1);
    }
    cout << ans << endl;
    for(auto i:up) cout <<i << " ";
    cout << endl;
    for(auto i:down) cout << i << " ";
    cout <<endl;
    return 0;
    
}
