#include <iostream>
#include <string>
using namespace std;

int main() {
    string inp;
    int ans=0, p=0;
    cin >> inp;
    while(p<inp.length()) {
        ans++;
        if(p+1<inp.length()) {
            if(inp[p]=='c') {
                if(inp[p+1]=='=' || inp[p+1]=='-') p++;
            }
            else if(inp[p]=='d') {
                if(inp[p+1]=='-') p++;
                else if(p+2<inp.length() && inp[p+1]=='z' && inp[p+2]=='=') p+=2;
            }
            else if(inp[p]=='l' && inp[p+1]=='j') p++;
            else if(inp[p]=='n' && inp[p+1]=='j') p++;
            else if(inp[p]=='s' && inp[p+1]=='=') p++;
            else if(inp[p]=='z' && inp[p+1]=='=') p++;
        }
        p++;
    }
    cout << ans;
}