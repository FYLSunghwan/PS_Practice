//BOJ 2920
#include <cstdio>
int main() {
    int k,nex,d,sw=1,sw2;
    scanf("%d%d",&k,&nex);
    d=nex-k;
    sw2=k;
    for(int i=1;i<=6;i++) {
        scanf("%d",&k);
        if(d!=k-nex) sw=0;
        nex=k;
    }
    if(sw) printf("%s",sw2==8?"descending":"ascending");
    else printf("mixed");
    return 0;
}