#include <iostream>
using namespace std;

long long N, Y, M, c;

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> c;
        Y+=((c/30 + 1)*10);
        M+=((c/60 + 1)*15);
    }
    if(Y==M) cout << "Y M ";
    else cout << (Y<M?"Y ":"M ");
    cout << min(Y,M);
}