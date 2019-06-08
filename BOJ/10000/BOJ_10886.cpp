//BOJ 10886
#include <cstdio>
int main() {
    int n,c,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&c);
        sum+=c;
    }
    printf("Junhee is%scute!",2*sum>=n?" ":" not ");
    return 0;
}