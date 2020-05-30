#include <bits/stdc++.h>
using namespace std;

string inp;
struct ap {
    int cnt=0;
    char ch;
    bool operator<(const ap& rhs) {
        if(cnt == rhs.cnt) return ch < rhs.ch;
        return cnt > rhs.cnt;
    }
};

ap cnt['z'-'a'+1];
int main() {
    for(int i=0;i<'z'-'a'+1;i++) cnt[i].ch = (char)(i+'a');
    while(getline(cin, inp)) {
        for(auto& i: inp)
            if(i>='a' && i<='z') cnt[i-'a'].cnt++;
    }
    sort(cnt, cnt+'z'-'a'+1);
    cout << cnt[0].ch;
    int back = cnt[0].cnt;
    for(int i=1;i<='z'-'a';i++) {
        if(back!=cnt[i].cnt) break;
        cout << cnt[i].ch;
    }
}