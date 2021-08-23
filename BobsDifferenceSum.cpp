#include "bits/stdc++.h"
#define pb push_back
using namespace std;
#define int long long
signed main(){
    int n, ans = 0;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i <n; i ++)cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 0; i < n; i ++){
        ans += arr[i] * (n-i-1);
        ans -= arr[i] * i;
    }
    cout << ans;

}