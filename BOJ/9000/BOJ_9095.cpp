//BOJ 9095
#include <iostream>
#include <algorithm>
using namespace std;
int memo[11]={1,1,},t,n;
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++)
            memo[i] = (i>=3?memo[i-3]:0) + (i>=2?memo[i-2]:0) +(i>=1?memo[i-1]:0);

        cout<<memo[n]<<endl;
    }
}