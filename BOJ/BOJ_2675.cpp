//BOJ 2675
#include <stdio.h>
#include <string.h>

char text[21];
int t,k,n;
int main() {
    for(scanf("%d",&t);t;t--) {
        scanf("%d%s",&n,text);
        for(int i=0;i<strlen(text);i++) for(int j=0;j<n;j++)printf("%c",text[i]);
        printf("\n");
    }
    return 0;
}