//BOJ 10797
#include <cstdio>
int n,t,cnt,i=5;
int main() {
    for(scanf("%d",&t);i;i--) {
        scanf("%d",&n);
        cnt+=(n==t);
    }
    printf("%d",cnt);
    return 0;
}