#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> dp(3);
	for (int days = 0; days < n; days++) {
		vector<int> M(3, 0);
		vector<int> a(3);
		for (int i = 0; i < 3; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != j) {
					M[i] = max(M[i], dp[j] + a[i]);
				}
			}
		}
		dp = M;
	}
	cout << *max_element(dp.begin(), dp.end());
}