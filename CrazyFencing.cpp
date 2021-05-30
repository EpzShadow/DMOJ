#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	double sum = 0;
	cin >> n;
	vector <double> h(n + 1);
	vector<double>b(n);
	for (int i = 0; i <= n; i++) {
		cin >> h[i];
	}
	cin;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	for (int i = 0; i < n; i++) {
		double temp = (h[i] + h[i + 1]) * b[i] / 2;
		sum += temp;
	}
	printf("%.1lf", sum);
	return 0;
}