//BOJ 2967
#include <cstdio>
char map[102][102];
int u[102][102],d[102][102],l[102][102],r[102][102],R,C,s,t1,t2;

int min(int a, int b) {return a<b?a:b;}
int main() {
    scanf("%d%d",&R,&C);
    for(int i=1;i<=R;i++) scanf("%s",map[i]+1);

    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++) {
            if (map[i][j] != 'x') continue;
            l[i][j]=u[i][j]=1;
            l[i][j]+=l[i][j-1];
            u[i][j]+=u[i-1][j];
        }
    for(int i=R;i>=1;i--)
        for(int j=C;j>=1;j--) {
            if (map[i][j] != 'x') continue;
            r[i][j]=d[i][j]=1;
            r[i][j]+=r[i][j+1];
            d[i][j]+=d[i+1][j];
        }

    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            if(map[i][j] != 'x') continue;
            int bL = l[i][j]-1;
            int bR = r[i][j]-1;
            int bU = u[i][j]-1;
            int bD = d[i][j]-1;
            int s = (bL>0) + (bR>0) + (bU>0) + (bD>0);
            if(s<2) map[i][j]=-1;
            if(s>2) continue;
            if(bR && bD) map[i][j]=-min(bR,bD)-1; //왼쪽 위
            if(bL && bD) map[i][j-min(bL,bD)] = -min(bL,bD)-1; //오른쪽 위
            if(bR && bU) map[i-min(bR,bU)][j]=-min(bR,bU)-1; //왼쪽 아래
            if(bL && bU) map[i-min(bU,bL)][j-min(bU,bL)]=-min(bL,bU)-1; //오른쪽 아래
        }
    }

    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            if(map[i][j]<0) {
                printf("%d %d %d\n",i,j,-map[i][j]);
                ++s;
                t1=i;
                t2=j;
            }
    if(s==1) printf("%d %d 1",t1,t2);


    return 0;
}