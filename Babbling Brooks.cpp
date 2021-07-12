#include<bits/stdc++.h>
using namespace std;
vector<int>a(105, 0);
int main() {
	stack<int>s;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	
	int in = -1;
	while (in != 77) {
		cin >> in;
		if (in == 99) {
			float stream, percent;
			cin >> stream >> percent;
			float leftStream = (float)a[stream];
			leftStream = percent / 100.0 * leftStream;//50/100*10 = 5
			leftStream = round(leftStream);
			int rightStream = a[stream] - leftStream;
			a[stream] = leftStream;
			a.insert(a.begin() + stream + 1, rightStream);
			n++;
		}
		else if (in == 88) {
			int stream;
			cin >> stream;
			a[stream] += a[stream + 1];
			a.erase(a.begin() + stream + 1);
			n--;
		}

		}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
}