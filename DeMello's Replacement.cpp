#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long n, p, m, cs, e;
	long long maxNum = -1e9, minNum = 1e9;
	double temp;
	cin >> n >> p;
	//S = 4sqrt(M) + 3 CS^P - 4E
	string maxName, minName, input;
	for (int i = 0; i < n; i++) {
		cin >> input >> m >> cs >> e;
		temp = 4.0 * sqrt(m) + 3.0 * pow(cs, p) - 4.0 * e;
		temp = floor(temp);
		if (temp > maxNum) {
			maxNum = (long long) temp;
			maxName = input;
		}
		else if (temp < minNum) {
			minNum = (long long)temp;
			minName = input;
		}
	}
	cout << maxName << ' ' << maxNum << endl;
	cout << minName << ' ' << minNum << endl;
 
}