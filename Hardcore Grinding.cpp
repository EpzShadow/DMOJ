#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int size = 1e7 + 1;
	vector<int>a(size,0);
	while (n--) {
		int x, y;
		cin >> x >> y;
		a[x]++;
		a[y]--;
	}
	int ans = 0;
	for (int i = 1; i < a.size(); i++) {
		a[i] += a[i - 1];
		ans = max(ans, a[i]);
	}
	cout << ans;
}