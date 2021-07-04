#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n, k, sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		sum += (a * b)%k;
	}
	cout << sum % k;
}