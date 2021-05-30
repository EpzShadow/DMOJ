#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int freq[2];//let freq[0] be the amount of H's and let freq[1] be the amount of V's
	freq[0] = 0;
	freq[1] = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'H') 
			freq[0] ++;
		else
			freq[1]++;
	}
	freq[0] = freq[0] % 2;
	freq[1] = freq[1] % 2;
	int arr[2][2] = { {1,2}, {3,4} };
	
	if (freq[0] == 1) {
		swap(arr[0][0], arr[1][0]);
		swap(arr[0][1], arr[1][1]);
	}
	if (freq[1] == 1) {
		swap(arr[0][0], arr[0][1]);
		swap(arr[1][0], arr[1][1]);
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}