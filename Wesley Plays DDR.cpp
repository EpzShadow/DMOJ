#include <bits/stdc++.h>
using namespace std;
bool compare(pair<string, int> p, pair<string,int>p2) {
	return(p.first.size() > p2.first.size());
}
int main() {
	int m, comboValue, ans = 0;
	string s, comboString;
	cin >> s >> m;
	vector<pair<string, int>>combos(m);
	for (int i = 0; i < m; i++) {
		cin >> comboString >> comboValue;
		combos[i] = make_pair(comboString, comboValue);
	}
	sort(combos.begin(), combos.end(), compare);
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < m; j++) {
			int sizeCombo = combos[j].first.size();
			if (i + sizeCombo <= s.size() && s.substr(i, sizeCombo) == combos[j].first) {
				i = i + sizeCombo - 1;
				ans += combos[j].second;
				//cout << combos[j].first << endl;
				break;
			}
		}
	}
	ans += s.size();
	cout << ans;
}