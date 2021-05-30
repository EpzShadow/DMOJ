#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, W, maxValue = 0;
	cin >> n >> W;
	vector<int> weights(n);
	vector<int>values(n);
	vector<long long>dp(1000 * n + 1, INT_MAX);
	//index is the value, content is min weight needed to acheive said value
	
	for (int i = 0; i < n; i++) {
		cin >> weights[i] >> values[i];
		maxValue += values[i];
	}


	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = maxValue - values[i]; j >=0; j--) {
			dp[j + values[i]] = min(dp[values[i] + j], weights[i] + dp[j]);
		}
	}
	long long output = 0;
	for (int i = 0; i <= maxValue; i++) {
		if (dp[i] <= W) {
			output = max(output, (long long) i);
		}
	}
	cout << output;
}