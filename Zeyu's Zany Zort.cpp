#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int a, b, c;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			sort(arr.begin() + b - 1, arr.begin() + c);
		}
		if (a == 2) {
			sort(arr.begin() + b - 1, arr.begin() + c, greater<int>());
		}
	}
	for (int i = 0; i < n; i++) {
		if (i < (n - 1))
			cout << arr[i] << ' ';
		else
			cout << arr[i] << endl;
	}
}