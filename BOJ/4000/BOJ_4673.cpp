//BOJ 4673
#include <cstdio>
int self[10001];
int main() {
    for(int i=1;i<=10000;i++) {
        if(self[i]) continue;
        int k=i;
        while(k<=10000) {
            int t=k;
            while(t){
                k+=(t%10);
                t/=10;
            }
            if(k<=10000) self[k]=1;
        }
    }
    for(int i=1;i<=10000;i++) {
        if(!self[i]) printf("%d\n",i);
    }
}