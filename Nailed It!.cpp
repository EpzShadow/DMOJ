#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; 
	cin >> n;
	vector<int>woodLengths(2001, 0);
	vector<int>sums(4002, 0);//sums is length of a board at a certain height
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		woodLengths[x]++;
	}
	for (int i = 1; i <= 2000; i++) {
		if (woodLengths[i] > 0) {
			for (int j = i; j <= 2000; j++) {
				if (i == j) {
					sums[i + i] += woodLengths[i] / 2;
				}
				else if (woodLengths[j] > 0) {
					sums[i + j] += min(woodLengths[i], woodLengths[j]);
				}
			}
		}
	}
	int maxLengths = INT_MIN, numOfTimes = 0;
	for (int i : sums) {
		maxLengths = max(maxLengths, i);
	}
	for (int i = 2; i <= 4000; i++) {
		if (sums[i] == maxLengths)
			numOfTimes++;
	}
	cout << maxLengths << ' ' << numOfTimes;
}