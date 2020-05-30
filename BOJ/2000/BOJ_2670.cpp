#include<bits/stdc++.h>
using namespace std;
double ar[10001],mx=-1,now=1;
int N;

int main() {
    cin >> N;
    for(int i=0;i<N;i++) cin >> ar[i];
    for(int i=0;i<N;i++) {
        now*=ar[i];
        if(now>mx) mx=now;
        if(now<1) now=1;
    }
    cout.precision(3);
    cout << fixed << mx;
    return 0;
}