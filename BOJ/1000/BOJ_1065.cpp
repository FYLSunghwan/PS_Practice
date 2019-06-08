//BOJ 1065
#include <cstdio>
#include <cmath>
int n;

int isHansu(int k) {
    if(k<100) return 1;
    int back=k%10;
    k/=10;
    int d=k%10-back;
    back=k%10;
    k/=10;
    while(k) {
        if(k%10-back != d) return 0;
        back=k%10;
        k/=10;
    }
    return 1;
}

int main() {
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++) ans+=isHansu(i);
    printf("%d",ans);
    return 0;
}