#include "bits/stdc++.h"
#define int long long
using namespace std;
const int MM = 2e5+5;
int arr[MM], ans = -1e9;
void solve(){
    deque<pair<int, int>>dq;//pair<value, pos>
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)
        cin >> arr[i], arr[i+n] = arr[i];
    for(int i = 1; i <= 2*n; i ++)
        arr[i] += arr[i-1];
    // for(int i = 1; i <= 2*n; i ++)
    //     cout << arr[i] << ' ';
//    this montonic deque finds the minium in the window of k, within idx i
    dq.push_back({(int) 0, (int) 0});
    for(int i = 1; i <= 2*n; i ++){
        while(!dq.empty() && dq.front().second < i-k)dq.pop_front();
        while(!dq.empty() && dq.back().first > arr[i])dq.pop_back();
        dq.push_back({arr[i], i});
        ans = max(ans, arr[i]-dq.front().first);
    }
    cout << ans << endl;
}
signed main(){ 
    cin.tie(0);
    cin.sync_with_stdio(0);
    solve();
}