#include <bits/stdc++.h>;
using namespace std;
int main() {
	int n, temp;
	cin >> n;
	vector<int> balls(n);
	bool dp[400][400];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		balls[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j >= i; j--) {
			if (i == j)
				dp[i][j] = true;
			else if (j - i <= 2 && balls[i] == balls[j])
				dp[i][j] == true;
			else if ((j - i) > 2) {
				for(int a = 0; a<)
			}

				
			
		}
	}

}
