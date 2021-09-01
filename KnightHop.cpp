#include "bits/stdc++.h"
#define pb push_back
// #define int long long
using namespace std;
int a,b,c,d, vis[10][10];
struct node{
    int x,y,d;
};
signed main(){
    cin.tie(0), cin.sync_with_stdio(0), cout.tie(0);
    cin >> a >> b >> c >> d;
    for(int i = 0; i < 10; i ++)for(int j = 0; j < 10; j ++)vis[i][j] = 1e9;
    queue<node>q;
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
    q.push({a,b, 0});
    while(!q.empty()){
        node v = q.front();
        q.pop();
        int x = v.x, y = v.y, d = v.d;
        vis[x][y] = min(vis[x][y], d);
        for(int i = 0; i < 8; i++){
            int newX = x+dx[i], newY = y + dy[i], newD = d + 1;
            if(newX >= 1 && newX <=8 && newY >= 1 && newY <= 8 && vis[newX][newY] == 1e9){
                q.push({newX, newY, newD});
            }
        }
    }
    cout << vis[c][d];
}                                                   