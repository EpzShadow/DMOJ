#include <bits/stdc++.h>
using namespace std;
int main() {	
	int T;
	cin >> T;

	for (int x = 0; x < T; x++) {
		long long arr[3], sum = 0, N;
		cin >> N;
		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		vector<long long>taken(3, 0);
		if (sum < N) {
			cout << -1 << endl;
			continue;
		}
		if(sum >= N) {	
			vector <long long> taken(3, 0);
			for (int i = 2; i >= 0; i--) {
				if (arr[i] <= N) {
					taken[i] = arr[i];
					N = N - taken[i];
				}
				else {
					taken[i] = N;
					N = 0;
				}
			}
			for (long long i : taken)
				cout << i << " ";
			cout << endl;
		}
	}
}