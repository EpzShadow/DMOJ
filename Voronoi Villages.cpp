#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	double ans = INT_MAX;
	cin >> n;
	vector<double>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < n - 1; i++) {
		ans = min(((a[i] - a[i - 1]) / 2 + (a[i + 1] - a[i]) / 2),ans);
	}
	printf("%.1f", ans);
}