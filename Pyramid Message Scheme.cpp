#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main() {
	int l;
	cin >> l;
	for (int x = 0; x < l; x++) {
		int n;
		cin >> n;
		unordered_map<string, bool>visited;//if visited[string] = true, i've visited this person
		vector<string>inputs(n);
		multimap<string, string>adj;//adjaceny list;
		for (int i = 0; i < n; i++)
			cin >> inputs[i];
		visited[inputs[n - 1]] = 1;
		int temp = 0, depthOfTree = -1;
		for (int i = 0; i < n; i++) {
			if (visited.count(inputs[i]))
				temp--;
			else {
				visited[inputs[i]] = 1;
				temp++;
				depthOfTree = max(depthOfTree, temp);
			}
		}
		cout << 10 * (n - 2 * depthOfTree) << endl;
	}
 }