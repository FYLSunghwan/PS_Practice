//BOJ 10953
#include <cstdio>
int c;
int main() {
    for(scanf("%d",&c);c;c--) {
        int a,b;
        scanf("%1d,%1d",&a,&b);
        printf("%d\n",a+b);
    }
    return 0;
}