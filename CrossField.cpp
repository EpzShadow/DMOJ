#include "bits/stdc++.h"
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std;
int n, h, vis[1600][1600], arr[1600][1600];
struct node{
    int x, y;
};
signed main(){
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    cin >> n >> h;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j <=n; j++)
            cin >> arr[i][j];
    queue<node>q;
    q.push({1,1});
    while(!q.empty()){
        node v = q.front();
        q.pop();
        // vis[v.x][v.y] = 1;
        if(v.x == n && v.y == n)break;

        for(int i = 0; i < 4; i ++){
            int x = v.x + dx[i], y = v.y + dy[i];
            if(x >=1 && x <=n && y >=1 && y <= n && !vis[x][y] && abs(arr[v.x][v.y] - arr[x][y]) <= h)
                q.push({x,y}), vis[x][y] = 1;
        }
    }
    vis[n][n] ? cout << "yes" : cout << "no";    
}