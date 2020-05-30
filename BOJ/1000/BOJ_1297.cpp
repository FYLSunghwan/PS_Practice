#include <bits/stdc++.h>
using namespace std;
double inch, hr, wr;
int h,w;
int main() {
    cin >> inch >> hr >> wr;
    h = (int)floor(sqrt(inch*inch * (hr*hr)/(hr*hr+wr*wr)));
    w = (int)floor(sqrt(inch*inch * (wr*wr)/(hr*hr+wr*wr)));
    cout << h << " " << w;
}