#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
int n, m, adj[105][105], vis[105], cnt;
queue<int> q;
void bfs(){
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(adj[v][i] == 1 && vis[i] == 0)
                q.push(i), vis[i] = 1;
        }
    }
}
void solve(){
    pair<int, int>edges[1005];
    n = 0, m = 0, cnt = 0;
    for(int i = 0; i < 105; i++)for(int j = 0; j < 105; j++)adj[i][j] = 0, vis[i] = 0;
    cin >> n >> m;
    for(int i = 1; i <=n; i++)adj[i][i] = 1;
    for(int i = 0, a, b; i < m; i ++){
        cin >> a >> b;
        edges[i] = {a,b};
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for(int i = 0, a, b; i < m; i ++){
        bool flg = 0;
        memset(vis, 0, sizeof(vis));
        a = edges[i].f;
        b = edges[i].s;
        adj[a][b] = 0;
        adj[b][a] = 0;
        bfs();
        for(int j = 1; j <=n; j++)if(vis[j] == 0)flg = 1;
        adj[a][b] = 1;
        adj[b][a] = 1;
        if(flg)cnt ++;
    }
    cout << cnt << endl;
}
int main(){
    int x = 5;
    while(x--)solve();
}
