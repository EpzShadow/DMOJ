#include<bits/stdc++.h>
using namespace std;
int main() {
	int M, N, K, sum = 0;
	cin >> M >> N >> K;
	//let 0 be black, let 1 be gold
	vector<vector<int>>arr(M, vector<int>(N, 0));
	vector<int>rowF(M,0);
	vector<int>colF(N, 0);
	for (int i = 0; i < K; i++) {
		char temp;
		int num;
		cin >> temp >> num;
		if (temp == 'R') {
			rowF[num - 1]++;
		}
		else
			colF[num - 1]++;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			sum += (rowF[i] + colF[j]) % 2;
		}
	}
	cout << sum;

}