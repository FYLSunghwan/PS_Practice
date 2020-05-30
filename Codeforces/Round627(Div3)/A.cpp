#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,ar[101];
        bool ans=true;
        cin >> n;
        for(int i=0;i<n;i++) cin >> ar[i];
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(abs(ar[i]-ar[j])%2) ans=false;
            }
        }
        cout << (ans?"YES":"NO") << endl;
    }
}