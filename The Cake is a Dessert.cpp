#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<long long>>a(n + 2, vector<long long>(m + 2, 0));
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[x2 + 1][y2 + 1] += 1;
		a[x2 + 1][y1] -= 1;
		a[x1][y2 + 1] -= 1;
		a[x1][y1] += 1;
	}
	int x = 2;
	while (x--)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

	int q;
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		long long ans = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
		cout << ans << endl;
	}

}