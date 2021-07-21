#include "bits/stdc++.h"
using namespace std;
int a[(int)1e5+2], dp[(int)(1e5+2)];
int main(){
    int n;
    cin >> n;

    for(int i = 1, x; i <= n; i ++){
        cin >> x;
        a[i] = x;
    }
    dp[0] = 0;
    dp[1] = a[1];
    int ans = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + a[i]);
    }
    cout << dp[n];
    return 0;
}