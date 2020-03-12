#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string inp;
        cin >> inp;
        int len = inp.length();
        int cnt=0,maxans=-1;
        for(int i=0;i<len;i++) {
            if(inp[i]=='L') {
                cnt++;
            }
            else cnt=0;
            maxans=max(maxans,cnt);
        }
        cout << (maxans+1) << endl;
    }
}