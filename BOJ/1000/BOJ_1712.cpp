#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll A, B, V;
    cin >> A >> B >> V;
    cout << (V-B-1)/(A-B)+1LL;
}