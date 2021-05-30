#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>stones(n+1, 0);
	vector<int>dp(n + 1, INT_MAX);
	for (int i = 1; i <= n; i++) {
		cin >> stones[i];
	}
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j : {i + 1, i + 2}) {
			if (j <= n) {
				dp[j] = min(dp[j], dp[i] + abs(stones[i] - stones[j]));
			}
		}
	}
	cout << dp[n];
}