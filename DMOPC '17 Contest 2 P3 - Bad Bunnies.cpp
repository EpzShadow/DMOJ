#include "bits/stdc++.h"
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
const int MM = 2e5+ 5;
vector<int>adj[MM];
int dis[MM], n, r, x, y, minV = 1e9;
bool dfs(int curr, int parent){
    if(curr == y){
        minV = min(minV, dis[y]);
        return true;
    }
    bool flag = false;
    for(auto i : adj[curr]){
        if(i == parent)continue;
        flag |= dfs(i, curr);
    }
    if(flag)minV = min(minV, dis[curr]);
    return flag;
    
}
signed main(){
    cin >> n >> r;
    for(int i = 1; i <=n; i ++)dis[i] = 1e9;
    for(int i = 1, a , b; i < n; i ++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<int> q;
    for(int i = 0; i < r; i ++){
        int a;
        cin >> a;
        q.push(a);
        dis[a] = 0;
                // cout << "bruh";

    }  
    cin >> x >> y;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : adj[v]){
            if(dis[u] == 1e9){
                dis[u] = min(dis[u], dis[v] + 1);
                q.push(u);
            }
        }
    }
    dfs(x, -1);
    cout << minV;
}
