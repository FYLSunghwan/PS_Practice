//BOJ 10952
#include <cstdio>
int main() {
    int a,b;
    while(scanf("%d%d",&a,&b) != EOF) {
        if(a==b && a==0) break;
        printf("%d\n", a + b);
    }
    return 0;
}