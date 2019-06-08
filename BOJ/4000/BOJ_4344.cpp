//BOJ 4344
#include <cstdio>
int main() {
    int c;
    for(scanf("%d",&c);c;c--) {
        int n;
        float sum=0,cnt=0,in[1001];
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%f",&in[i]);
            sum+=in[i];
        }
        sum/=(float)n;
        for(int i=0;i<n;i++) if(in[i]>sum) cnt+=1;
        printf("%.3f%%\n",cnt/n*100);
    }
}