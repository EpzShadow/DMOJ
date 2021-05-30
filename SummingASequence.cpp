#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ll n, ans = 0;
	cin >> n;
	vector<ll>arr(n, 0);
	vector<ll>dp(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (arr[0] < 0)
		dp[0] = 0;
	else
		dp[0] = arr[0];
	//dp[0] = max(0LL, arr[0]);
	dp[1] = max(arr[1], dp[0]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
	}
	cout << dp[n-1];
}