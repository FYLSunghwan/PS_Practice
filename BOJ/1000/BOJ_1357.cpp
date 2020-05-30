#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    int ans = 0;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    ans = stoi(a) + stoi(b);
    a = to_string(ans);
    reverse(a.begin(), a.end());
    cout << stoi(a);
    return 0;
}
