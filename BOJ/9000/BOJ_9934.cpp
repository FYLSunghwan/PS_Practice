#include <bits/stdc++.h>
using namespace std;

vector<int> lv[11];

struct BT {
    BT *left, *right;
    int visited, *ar, num;
    static int curr;

    BT(int h, int *inp) : visited(0), ar(inp) {
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        if(h>1) {
            left = new BT(h-1, inp);
            right = new BT(h-1, inp);
        }
    }
    ~BT() {
        if(left) delete left;
        if(right) delete right;
    }
    void search() {
        visited = 1;
        if(left) num = ar[curr++];
        else {
            left->search();
            num = ar[curr++];
            right->search();
        }
    }
};

int BT::curr = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int K,inp[50000];

    cin>>K;
    for(int i=0;i<pow(2,K);i++) cin>>inp[i];
    BT *tree = new BT(K,inp);
    cout<<"SSS";
    tree->search();
    queue<pair<int,BT*>> q;
    q.push({1,tree});
    while(!q.empty()) {
        pair<int,BT*> top = q.front();
        q.pop();
        lv[top.first].push_back(top.second->num);
        if(top.second->left) {
            q.push({top.first+1, top.second->left});
            q.push({top.first+1, top.second->right});
        }
    }
    for(int i=1;i<=K;i++) {
        for(int j=0;j<lv[i].size();j++) {
            cout<<lv[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}