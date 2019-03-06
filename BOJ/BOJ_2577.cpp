#include <iostream>
using namespace std;

int a,b,c,res[10];

void cal(int r) {
    if(r==0) return;
    res[r%10]++;
    cal(r/10);
}

int main() {
    cin>>a>>b>>c;
    cal(a*b*c);
    for(int i=0;i<10;i++) cout<<res[i]<<endl;
    return 0;
}