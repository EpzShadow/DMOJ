#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
const int MM = 2e7 + 5;
char arr[105][105];
int r, c;
int vis[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y){
    // cout << x << ' ' << y << endl;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int newX = x + dx[i], newY = y + dy[i];
        if(newX >= 1 && newY >= 1 && newX <= r && newY <= c && !vis[newX][newY] && arr[newX][newY] != 'X')
            dfs(newX, newY);
    }
}
void solve(){
    int cnt = 0;
    cin >> r >> c;
    for(int i = 1; i <= r; i++)for(int j =1 ; j <=c;j++)cin >> arr[i][j];
    
    for(int i =1 ; i <=r; i++)
        for(int j = 1; j <=c; j++)
            if(!vis[i][j] && arr[i][j] != 'X')dfs(i,j), cnt++;

    cout << cnt;

}
int main(){
    solve();
}
