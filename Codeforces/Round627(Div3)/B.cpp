#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, ar[5001], ans=false;
        cin >> n;
        for(int i=0;i<n;i++) cin >> ar[i];
        for(int i=0;i<n-2;i++) {
            for(int j=i+2;j<n;j++) {
                if(ar[i]==ar[j]) ans=true;
            }
        }
        cout << (ans?"YES":"NO") << endl;
    }
    return 0;
}