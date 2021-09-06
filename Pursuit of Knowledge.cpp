#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
int n, m, t, arr[1005][1005], queries;
vector<int>adj [1005];
queue<int>q;
void bfs(int start){
    q.push(start);
    arr[start][start] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i : adj[v]){
            if(arr[start][i] == 1e9){
                arr[start][i] = arr[start][v]+1;
                q.push(i);
            }
        }
    }
}
signed main(){
    cin >> n >> m >> t;
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for(int i = 1; i <=n; i++)for(int j = 1; j<=n; j ++)arr[i][j] = 1e9;
    for(int i = 1; i <=n; i++)bfs(i);
    cin >> queries;
    while(queries--){
        int a, b;
        cin >> a >> b;
        if(arr[a][b] == 1e9)cout << "Not enough hallways!" << endl;
        else
        cout << arr[a][b] * t << endl;
    }

}
