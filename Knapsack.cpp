#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, W;
	cin >> n >> W;
	vector<long long>dp(W + 1,0);
	for (int i = 0; i < n; i++) {
		int weight, value;
		cin >> weight >> value;

		for (int j = W - weight; j >= 0; j--) {
			dp[weight + j] = max(dp[weight + j], dp[j] + value);
		}
	}
	long long answer = 0;
	for(int i = 0; i <= W; i ++){
		answer = max(answer, dp[i]);
	}
	cout << answer;

	
}