//BOJ 2960
#include <cstdio>
int era[1001],k,cnt,n;
int main() {
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++) {
        for(int j=i;j<=n;j+=i) {
            if(era[j]) continue;
            era[j]=1;
            cnt++;
            if(cnt==k) {
                printf("%d",j);
                return 0;
            }
        }
    }
    return 0;
}