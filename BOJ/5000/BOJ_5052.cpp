#include <bits/stdc++.h>
using namespace std;

struct Trie{
    bool fin;
    Trie *next[10];

    Trie() : fin(false) {
        memset(next,0,sizeof(next));
    }
    ~Trie() {
        for(int i=0;i<10;i++)
            if(next[i]) delete next[i];
    }
    void insert(const char* key) {
        if(*key == '\0') fin = true;
        else {
            int item = *key - '0';
            if(!next[item]) next[item] = new Trie();
            next[item]->insert(key+1);
        }
    }
    bool find(const char* key) {
        if(*key == '\0') return 0;
        if(fin) return 1;
        int item = *key -'0';
        return next[item]->find(key+1);
    }
};

int main() {
    int T,N;
    scanf("%d",&T);
    while(T--) {
        Trie *trie = new Trie;
        scanf("%d",&N);
        char str[10001][12];
        for(int i=1;i<=N;i++) {
            scanf("%s",str[i]);
            trie->insert(str[i]);
        }
        bool ans=false;
        for(int i=1;i<=N;i++)  {
            if(trie->find(str[i])) ans=true;
        }
        if(ans) printf("NO\n");
        else printf("YES\n");
    }
}