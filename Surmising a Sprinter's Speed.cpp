#include <bits/stdc++.h>
using namespace std;
bool compare(pair<double, double> a, pair<double, double> b) {
	return (b.first > a.first);
}
int main() {
	int N;
	double ans = 0;
	cin >> N;
	vector<pair<double, double>>times(N);
	for (int i = 0; i < N; i++) {
		cin >> times[i].first >> times[i].second;
	}
	sort(times.begin(), times.end(), compare);
	for (int i = 0; i < N-1; i++) {
		double dis = abs(times[i + 1].second - times[i].second);
		double t = abs(times[i + 1].first - times[i].first);
		ans = max(ans, (dis/t));
	}
	cout << fixed << setprecision(5) << ans;
}