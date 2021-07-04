#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, q;
	cin >> n >> q;
	vector<double>distances(n + 1, 0);
	vector<long long>sorted(n+1);
	for (int i = 1; i <= n; i++){
		long long x, y;
		cin >> x >> y;
		distances[i] = sqrt(x * x + y * y);
	}
	sort(distances.begin(), distances.end());
	for (long long i = 0; i < q; i++) {
		long long x, ans;
		cin >> x;
		int l = 0, r = n;
		vector<double>::iterator up; 
		up = upper_bound(distances.begin(), distances.end(), x);
		for (long long j = n; j >= 0; j--) {
			if (distances[j] <= x) {
				ans = j;
				break;
			}
		}
		cout << up - distances.begin() - 1 << endl;
	}
}