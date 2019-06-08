//BOJ 2490
#include <iostream>
using namespace std;
int main() {
    for(int i=0;i<3;i++) {
        int k,sum=0;
        for(int j=0;j<4;j++) {
            cin>>k;
            sum+=k;
        }
        cout<<"DCBAE"[sum]<<endl;
    }
    return 0;
}