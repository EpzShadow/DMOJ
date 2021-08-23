#include "bits/stdc++.h"
#define pb push_back
using namespace std;
#define int long long
int arr[105][105];
signed main(){
    int n, m, mx = -1e9, ans = 0;
    cin >> n >> m;
    for(int i = 1; i <=n; i ++)for(int j = 1; j <=m; j ++){cin >>arr[i][j], mx = max(mx, arr[i][j]);},
    for(int i = 1; i <=n; i ++)for(int j =1 ; j <=m; j++)ans += mx-arr[i][j];
    cout << ans;
}