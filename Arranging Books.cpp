#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	int ans = 0;
	cin >> s;
	int count[3] = {};//count[0] = L's, count[1] = M's, count[2] = S's
	int count2[3] = {};//number of wrong elements in each subarr
	int N[3] = {};//number of M's in L and number of L's in M
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'L':
			count[0]++;
			break;
		case 'M':
			count[1]++;
			break;
		case 'S':
			count[2]++;
			break;
		}
	}
	for (int i = 0; i < count[0]; i++) {
		if (s[i] != 'L')
			count2[0] ++;
		if (s[i] == 'M')
			N[0] ++;
	}
	for (int i = count[0]; i < count[0] + count[1]; i++) {
		if (s[i] != 'M')
			count2[1] ++;
		if (s[i] == 'L')
			N[1] ++;
	}
	for (int i = count[0] + count[1]; i < s.size(); i++) {
		if (s[i] != 'L')
			count2[2] ++;
	}
	cout << count2[0] + count2[1] - min(N[0], N[1]);
}