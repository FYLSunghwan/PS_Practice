//BOJ 9012
#include <cstdio>
#include <cstring>
int c;
int main() {
    for(scanf("%d",&c);c;c--) {
        char s[100];
        scanf("%s",s);
        int cnt=0,ans=1;
        for(int i=0;i<strlen(s);i++) {
            if(s[i]=='(') ++cnt;
            if(s[i]==')') --cnt;
            if(cnt<0) {
                ans=0;
                break;
            }
        }
        if(cnt>0) ans=0;
        printf("%s\n",ans?"YES":"NO");
    }
    return 0;
}