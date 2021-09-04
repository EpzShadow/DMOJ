#include "bits/stdc++.h"
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std;
int t, w, h, dis[52][52], newX, newY;
char arr[52][52];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
pair<int, int> start, washroom;    
void solve(){
    for(int i = 0; i < 52; i++)
        for(int j = 0; j < 52; j++)
            dis[i][j] = 100;
    cin >> w >> h;
    for(int i = 1;i <=h; i ++){
        for(int j = 1; j <=w; j ++){
            cin >> arr[i][j];
            if(arr[i][j] == 'C')
                start = {i,j};
            else if(arr[i][j] == 'W')
                washroom = {i,j};
        }
    }
    // for(int i = 1;i <=h; i++){
    //     for(int j = 1; j<=w; j ++)
    //         cout << dis[i][j] << ' ';
    //     cout << endl;
    // }
    queue<pair<int, int>>q;
    dis[start.f][start.s] = 0;
    q.push(start);
    while(!q.empty()){
        pair<int, int>v = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++){
            newX = v.f + dx[i];
            newY = v.s + dy[i];
            if(newX >=1 && newX <= h && newY >= 1 && newY <=w && dis[newX][newY] == 100 && arr[newX][newY] != 'X'){
                q.push({newX, newY});
                dis[newX][newY] = min(dis[newX][newY], dis[v.f][v.s] + 1);
            }
        }
    }
    // for(int i = 1;i <=h; i++){
    //     for(int j = 1; j<=w; j ++)
    //         cout << dis[i][j] << ' ';
    //     cout << endl;
    // }
    dis[washroom.f][washroom.s] < 60 ? cout << dis[washroom.f][washroom.s] : cout << "#notworth";
    cout << endl; 
}
signed main(){
    cin >> t;
    while(t--)
        solve();
}
