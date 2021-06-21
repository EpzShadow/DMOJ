#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int>a;
vector<int>prefixSum;
bool check(int mid) {
	int numOfSubArr = 1, j = 1;
	for (int i = 1; i <= n; i++) {
		if (prefixSum[i] - prefixSum[j - 1] > mid) {
			j = i;
			numOfSubArr++;
		}
	}
	return(numOfSubArr <= m);
}
signed main() {
	int k, sum = 0;
	cin >> n >> m;
	a.resize(n + 1, 0);
	prefixSum.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		prefixSum[i] = a[i] + prefixSum[i - 1];
	}
	int l = *max_element(a.begin(), a.end()), r = prefixSum[n];//makes sure my min sum is always greater than the elements
	while (l < r) {
		int mid = (l + r) >> 1; // ">> 1" moves bit to the right by one, basically divide by 2 but faster
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l;
}