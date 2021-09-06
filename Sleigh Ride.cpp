#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
const int MM = 1e5 +5;
int mx = -1e9, total;
vector<pair<int, int>> adj[MM];//adj[i] = {j,w}
int n, cnt;
void dfs(int curr, int parent, int weight){
    if(adj[curr].size() == 1 && curr ^ 0){
        mx = max(mx, weight);
        cnt++;
        return;
    }
    for(auto i : adj[curr]){
        if(i.f == parent)continue;
        dfs(i.f, curr, weight + i.s);
    }
}
int main(){
    cin >> n;
    for(int i = 0, a, b, c; i < n; i++){
        cin >> a >> b >> c;
        adj[a].pb({b,c});
        adj[b].pb({a,b});
        total += 2*c;
    }
    // for(int i = 0; i <=n; i ++){
    //     cout << endl;
    //     for(auto j : adj[i])cout << j.f;
    // }
    dfs(0, -1, 0);
    // if(cnt==1)cout << total/2;
    // else
    cout << total - mx;
}
