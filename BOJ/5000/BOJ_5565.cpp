//BOJ 5565
#include <cstdio>
int tot,in,i=9;
int main() {
    for(scanf("%d",&tot);i;i--) {
        scanf("%d",&in);
        tot-=in;
    }
    printf("%d",tot);
    return 0;
}