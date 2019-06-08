//BOJ 1002
#include <cstdio>
int x1,y1,r1,x2,y2,r2,t;
int check(int r,int rp, int d) {
    if(d>(r+rp)*(r+rp)) return 0;
    if(d==(r+rp)*(r+rp)) return 1;
    if(d>(r-rp)*(r-rp)) return 2;
    if(d==(r-rp)*(r-rp)) return 1;
    return 0;
}
int main() {
    for(scanf("%d",&t);t;t--) {
        scanf("%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2);
        int r=(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        if(x1==x2 && y1==y2 && r1==r2) printf("-1\n");
        else printf("%d\n",check(r1,r2,r));
    }
    return 0;
}