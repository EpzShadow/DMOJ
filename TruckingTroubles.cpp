#include "bits/stdc++.h"
using namespace std;
struct edge{
    int a,b,w;
};
int parent[10005], visited[100005], ans[10005];
vector<edge>edges;
vector<pair<int, int>>adj[100005];
int n, r, d;
int find(int x){
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b)
    parent[b] = a;
}  
bool comp(edge a, edge b){
    return a.w > b.w;
}
void dfs(int v){
    visited[v] = true;
    for(pair<int, int> p : adj[v]){
        if(visited[p.first])continue;
        ans[p.first] = min(ans[v], p.second);
        dfs(p.first);
    }

}
int main(){
    cin >> n >> r >> d;
    for(int i = 0; i < r; i ++){
        int x,y,w;
        cin >> x >> y >> w;
        edges.push_back({x,y,w});
    }
    for(int i = 1; i<=n; i ++)
    parent[i] = i;
    sort(edges.begin(), edges.end(), comp);
    for(edge e : edges){
        if(find(e.a) != find(e.b)){
            unite(e.a,e.b);
            adj[e.a].push_back({e.b, e.w});
            adj[e.b].push_back({e.a, e.w});
        }
    }
    ans[1] = 1e9;
    dfs(1);
    int cnt = 1e9;
    for(int i = 1; i <=d; i ++){
        int m; cin >> m;
        cnt = min(cnt, ans[m]);
    }
    cout << cnt << endl;
}