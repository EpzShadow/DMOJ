#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int i = (n - 1) / 2;
	int j = i + 1;
	for (int k = 0; k < n; k++) {
		if (k % 2 == 0) {
			cout << a[i] << ' ';
			i--;
		}
		else {
			cout << a[j] << ' ';
			j++;
		}
	}
}