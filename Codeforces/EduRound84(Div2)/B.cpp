#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n, tmp;
ll vis[100001]={0};
ll married[100001]={0};
vector<ll> ls[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1;i<=n;i++) {
            vis[i]=0;
            married[i]=0;
            ls[i].clear();
            cin >> tmp;
            for(int j=1;j<=tmp;j++) {
                ll kk;
                cin >> kk;
                ls[i].push_back(kk);
            }
        }
        ll pc=0, kd=0;
        for(int i=1;i<=n;i++) {
            bool sw=false;
            for(auto& j:ls[i]) {
                if(!vis[j]) {
                    married[i]=1;
                    vis[j]=1;
                    sw=true;
                    break;
                }
            }
            if(!sw) pc=i;
        }
        for(int i=1;i<=n;i++) {
            if(!vis[i]) kd = i;
        }
        if(pc && kd) cout << "IMPROVE\n" << pc << " " << kd << "\n";
        else cout << "OPTIMAL\n";
    }
}