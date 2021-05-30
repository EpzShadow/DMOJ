#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n;
	cin >> k;
	vector<int>h(n);
	vector<int>dp(n, INT_MAX);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j <=i + k; j++) {
			if (j < n) {
				dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
			}
		}
	}
	cout << dp[n - 1];

}