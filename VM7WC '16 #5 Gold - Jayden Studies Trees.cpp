#include "bits/stdc++.h"
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
const int MM = 1e4 + 5;
int n, ans, vis[MM], maxD = -1, maxNode = -1;
vector<int> adj[MM];
void dfs(int curr, int dis){
    vis[curr] = -1;
    if(dis > maxD){
        maxNode = curr;
        maxD = dis;
    }
    for(auto x : adj[curr]){
        if(!vis[x])
            dfs(x, dis+1);
    }
}
signed main(){
    cin >> n;

    for(int i = 1, a ,b; i < n; i++){
        cin >> a >> b;
        adj[b].pb(a);
        adj[a].pb(b);
    }
    dfs(1, 1);
    memset(vis, 0, sizeof(vis));
    maxD = -1;
    dfs(maxNode, 1);
    cout << maxD-1;
}

