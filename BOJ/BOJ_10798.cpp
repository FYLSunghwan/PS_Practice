//BOJ 10798
#include <cstdio>
#include <string.h>
#include <algorithm>

char c[6][16];
int len=-999;

int main() {
    for(int i=0;i<5;i++) {
        scanf("%s",c[i]);
        len= std::max(len,(int)strlen(c[i]));
    }
    for(int i=0;i<len;i++) {
        for(int j=0;j<5;j++) {
            if(c[j][i]!='\0') printf("%c",c[j][i]);
        }
    }
    return 0;
}