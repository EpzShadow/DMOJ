#include<bits/stdc++.h>
using namespace std;

int main() {

	int n, k, unique = 0;
	long long ans = 0;
	cin >> n >> k;
	vector<int> arr(n, 0);
	vector<int>frequency((int)10e6, 0);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);

	}
	int j = 0; 
	for (int i = 0; i < n; i++) {	
		while (unique < k && j < n) {
			frequency[arr[j]]++;
			if (frequency[arr[j]] == 1) {
				unique++;
			}
			j++;
		}

		if(unique >= k)
			ans += (n - j + 1);

		frequency[arr[i]]--;
		if (frequency[arr[i]] <= 0) {
			unique--;
		}
	}
	printf("%lld\n", ans);
}