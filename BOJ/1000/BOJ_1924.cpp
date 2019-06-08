#include <cstdio>
int main() {
    int m,d;
    scanf("%d %d",&m,&d);
    printf("%.3s","MONTUEWEDTHUFRISATSUN"+(("0033614625035"[m]+d)%7)*3);
    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

string yoil[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},m,d;
int main() {
    for(int i=1;i<=12;i++) {
        day[i]=day[i-1];
        if(i==2) day[i]+=28;
        else if(i%2) day[i]+=(i<8?31:30);
        else day[i]+=(i<8?30:31);
    }
    cin>>m>>d;
    cout<<yoil[(day[m-1]+d)%7];
    return 0;
}
 */