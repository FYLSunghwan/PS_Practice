//BOJ 1463_2019.3.5
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,D[1000000];


int main() {
    cin >> n;
    for(int i=2;i<=n;i++) {
        D[i]=min({i%3==0?D[i/3]:987654321,i%2==0?D[i/2]:987654321,D[i-1]})+1;
    }
    printf("%d",D[n]);
    return 0;
}

//Bottom-Up만 가능
