#include <bits/stdc++.h>
using namespace std;
string inp="none";
int main() {
    while(1) {
        cin >> inp;
        if(inp=="0") break;
        int i=0;
        bool flag=true;
        while(i*2<inp.size()) {
            if(inp[i]!=inp[inp.size()-i-1]) {
                flag=false;
            }
            i++;
        }
        cout << (flag?"yes":"no") << endl;
    }
    return 0;
}