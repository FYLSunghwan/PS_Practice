#include <iostream>
#include <string>
using namespace std;

int main() {
    string inp;
    int ans=0;
    cin >> inp;
    for(auto& it:inp) {
        if(it>='W') ans+=9;
        else if(it>='T') ans+=8;
        else if(it>='P') ans+=7;
        else ans+=((it-'A')/3+2);
    }
    ans += inp.length();
    cout << ans;
}