#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main() {
	int n, m, ans = 0;
	cin >> n;
	//vector<vector<int>>a(n + 2, vector<int>(n + 2, 0));
	cin >> m;
 	while (m--) {
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		a[x+1][y+1] += 1;
		a[x + w+1][y + h+1] += 1;
		a[x + w+1][y+1] -= 1;
		a[x+1][y + h+1] -= 1;
	}
	for(int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j++) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i-1][j-1];
			if (a[i][j]%2!=0)
				ans++;
		}
	cout << ans ;
}