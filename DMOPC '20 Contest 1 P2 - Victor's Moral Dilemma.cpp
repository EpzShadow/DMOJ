#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
const int MM = 5e5+ 5;
vector<int>adj[MM];
int vis[MM], maxNode = -1, maxDis = -1, dis[MM], dis2[MM];
int leftNode, rightNode;
void dfs(int curr, int dis){
    vis[curr] = 1;
    if(dis > maxDis){
        maxNode = curr;
        maxDis = dis;
    }
    for(int i : adj[curr]){
        if(!vis[i]){
            dfs(i, dis+1);
        }
    }
}
signed main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i ++)dis[i] = 1e9, dis2[i] = 1e9;
    for(int i = 1, a, b; i < n; i ++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 1);
    memset(vis, 0, sizeof(vis));
    leftNode = maxNode;
    maxDis = -1;
    dfs(maxNode, 0);
    rightNode = maxNode;

    // cout << leftNode << ' ' << rightNode;
    queue<int> q;
    q.push(leftNode);
    dis[leftNode] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i : adj[v]){
            if(dis[i] == 1e9){   
                dis[i] = dis[v] + 1;
                q.push(i);
            }
        }
    }
    q.push(rightNode);
    dis2[rightNode] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i : adj[v]){
            if(dis2[i] == 1e9){
                dis2[i] = dis2[v] + 1;
                q.push(i);
            }
        }
    }
    for(int i = 1; i <= n; i++)cout << max(dis[i], dis2[i]) << endl;
}
