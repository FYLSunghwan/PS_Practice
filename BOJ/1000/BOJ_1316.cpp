#include <iostream>
using namespace std;

int main() {
    int N,ans=0;
    string inp;
    cin >> N;
    while(N--) {
        int is[50]={0,};
        bool isans=true;
        cin >> inp;
        char bef;
        bef = inp[0];
        for(int i=1;i<inp.length();i++) {
            if(is[inp[i]-'a']) isans=false;
            if(bef!=inp[i]) {
                is[bef-'a']=1;
            }
            bef=inp[i];
        }
        ans += isans;
    }
    cout << ans;
}