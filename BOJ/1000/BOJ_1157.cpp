//BOJ 1157
#include <cstdio>
#include <cstring>
char dan[1000001];
int bindo[100],cnt,mx=-1,mi,len;
int max(int a, int b) {return a>b?a:b;}
int main() {
    scanf("%s",dan);
    len=strlen(dan);
    for(int i=0;i<len;i++) {
        if(dan[i]>='a') bindo[dan[i]-'a']++;
        else bindo[dan[i]-'A']++;
    }
    for(int i=0;i<26;i++) {
        if(bindo[i]>mx) {
            mx=bindo[i];
            mi=i;
            cnt=1;
        }
        else if(bindo[i]==mx) ++cnt;
    }
    if(cnt>1) printf("?");
    else printf("%c",'A'+ mi);
    return 0;
}

