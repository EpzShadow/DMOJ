#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    long long n, sum = 0;
    cin >> n;
    vector<pair<long long, long long>>arr(n);
    vector<long long>dp(5001, 1e18);
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        sum += y;
        arr[i] = make_pair(x, y);
    }
    dp[0] = 0;
    //dp[i] is min voters for i points
    for (int j = 0; j < n; j++) {
        for (int i = sum - arr[j].second; i>= 0; i--) {
            long long c = arr[j].first / 2 + 1;
            dp[i + arr[j].second] = min(dp[i] + c, dp[i + arr[j].second]);
        }
    }
    long long x = sum / 2 + 1;
    long long ans = 1e18;
    //cout << dp[x];
    for (int i = 0; i <= sum; i++) {
        if (i > sum - i)
            ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
    //cout << dp[sum / 2 + 1] << endl;
}
