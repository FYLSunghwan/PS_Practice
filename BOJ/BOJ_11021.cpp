//BOJ 11021
#include <cstdio>
int c;
int main() {
    scanf("%d",&c);
    for(int i=1;i<=c;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case #%d: %d\n",i,a+b);
    }
    return 0;
}