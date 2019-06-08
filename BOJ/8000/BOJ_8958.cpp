//BOJ 8958
#include <cstdio>
#include <cstring>
int c;
int main() {
    for(scanf("%d",&c);c;c--) {
        char s[100];
        int cnt=0,score=0;
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++) {
            if(s[i]=='O') {
                cnt+=1;
                score+=cnt;
            }
            else cnt=0;
        }
        printf("%d\n",score);
    }
    return 0;
}