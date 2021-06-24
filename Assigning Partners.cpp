#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string>line1(n);
	vector<string>line2(n);
	for (int i = 0; i < n; i++) {
		cin >> line1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> line2[i];
	}
	
	for (int i = 0; i < n; i++) {
		vector<string>temp = { line1[i], line2[i] };
		if (temp[0] == temp[1]) {
			cout << "bad";
			return 0;
		}
		sort(temp.begin(), temp.end());
		for (int j = 0; j < n; j++) {
			if (j != i) {
				vector<string>temp2 = { line1[j], line2[j] };
				sort(temp2.begin(), temp2.end());

				if (temp[0] == temp2[0] && temp[1] != temp2[1]) {
					cout << "bad";
					return 0;
				}
			}
		}
	}
	cout << "good";
}