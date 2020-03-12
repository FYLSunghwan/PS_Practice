#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll lhs, rhs, res;
    cin >> lhs >> rhs;
    cout << lhs * (rhs%10LL) << endl;
    cout << lhs * (rhs/10LL%10LL) << endl;
    cout << lhs * (rhs/100LL) << endl;
    cout << lhs * rhs;
    return 0;
}