#include <bits/stdc++.h>
using namespace std;

bool cmp(string& fr, string& ba) {
    if(fr.length()==ba.length())
        return fr<ba;
    return fr.length() < ba.length();
}

int main() {
    string ar[20001];
    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> ar[i];
    sort(ar,ar+N,cmp);
    string back="";
    for(int i=0;i<N;i++) {
        if(back==ar[i]) continue;
        cout << ar[i] << endl;
        back=ar[i];
    }
    return 0;
}