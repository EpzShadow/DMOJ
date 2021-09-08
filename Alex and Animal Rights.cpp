#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
const int MM = 2e7 + 5;
char arr[50][50];
int r, c;
int vis[50][50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool dfs(int currX, int currY){
    bool flg = 0;
    if(arr[currX][currY] == 'M')
        flg|=1;
    vis[currX][currY] = 1;
    for(int i = 0; i < 4; i++){
        int x = currX + dx[i];
        int y = currY + dy[i];
        if(x <= r && y <= c && x >=1 && y >= 1 && arr[x][y] != '#' && !vis[x][y])
            flg |= dfs(x,y);
    }
    return flg;
}
void solve(){
    int cnt = 0;
    cin >> r >> c;
    for(int i = 1; i <= r; i++)for(int j =1 ; j <=c;j++)cin >> arr[i][j];
    
    for(int i =1 ;i <=r; i++)
        for(int j =1 ; j <=c; j++)
            if(!vis[i][j] && arr[i][j] != '#'){
                if(dfs(i, j))
                    cnt++;
            }
    cout << cnt;

}
int main(){
    solve();
}Alex and Animal Rights
