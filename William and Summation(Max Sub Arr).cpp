#include<bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	long long n, sum = 0;
	cin >> n;
	vector<long long> a(n, 0);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = a[i] * (n - i);
	}
	for (long long i = 0; i < n; i++) {
		sum += a[i];
	}
	long long max_so_far = a[0], curr_max = a[0];
	for (int i = 1; i < n; i++) {
		curr_max = max(a[i], curr_max + a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	cout << sum - (2 * max_so_far);
}
