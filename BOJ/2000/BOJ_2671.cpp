#include <bits/stdc++.h>
using namespace std;
string inp;
int main() {
    cin >> inp;
    cout << (regex_match(inp,regex("(100+1+|01)+"))?"SUBMARINE":"NOISE");
    return 0;
}