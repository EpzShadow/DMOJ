#include "bits/stdc++.h"
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std;
vector<int>adj[105];
int dis[105], ants[105], n, m;
queue<int>q;
signed main(){
    for(int i = 0; i < 105; i ++)dis[i] = 1e9, ants[i] = 1e9;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }    
    cin >> m;
    while(m--){
        int a; cin >> a;
        q.push(a);
        ants[a] = 0;
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i : adj[v]){
            if(ants[i] == 1e9){
                ants[i] = min(ants[i], ants[v] + 4);
                q.push(i);
            }
        }
    }
    q.push(1);
    dis[1] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i : adj[v]){
            if(dis[i] == 1e9 && ants[i] > dis[v]){
                dis[i] = min(dis[i], dis[v] + 1);
                q.push(i);
            }
        }
    }
    // for(int i = 0; i <= n; i ++)cout << ants[i] << ' ';
    // cout << endl;
    // for(int i = 0; i <=n; i ++)cout << dis[i] << ' ';
    // cout << endl;
    dis[n] == 1e9 ? cout << "sacrifice bobhob314" << endl : cout << dis[n] << endl;
}
