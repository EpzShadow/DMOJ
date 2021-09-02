#include "bits/stdc++.h"
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std;
const int MM = 1e6+5;
vector<int> adj[MM], revAdj[MM];
int n, m, a, b, p, q;
bool bfs(vector<int>a[MM], int start, int end){
    int vis[MM];
    memset(vis, 0, sizeof(vis));
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i : a[v]){
            if(!vis[i]){
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return vis[end];
}
signed main(){
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        adj[a].pb(b);
        revAdj[b].pb(a);
    }
    cin >> p >> q;
    bool x = bfs(adj, p,q), y = bfs(revAdj, p, q);
    if(x)cout << "yes";
    else if(y) cout << "no";
    else cout << "unknown";
}
