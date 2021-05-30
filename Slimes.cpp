#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, x;
	cin >> n;
	unsigned long long dp [401][401];
	vector<int>slimes(n);
	//dp[i][j] is the minium cost from subarray i to j
	for (int i = 0; i < n; i++) {
		cin >> x;
		slimes[i] = x;
		dp[i][i] = slimes[i]; 
	}




	

}