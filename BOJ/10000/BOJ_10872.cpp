//BOJ 10872
#include <cstdio>
int n,ans=1;
int main() {
    for(scanf("%d",&n);n;ans*=(n--));
    printf("%d",ans);
    return 0;
}