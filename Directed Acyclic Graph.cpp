#include "bits/stdc++.h"
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std;
int n;
vector<int>adj[1005];
bool dfs(int curr, vector<int>vis){//return true if cycle
    vis[curr] = true;
    for(auto i : adj[curr]){
        if(vis[i])
            return true;
        else
            return dfs(i, vis);
    }
    return false;
}
void solve(){
    bool x = 0;
    for(int i = 1; i <=n; i ++){
        vector<int>vis(1005, 0);
        x = x| dfs(i, vis);
    }
    x ? cout << "NO" : cout << "YES";
}
signed main(){
    cin >> n; 
    for(int i = 1; i <=n; i ++){
        for(int j = 1, k; j <=n; j ++){
            cin >> k;
            if(k)
                adj[i].pb(j);
        }
    }
    solve();
}
