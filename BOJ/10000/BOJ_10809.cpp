//BOJ 10809
#include <cstdio>
#include <cstring>
char in;
int pos[100];
int main() {
    memset(pos,-1,sizeof(pos));
    for(int i=0;scanf("%1s",&in) != EOF;i++)
        if(pos[(int)(in-'a')]==-1) pos[(int)(in-'a')] =i;
    for(int i=0;i<'Z'-'A'+1;i++) printf("%d ",pos[i]);
    return 0;
}